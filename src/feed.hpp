#ifndef FEED_HPP
#define FEED_HPP

#include <qt6/QtCore/QDate>
#include <qt6/QtCore/QString>

class Feed
{

public:
    Feed(QString title, QString content, QString desc, QDateTime dt, QString link);
    ~Feed();

    QDateTime getDate() { return datetime; }
    QString getDesc() { return desc; }
    QString getLink() { return link; } 
    QString getTitle() { return title; }
    QString getContent() { return content; }

private:
    QString title;
    QString content;
    QString desc;
    QString link;
    QDateTime datetime;
    int fc;
};
#endif // !FEED_HPP
