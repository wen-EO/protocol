#include "hstatuswidget.h"
#include "ui_hstatuswidget.h"
#include"statuswidget.h"
#include"QHBoxLayout"
#include"qpainter.h"
#include"QStyleOption"
HStatusWidget::HStatusWidget(QWidget *parent) :
    QWidget(parent),statusWidget(NULL),
    ui(new Ui::HStatusWidget)
{
    ui->setupUi(this);
    init();
}

HStatusWidget::~HStatusWidget()
{
    delete ui;
}
void HStatusWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
void HStatusWidget::init()
{
    if(statusWidget==NULL)
    {
        statusWidget = new StatusWidget;
        QHBoxLayout * layout = new QHBoxLayout(this);
        layout->setContentsMargins(0,0,0,0);
        layout->addWidget(statusWidget);
    }

    this->setProperty("form","bottom");
}
