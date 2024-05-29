#ifndef FEEDGROUP_CPP
#define FEEDGROUP_CPP


#include "feedgroup.hpp"

FeedGroup::FeedGroup(const QString title)
:m_title(title)
{

}

FeedGroup::FeedGroup()
{

}

void FeedGroup::setTitle(const QString title)
{
    m_title = title;
}

void FeedGroup::addFeed(const Feed feed)
{

}

void FeedGroup::removeFeed(const int index)
{

}

void FeedGroup::removeFeed(const Feed feed)
{

}

void FeedGroup::setFeeds(const Feed *feeds)
{
}

void FeedGroup::setFeeds(const QVector<Feed> &feeds)
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
