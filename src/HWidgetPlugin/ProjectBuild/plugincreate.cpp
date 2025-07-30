#include "plugincreate.h"
#include "ui_plugincreate.h"
#include "qpainter.h"
#include "qstyleoption.h"
#include "hqss.h"
#include <QFile>

PluginCreate::PluginCreate(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::PluginCreate)
{
    initTitleBar();
    ui->setupUi(this);
}

PluginCreate::~PluginCreate()
{
    delete ui;
}

void PluginCreate::initTitleBar()
{
    //设置标题栏跑马灯效果，可以不设置;
    //m_titleBar->setTitleRoll();
    //m_titleBar->setBackgroundColor(56,70,85);
}

void PluginCreate::on_pushButton_2_clicked()
{
    this->close();
}

void PluginCreate::on_pushButton_3_clicked()
{
    this->close();
}
