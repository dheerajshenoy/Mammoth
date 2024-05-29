#include "feedreader.hpp"

FeedReader::FeedReader(QWidget *parent)
:QWidget(parent)
{
    this->setLayout(m_layout);
    m_layout->addWidget(webview);
    this->show();
}

void FeedReader::setFeed(Feed &feed)
{
    m_feed.setInfo(feed.getTitle(), feed.getContent(), feed.getDesc(), feed.getDate(), feed.getLink());
    qDebug() << feed.getTitle();
    populate();
}

void FeedReader::populate()
{
    QString content = m_feed.getContent();
    QString html = QString(R"(
                           <html>
                           <head>
                               <title>Hello World</title>
                               <meta charset="utf-8">
                               <script type="text/javascript" id="MathJax-script" async
                               src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js">
                               </script>
                           </head>
                           <body bg="#FF5000">
                           <div id="formula">
                           %1
                           </div>
                           </body>
                           </html>
                           )").arg(content);

    webview->setHtml(html);
}

void FeedReader::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_J:
            ScrollDown();
            break;

        case Qt::Key_K:
            ScrollUp();
            break;

        case Qt::Key_L:
            break;

        case Qt::Key_Escape:
            emit gotoFeeds();
            break;

        default:
            QWidget::keyPressEvent(e);
    }
}

void FeedReader::ScrollUp()
{

}

void FeedReader::ScrollDown()
{

}

FeedReader::~FeedReader()
{

}
