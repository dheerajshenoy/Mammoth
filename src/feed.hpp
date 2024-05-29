#ifndef FEED_HPP
#define FEED_HPP

#include <qt6/QtCore/QDate>
#include <qt6/QtCore/QString>

class Feed
{

public:
    Feed(QString title, QString content, QString desc, QDateTime dt, QString link);
    Feed();
    ~Feed();

    const QDateTime getDate() { return datetime; }
    const QString getDesc() { return desc; }
    const QString getLink() { return link; } 
    const QString getTitle() { return title; }
    const QString getContent() { return content; }
    void setInfo(QString title, QString content, QString desc, QDateTime dt, QString link);


private:
    QString title;
    QString content;
    QString desc;
    QString link;
    QDateTime datetime;
    int fc;
};
#endif // !FEED_HPP
