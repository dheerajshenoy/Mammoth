#ifndef MAMMOTH_CPP
#define MAMMOTH_CPP

#include "mammoth.hpp"

Mammoth::Mammoth(QWidget *parent)
:QMainWindow(parent)
{
    connect(m_networkManager, &QNetworkAccessManager::finished, this, &Mammoth::onFeedFetched);
    m_widget->setLayout(m_layout);
    this->setCentralWidget(m_widget);
    InitGui();
    InitKeybinds();
    ReadFeeds();
    FetchFeeds();
    displayFeedGroups();
}

void Mammoth::InitGui()
{
    InitFeedTable();
    m_layout->addWidget(m_feed_table);
}

void Mammoth::InitFeedTable()
{
    m_feed_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_feed_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_feed_table->horizontalHeader()->setStretchLastSection(true);

    QStringList Headers = { "Feeds", "Title" };

    m_feed_table->setHorizontalHeaderLabels(Headers);
    m_feed_table->setColumnCount(Headers.size());
}

void Mammoth::ReadFeeds()
{
    m_sources = { "https://archlinux.org/feeds/news/",
        "https://rss.arxiv.org/rss/astro-ph",
        "https://lifehacker.com/feed/rss",
        "https://www.wired.com/feed/rss"
    };
}

void Mammoth::FetchFeeds()
{
    for(uint i=0; i < m_sources.size(); i++)
    //for(uint i=0; i < 1; i++)
    {
        m_networkManager->get(QNetworkRequest(QUrl(m_sources[i])));
    }
}

void Mammoth::RefreshFeeds()
{
    for(uint i=0; i < m_sources.size(); i++)
    {

    }
}

void Mammoth::onFeedFetched(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        ParseFeed(reply);
    }
    else {
        // TODO : Handle error
    }

    reply->deleteLater();
}

void Mammoth::InitKeybinds()
{
}

void Mammoth::GotoItem(int i)
{
}

void Mammoth::Back()
{

}

void Mammoth::MarkItem()
{

}

void Mammoth::SelectItem()
{

}


void Mammoth::ParseFeed(QIODevice *device)
{
    FeedGroup fg;
    QXmlStreamReader xml(device);
    QDateTime dt;
    QString dt_format = "ddd, dd MMM yyyy HH:mm:ss +0000";
    QString title, link, content, desc;
    QString groupTitle;

    while (!xml.atEnd() && !xml.hasError())
    {
        xml.readNext();
        if (xml.isStartElement())
        {

            if (xml.name().toString() == "channel")
            {
                while (!(xml.isEndElement() && xml.name().toString() == "channel"))
                {
                    xml.readNext();
                    if (xml.isStartElement())
                    {
                        if (xml.name().toString() == "title")
                        {
                            fg.setTitle(xml.readElementText());
                        }

                        else if (xml.name().toString() == "link")
                        {

                        }

                        else if (xml.name().toString() == "description")
                        {
                            desc = xml.readElementText();
                        }

                        else if (xml.name().toString() == "item")
                        {
                            QString title, link, pubDate;
                            while (!(xml.isEndElement() && xml.name().toString() == "item"))
                            {
                                xml.readNext();
                                if (xml.isStartElement())
                                {
                                    if (xml.name().toString() == "title")
                                    {
                                        title = xml.readElementText();
                                    }

                                    else if (xml.name().toString() == "link")
                                    {
                                        link = xml.readElementText();
                                    }

                                    else if (xml.name().toString() == "lastBuildDate")
                                    {
                                        dt = QDateTime::fromString(xml.readElementText(), dt_format);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        m_feedItems.append(Feed(title, content, desc, dt, link));
    }

    fg.setFeeds(m_feedItems);
    m_feedGroups.append(fg);
    displayFeedGroups();
}

void Mammoth::displayFeedGroups()
{
    m_feed_table->setRowCount(m_feedGroups.size());
    for(int i=0; i < m_feedGroups.size(); i++)
    {
        auto &fg = m_feedGroups[i];

        QTableWidgetItem *feedcount = new QTableWidgetItem(QString::number(fg.getFeedCount()));
        QTableWidgetItem *title = new QTableWidgetItem(fg.getTitle());

        m_feed_table->setItem(i, 0, feedcount);
        m_feed_table->setItem(i, 1, title);
    }
    m_feed_table->setCurrentCell(m_cur_y, 1);
}

Mammoth::~Mammoth()
{

}

#endif
