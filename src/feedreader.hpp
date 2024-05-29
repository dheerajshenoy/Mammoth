#ifndef FEEDREADER_HPP
#define FEEDREADER_HPP

#include <qt6/QtWidgets/QWidget>
#include <qt6/QtWidgets/QVBoxLayout>
#include <qt6/QtWidgets/QLabel>
#include <qt6/QtWidgets/QPushButton>
#include <qt6/QtCore/QString>
#include <qt6/QtWebEngineWidgets/QWebEngineView>
#include <qt6/QtGui/QKeyEvent>
#include "feed.hpp"

class FeedReader : public QWidget
{
Q_OBJECT

public:
    FeedReader(QWidget *parent = nullptr);
    ~FeedReader();

    void setFeed(Feed feed);
    void populate();
    void ScrollDown();
    void ScrollUp();

protected:
    void keyPressEvent(QKeyEvent *e) override;

signals:
    void gotoFeeds();

private:
    QVBoxLayout *m_layout = new QVBoxLayout();
    Feed m_feed;
    QWebEngineView *webview = new QWebEngineView();
    QPushButton *prevBtn = new QPushButton("Previous Page");
};

#endif // FEEDREADER_HPP
