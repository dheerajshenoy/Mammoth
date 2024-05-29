#include "feedreader.hpp"

FeedReader::FeedReader(QWidget *parent)
:QWidget(parent)
{
    this->setLayout(m_layout);
    m_layout->addWidget(webview);
    m_layout->addWidget(prevBtn);

    connect(prevBtn, &QPushButton::clicked, this, [=]() {
        emit gotoFeeds();
    });
    this->show();
}

void FeedReader::setFeed(Feed feed)
{
    m_feed.setInfo(feed.getTitle(), feed.getContent(), feed.getDesc(), feed.getDate(), feed.getLink());
    populate();
}

void FeedReader::populate()
{
    QString content = m_feed.getDesc();
    QString html = QString(R"(
                           <html>
                           <head>
                           <title>Hello World</title>
                           <meta charset="utf-8">
                           <script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
                           <script id="MathJax-script" async
                           src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js">
                           </script>
                           </head>
                           <body>
                           <p>%1</p>
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
