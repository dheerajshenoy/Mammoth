#ifndef MAMMOTH_HPP
#define MAMMOTH_HPP


#include <qt6/QtWidgets/QMainWindow>
#include <qt6/QtWidgets/QApplication>
#include <qt6/QtWidgets/QVBoxLayout>
#include <qt6/QtWidgets/QHBoxLayout>
#include <qt6/QtWidgets/QLabel>
#include <qt6/QtWidgets/QPushButton>
#include <qt6/QtWidgets/QLineEdit>
#include <qt6/QtWidgets/QMenu>
#include <qt6/QtWidgets/QMenuBar>
#include <qt6/QtWidgets/QHeaderView>
#include <qt6/QtWidgets/QAbstractItemView>
#include <qt6/QtWidgets/QStackedWidget>
#include <qt6/QtGui/QShortcut>
#include <qt6/QtGui/QKeySequence>
#include <qt6/QtNetwork/QNetworkAccessManager>
#include <qt6/QtNetwork/QNetworkReply>
#include <qt6/QtNetwork/QNetworkRequest>
#include <qt6/QtCore/QXmlStreamReader>
#include <qt6/QtCore/QDateTime>
#include <qt6/QtCore/QVector>
#include "feedtable.hpp"
#include "feedreader.hpp"
#include "feedgrouptable.hpp"
#include "panel.hpp"

class Mammoth : public QMainWindow
{
    public:
    Mammoth(QWidget *parent = nullptr);
    ~Mammoth();

    void InitGui();
    void ReadFeeds();
    void FetchFeeds();
    void onFeedFetched(QNetworkReply *reply);
    void RefreshFeeds();
    void ParseFeed(QIODevice *device);
    void displayFeeds(QVector<Feed>);
    void displayFeedGroups();
    void InitKeybinds();
    void SelectFeedGroup(int fgNum);
    void SelectFeed(int feedGroupNum, int feedNum);
    void ShowFeedGroupPage();
    void ShowFeedsPage();

private:
    QVBoxLayout *m_layout = new QVBoxLayout();
    QStackedWidget *m_stackwidget = new QStackedWidget();
    QStringList m_sources = {};
    FeedGroupTable *m_feedgroup_table = new FeedGroupTable();
    FeedTable *m_feed_table = new FeedTable();
    QNetworkAccessManager *m_networkManager = new QNetworkAccessManager(this);
    QVector<Feed> m_feedItems;
    QVector<FeedGroup> m_feedGroups;
    bool date_read = false, main_title_read = false, channel_read = false;

    int m_cur_y = 0;
    FeedReader *m_reader = new FeedReader();
    Panel *m_panel = new Panel();
    QWidget *m_widget = new QWidget();
};

#endif
