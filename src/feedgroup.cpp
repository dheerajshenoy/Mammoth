#ifndef FEEDGROUP_CPP
#define FEEDGROUP_CPP


#include "feedgroup.hpp"

FeedGroup::FeedGroup(QString title)
:m_title(title)
{

}

FeedGroup::FeedGroup()
{

}

void FeedGroup::setTitle(QString title)
{
    m_title = title;
}

void FeedGroup::addFeed(Feed feed)
{

}

void FeedGroup::removeFeed(int index)
{

}

void FeedGroup::removeFeed(Feed feed)
{

}

void FeedGroup::setFeeds(Feed *feeds)
{
}

void FeedGroup::setFeeds(QVector<Feed> feeds)
{
    m_feeds = feeds;
    m_fc = feeds.size();
}

void FeedGroup::displayFeeds()
{

}

FeedGroup::~FeedGroup()
{

}
#endif // !FEEDGROUP_CPP
