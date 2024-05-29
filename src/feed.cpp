#ifndef FEED_CPP
#define FEED_CPP

#include "feed.hpp"

Feed::Feed(QString _title, QString _content, QString _desc, QDateTime _dt, QString _link)
:title(_title), content(_content), desc(_desc), datetime(_dt), link(_link)
{

}


Feed::~Feed()
{

}

#endif
