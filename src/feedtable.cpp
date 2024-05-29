#ifndef FEEDTABLE_CPP
#define FEEDTABLE_CPP

#include "feedtable.hpp"

FeedTable::FeedTable(QWidget *parent)
:QTableWidget(parent)
{

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

}

void FeedTable::SelectItem()
{
    
}

void FeedTable::GotoItem(int i)
{
    m_cur_y += i;
    if (m_cur_y < this->rowCount())
        setCurrentCell(m_cur_y, 0);
}

FeedTable::~FeedTable()
{

}

#endif // !FEEDTABLE_CPP
