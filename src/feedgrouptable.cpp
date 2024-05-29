#ifndef FEEDGROUPTABLE_CPP
#define FEEDGROUPTABLE_CPP

#include "feedgrouptable.hpp"

FeedGroupTable::FeedGroupTable(QWidget *parent)
:QTableWidget(parent)
{

    QStringList Headers = { "Feeds", "Title" };

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

void FeedGroupTable::keyPressEvent(QKeyEvent *e)
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

        default:
            QTableWidget::keyPressEvent(e);
    }
}

void FeedGroupTable::SelectItem()
{
    emit feedSelected(m_cur_y);
}

void FeedGroupTable::GotoItem(int i)
{
    if (m_cur_y + i < this->rowCount() && m_cur_y + i > -1)
    {
        m_cur_y += i;
        setCurrentCell(m_cur_y, 0);
    }
}

void FeedGroupTable::setFeedGroup(FeedGroup group)
{

}

FeedGroupTable::~FeedGroupTable()
{

}

#endif
