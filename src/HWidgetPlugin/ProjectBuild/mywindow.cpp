#include "mywindow.h"

MyWindow::MyWindow(QFrame *parent) : QFrame(parent)
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    m_titleBar = new MyTitleBar(this);
    m_contentWidget = new QWidget(this);
    m_contentWidget->setObjectName("Contents");
    m_layout = new QVBoxLayout;
    m_layout->addWidget(m_titleBar);
    m_layout->addWidget(m_contentWidget);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(m_layout);
}

void MyWindow::setWindowTitle(const QString &title)
{
    m_titleBar->setWindowTitle(title);
}

void MyWindow::SetTitleBarIcon(const QString &iconPath)
{
    m_titleBar->SetTitleBarIcon(iconPath);
}

QWidget *MyWindow::contentWidget()
{
    return m_contentWidget;
}

void MyWindow::setWindowTitleHeight(int h)
{
    m_titleBar->setFixedHeight(h);
}
