#include "panel.hpp"

Panel::Panel(QWidget *parent)
:QWidget(parent)
{
    m_layout->addWidget(m_msgLabel);
    this->setLayout(m_layout);
    this->show();
}

void Panel::MSG(QString message, int ms)
{
    m_msgLabel->setText(message);

    QTimer::singleShot(ms, [=]() {
        m_msgLabel->setText("");
    });

}

Panel::~Panel()
{

}
