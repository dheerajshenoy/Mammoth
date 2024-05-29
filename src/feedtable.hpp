#ifndef FEEDTABLE_HPP
#define FEEDTABLE_HPP

#include <qt6/QtWidgets/QTableWidget>
#include <qt6/QtWidgets/QWidget>
#include <qt6/QtGui/QKeyEvent>
#include <qt6/QtWidgets/QHeaderView>
#include <qt6/QtCore/QVector>
#include "feed.hpp"

class FeedTable : public QTableWidget
{
Q_OBJECT

public:
    FeedTable(QWidget *parent = nullptr);
    ~FeedTable();

    void GotoItem(int i);
    void SelectItem();
    void Back();
    void setFeedGroupNumber(int fgn);
    void setFeedNumber(int fn);
    void setFeeds(QVector<Feed> feedlist);
    void SaveCursor();
    void RestoreCursor();

signals:
    void feedSelected(int groupnum, int row);
    void goBack(void);

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:

    int m_cur_y = 0;
    int m_cur_y_sav;
    int m_fn;
    int m_fgn;
    
};

#endif
