#include"statuswidget.h"
#include"qpainter.h"
#include"qtimer.h"
#include"qlabel.h"
#include"qboxlayout.h"
#include"qdatetime.h"
#include"qstyleoption.h"
#include"qlabel.h"
#include"qsizegrip.h"
StatusWidget::StatusWidget(QWidget *parent) : QWidget(parent)
{
    title = QString("协议管理工具");
    version = QString("V1.0");
    author = QString("");
    currentUserName = "admin";
    currentUserType = QString("管理员");
    fontName = "Microsoft Yahei";
    fontSize = 9;
    lineFixedWidth = true;

    day = 0;
    hour = 0;
    minute = 0;
    seconds = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));

    labTitle = 0;
    labAuthor = 0;
    labUser = 0;
    labLive = 0;
    labDateTime = 0;

    labTitleVisible = true;
    labAuthorVisible = true;
    labUserVisible = false;
    labLiveVisible = true;
    labDateTimeVisible = false;

    start(1000);
}

void StatusWidget::paintEvent(QPaintEvent *)
{
    //加上此代码让继承类样式起作用
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void StatusWidget::showTime()
{
    seconds++;

    if (seconds == 60) {
        minute++;
        seconds = 0;
    }

    if (minute == 60) {
        hour++;
        minute = 0;
    }

    if (hour == 24) {
        day++;
        hour = 0;
    }

    QDateTime now = QDateTime::currentDateTime();
   labLive->setText(QString("%1:%2%3%4%5%6%7%8%9")\
                    .arg(QString("已运行"))\
                    .arg(day).arg(QString("天"))\
                    .arg(hour).arg(QString("时"))\
                    .arg(minute).arg(QString("分"))\
                    .arg(seconds).arg(QString("秒")));

   labDateTime->setText(now.toString("%1:yyyy%2 MM%3 dd%4 HH:mm:ss")
                        .arg(QString("当前时间"))
                        .arg(QString("年"))
                        .arg(QString("月"))
                        .arg(QString("日")));

}

void StatusWidget::setLabTitleVisible(bool labTitleVisible)
{
    this->labTitleVisible = labTitleVisible;
}

void StatusWidget::setLabAuthorVisible(bool labAuthorVisible)
{
    this->labAuthorVisible = labAuthorVisible;
}

void StatusWidget::setLabUserVisible(bool labUserVisible)
{
    this->labUserVisible = labUserVisible;
}

void StatusWidget::setLabLiveVisible(bool labLiveVisible)
{
    this->labLiveVisible = labLiveVisible;
}

void StatusWidget::setLabDateTimeVisible(bool labDateTimeVisible)
{
    this->labDateTimeVisible = labDateTimeVisible;
}

void StatusWidget::setTitle(const QString &title)
{
    if (this->title != title) {
        this->title = title;
        if (labTitle != 0) {
            labTitle->setText(QString("%1%2 %3").arg(QString("欢迎使用"))
                              .arg(title).arg(version));
        }
    }
}

void StatusWidget::setVersion(const QString &version)
{
    if (this->version != version) {
        this->version = version;
        if (labTitle != 0) {
            labTitle->setText(QString("%1%2 %3").arg(QString("欢迎使用"))
                              .arg(title).arg(version));
        }
    }
}

void StatusWidget::setAuthor(const QString &author)
{
    if (this->author != author) {
        this->author = author;
        if (labAuthor != 0) {
            labAuthor->setText(QString("%1: %2").arg(QString("版权所有")).arg(author));
        }
    }
}

void StatusWidget::setCurrentUserName(const QString &currentUserName)
{
    if (this->currentUserName != currentUserName) {
        this->currentUserName = currentUserName;
        if (labUser != 0) {
            labUser->setText(QString("%1: %2:%3%4")
                             .arg(QString("当前用户"))\
                             .arg(currentUserName)\
                             .arg(currentUserType)\
                             .arg(QString("】")));
        }
    }
}

void StatusWidget::setCurrentUserType(const QString &currentUserType)
{
    if (this->currentUserType != currentUserType) {
        this->currentUserType = currentUserType;
        if (labUser != 0) {
            labUser->setText(QString("%1: %2:%3%4")
                             .arg(QString("当前用户"))
                             .arg(currentUserName)
                             .arg(currentUserType)
                             .arg(QString("】")));
        }
    }
}

void StatusWidget::setFontName(const QString &fontName)
{
    this->fontName = fontName;
}

void StatusWidget::setFontSize(int fontSize)
{
    this->fontSize = fontSize;
}

void StatusWidget::setLineFixedWidth(bool lineFixedWidth)
{
    this->lineFixedWidth = lineFixedWidth;
}

//主要部分
void StatusWidget::start(int interval)
{
    labTitle = new QLabel;
    labTitle->setText(QString("%1%2 %3").arg(QString("欢迎使用")).arg(title).arg(version));

    labAuthor = new QLabel;
    labAuthor->setText(QString("%1: %2").arg(QString("版权所有")).arg(author));

    labUser = new QLabel;
    labUser->setText(QString("%1: %2%3%4%5")
                     .arg(QString("当前用户"))
                     .arg(currentUserName)
                     .arg(QString("【"))
                     .arg(currentUserType)
                     .arg(QString("】")));

    labLive = new QLabel;
    labDateTime = new QLabel;
    labDateTime->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    showTime();

    QFrame *line1 = new QFrame;
    line1->setFrameShape(QFrame::VLine);
    line1->setFrameShadow(QFrame::Sunken);

    QFrame *line2 = new QFrame;
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Sunken);

    QFrame *line3 = new QFrame;
    line3->setFrameShape(QFrame::VLine);
    line3->setFrameShadow(QFrame::Sunken);

    QFrame *line4 = new QFrame;
    line4->setFrameShape(QFrame::VLine);
    line4->setFrameShadow(QFrame::Sunken);

    if (lineFixedWidth) {
        line1->setFixedWidth(1);
        line2->setFixedWidth(1);
        line3->setFixedWidth(1);
        line4->setFixedWidth(1);
    }

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(6);
    layout->setContentsMargins(6, 6, 6, 6);

    if (labTitleVisible) {
        layout->addWidget(labTitle);
        layout->addWidget(line1);

    }

    if (labAuthorVisible) {
        layout->addWidget(labAuthor);
        layout->addWidget(line2);
    }

    if (labUserVisible) {
        layout->addWidget(labUser);
        layout->addWidget(line3);
    }

    if (labLiveVisible) {
        layout->addWidget(labLive);
        layout->addWidget(line4);
    }

    if (labDateTimeVisible) {
        layout->addWidget(labDateTime);
    }

    layout->addStretch();

    QSizeGrip *grip = new QSizeGrip(this);
    layout->addWidget(grip);

    QFont font = QFont(fontName, fontSize);
    QList<QLabel *> labs = this->findChildren<QLabel *>();

    foreach (QLabel *lab, labs) {
        lab->setFont(font);
    }

    timer->start(interval);
}
