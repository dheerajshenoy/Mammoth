#ifndef FEEDTABLE_HPP
#define FEEDTABLE_HPP

#include <qt6/QtWidgets/QTableWidget>
#include <qt6/QtWidgets/QWidget>
#include <qt6/QtGui/QKeyEvent>
#include "feedgroup.hpp"

class FeedTable : public QTableWidget
{

public:
    FeedTable(QWidget *parent = nullptr);
    ~FeedTable();

    void GotoItem(int i);
    void SelectItem();
    void Back();

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:

    int m_cur_y = 0;
};

#endif
