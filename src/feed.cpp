#ifndef FEED_CPP
#define FEED_CPP

#include "feed.hpp"

Feed::Feed()
{}

Feed::Feed(const QString _title, const QString _content, const QString _desc,
           const QDateTime _dt, const QString _link)
:title(_title), content(_content), desc(_desc), datetime(_dt), link(_link)
{}

void Feed::setInfo(const QString title, const QString content, const QString desc, const QDateTime dt, const QString link)
{
    this->title = title;
    this->content = content;
    this->desc = desc;
    this->datetime = dt;
    this->link = link;
}

/*Feed::Feed(const Feed &f)*/
/*{*/
/*    this->desc = f.getDesc();*/
/*    this->title = f.getTitle();*/
/*    this->content = f.getContent();*/
/*    this->datetime = f.getDate();*/
/*    this->link = f.getLink();*/
/*}*/

void Feed::setRead(bool r)
{
    m_read = r;
}

bool Feed::isRead()
{
    return m_read;
}

Feed::~Feed()
{

}

#endif

