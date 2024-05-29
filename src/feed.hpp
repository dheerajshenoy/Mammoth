#ifndef FEED_HPP
#define FEED_HPP

#include <qt6/QtCore/QDate>
#include <qt6/QtCore/QString>

class Feed
{

public:
    Feed(const QString title, const QString content, const QString desc, const QDateTime dt, const QString link);
    Feed();
    ~Feed();

    const QDateTime getDate() { return datetime; }
    const QString getDesc() { return desc; }
    const QString getLink() { return link; } 
    const QString getTitle() { return title; }
    const QString getContent() { return content; }
    void setInfo(const QString title, const QString content, const QString desc, const QDateTime dt, const QString link);


private:
    QString title;
    QString content;
    QString desc;
    QString link;
    QDateTime datetime;
    int fc;
};
#endif // !FEED_HPP
