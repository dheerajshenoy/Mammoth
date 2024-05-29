#ifndef FEEDGROUP_HPP
#define FEEDGROUP_HPP

#include <qt6/QtCore/QString>
#include <qt6/QtCore/QList>
#include "feed.hpp"

class FeedGroup
{
    public:
    FeedGroup();
    FeedGroup(QString title);
    ~FeedGroup();

    void setTitle(const QString title);
    void addFeed(const Feed feed);
    void removeFeed(const Feed feed);
    void removeFeed(const int index);
    void setFeeds(const QVector<Feed> &feeds);
    void setFeeds(const Feed *feeds);
    void displayFeeds();
    int getFeedCount() { return m_fc; }
    QString getTitle() { return m_title; }
    void setFeedCount(const int count) { m_fc = count; }
    const QVector<Feed> getFeedList() { return m_feeds; }

private:
    QVector<Feed> m_feeds;
    QString m_title;
    int m_fc; // Feed Count
};

#endif
