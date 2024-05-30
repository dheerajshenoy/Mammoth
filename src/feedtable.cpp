#ifndef FEEDTABLE_CPP
#define FEEDTABLE_CPP

#include "feedtable.hpp"

FeedTable::FeedTable(QWidget *parent)
:QTableWidget(parent)
{

    QStringList Headers = { "Date", "Title"};

    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->horizontalHeader()->setStretchLastSection(true);
    this->setColumnCount(Headers.size());
    this->horizontalHeader()->setSectionsClickable(false);
    this->setHorizontalHeaderLabels(Headers);

    // Set the current cursor position to the clicked position
    connect(this, &QTableWidget::cellClicked, this, [=](int row) {
        m_cur_y = row;
    });
}

void FeedTable::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_J:
            GotoItem(1);
            break;

        case Qt::Key_K:
            GotoItem(-1);
            break;

        case Qt::Key_L:
            SelectItem();
            break;

        case Qt::Key_H:
            Back();
        break;

        default:
            QTableWidget::keyPressEvent(e);
    }
}

void FeedTable::Back()
{
    emit goBack();
}

void FeedTable::SelectItem()
{
    auto item = this->currentItem();
    item->setBackground(QColor::fromRgb(100, 0, 0));
    emit feedSelected(m_fgn, m_cur_y);
}

void FeedTable::GotoItem(int i)
{
    if (m_cur_y + i < this->rowCount() && m_cur_y + i > -1)
    {
        m_cur_y += i;
        setCurrentCell(m_cur_y, 0);
    }
}

void FeedTable::setFeeds(QVector <Feed> feedlist)
{
    m_feeds = feedlist;
    this->setRowCount(feedlist.size());
    for(int i=0; i < feedlist.size(); i++)
    {
        auto f = feedlist[i];
        QTableWidgetItem *date = new QTableWidgetItem(f.getDate().toString());
        QTableWidgetItem *title = new QTableWidgetItem(f.getTitle());

        if (f.isRead())
        {
            date->setBackground(QColor::fromRgb(100, 0, 0));
            title->setBackground(QColor::fromRgb(100, 0, 0));
        }

        this->setItem(i, 0, date);
        this->setItem(i, 1, title);
    }

    this->setCurrentCell(m_cur_y, 1);
}

void FeedTable::setFeedGroupNumber(int fgn)
{
    m_fgn = fgn;
}

void FeedTable::setFeedNumber(int fn)
{
    m_fn = fn;

}


void FeedTable::RestoreCursor()
{
    setCurrentCell(m_cur_y_sav, 0);
}

void FeedTable::SaveCursor()
{
    m_cur_y_sav = m_cur_y;
}

void FeedTable::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    // Reapply the background color when the widget is shown
    for(int i=0; i < rowCount(); i++)
    {
        for(int j=0; j < columnCount(); j++)
        {
            if (m_feeds[i].isRead())
            {
                this->itemAt(i, j)->setBackground(QColor::fromRgb(100, 0, 0));
            }
        }
    }
}

FeedTable::~FeedTable()
{

}

#endif // !FEEDTABLE_CPP
