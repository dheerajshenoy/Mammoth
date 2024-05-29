#ifndef FEED_CPP
#define FEED_CPP

#include "feed.hpp"

Feed::Feed()
{}

Feed::Feed(QString _title, QString _content, QString _desc, QDateTime _dt, QString _link)
:title(_title), content(_content), desc(_desc), datetime(_dt), link(_link)
{}

void Feed::setInfo(QString title, QString content, QString desc, QDateTime dt, QString link)
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

Feed::~Feed()
{

}

#endif
