#ifndef FEEDGROUPTABLE_HPP
#define FEEDGROUPTABLE_HPP

#include <qt6/QtWidgets/QTableWidget>
#include <qt6/QtWidgets/QWidget>
#include <qt6/QtGui/QKeyEvent>
#include <qt6/QtWidgets/QHeaderView>
#include "feedgroup.hpp"

class FeedGroupTable : public QTableWidget
{
Q_OBJECT

public:
    FeedGroupTable(QWidget *parent = nullptr);
    ~FeedGroupTable();

    void GotoItem(int i);
    void SelectItem();
    void setFeedGroup(FeedGroup group);

    void SaveCursor();
    void RestoreCursor();

signals:
    void feedSelected(int row);

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:

    int m_cur_y = 0;
    int m_cur_y_sav;
};

#endif
