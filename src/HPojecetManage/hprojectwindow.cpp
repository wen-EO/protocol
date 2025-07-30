#include "hprojectwindow.h"
#include "ui_hprojectwindow.h"
#include "hwidgetdefine.h"
#include "hwidgetlibrary.h"
#include "hdefine.h"

#include "qgridlayout.h"
#include "qstackedlayout.h"
#include "qdebug.h"
#include "hqss.h"
#include "hwindowapi.h"
#include "hlogmanage.h"
#include "hconfigmanage.h"

#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSettings>
#include <QDir>

HProjectWindow::HProjectWindow(QWidget *parent) :
    QMainWindow(parent),m_stackedLayout(NULL),m_titlebar(NULL),m_statusBar(NULL),
    ui(new Ui::HProjectWindow)
{
    ui->setupUi(this);

    init_Config();

    init_Component();

    initWorkSpace();

    setStackedLayout();

    _setStyle();

    bindSigSlots();

    setDockNestingEnabled(true);//允许嵌套dock

    setProperty("canMove", false);//默认窗体最大化，设置为不可移动
}

HProjectWindow::~HProjectWindow()
{
    delete ui;
}

void HProjectWindow::init_Config()
{
    HConfigManage::getInstance()->m_wndList.clear();

    QString filePath = HConfigManage::getInstance()->getAbsolutePath("/config/sysdata.ini");
    //QString configFileName=QDir::currentPath()+"\\sysdata.ini";
    QSettings *settings = new QSettings(filePath,QSettings::IniFormat);
    settings->beginGroup("server");
    HConfigManage::getInstance()->mySQLIP = settings->value("ip").toString();
    HConfigManage::getInstance()->mySQLPort = settings->value("port").toInt();
    HConfigManage::getInstance()->mySQLDbName = settings->value("dbname").toString();
    HConfigManage::getInstance()->mySQLUser = settings->value("user").toString();
    HConfigManage::getInstance()->mySQLPwd = settings->value("pwd").toString();
    settings->endGroup();
}

void HProjectWindow::init_Component()
{
    HConfigManage::getInstance()->m_categoryList.clear();
    HConfigManage::getInstance()->m_wndList.clear();
    init_Category();
    init_Protocol();
}

void HProjectWindow::init_Category()
{
    //连接SQLite，打开数据库，读取协议库信息
    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        //查询数据
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("select id,name,description from category_entity");
        if(!sql_querySQLite.exec(strSQLite))
        {
            qDebug() << sql_querySQLite.lastError();
            return;
        }
        else
        {
            while(sql_querySQLite.next())
            {
                QString categoryId= sql_querySQLite.value(0).toString();
                QString categoryName = sql_querySQLite.value(1).toString();
                QString categoryDescription = sql_querySQLite.value(2).toString();

                category_info *_info = new category_info;
                _info->categoryId = categoryId;
                _info->categoryName = categoryName;
                _info->categoryDescription = categoryDescription;

                HConfigManage::getInstance()->m_categoryList.push_back(_info);
            }
        }
    }
    databaseSQLite.close();
}

void HProjectWindow::init_Protocol()
{
    //连接SQLite，打开数据库，读取协议库信息
    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        //查询数据
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("select A.id,B.name,A.create_user,A.create_time,A.description,A.name,A.version from protocol_entity A join category_entity B on A.category_entity_id=B.id");
        if(!sql_querySQLite.exec(strSQLite))
        {
            qDebug() << sql_querySQLite.lastError();
            return;
        }
        else
        {
            while(sql_querySQLite.next())
            {
                QString pluId= sql_querySQLite.value(0).toString();
                QString pluCategory=sql_querySQLite.value(1).toString();
                QString pluCreateUser = sql_querySQLite.value(2).toString();
                QString pluCreateTime = sql_querySQLite.value(3).toString();
                QString pluDescription = sql_querySQLite.value(4).toString();
                QString pluName = sql_querySQLite.value(5).toString();
                QString pluVersion = sql_querySQLite.value(6).toString();

                hWidget_plu_info *plu_info = new hWidget_plu_info;
                plu_info->pluId = pluId;
                plu_info->pluName = pluName;
                plu_info->pluCategory=pluCategory;
                plu_info->pluCreateUser=pluCreateUser;
                plu_info->pluCreateTime=pluCreateTime;
                plu_info->pluDescription=pluDescription;
                plu_info->pluVersion = pluVersion;

                HConfigManage::getInstance()->m_wndList.push_back(plu_info);
            }
        }
    }
    databaseSQLite.close();
}

void HProjectWindow::initWorkSpace()
{
    foreach(HWIDGET_PLU_INFO *pluItem,HWidgetLibrary::getInstance()->m_wndList)
    {
        HWidgetPluginInterface *pluInter = reinterpret_cast<HWidgetPluginInterface *>(pluItem->pluClass);
        //判断是否是工具栏插件
        if (pluItem->pluType == HDefine::H_UI_PRO)
        {
            if (pluItem->pluName == "titleBar")
            {
                this->m_titlebar = pluInter->createWindow(this);
                qDebug()<<"get it";
                continue;
            }
            else if(pluItem->pluName == "statusWidget")
            {
                this->m_statusBar = pluInter->createWindow(this);
                this->setStatusBar((QStatusBar *)m_statusBar);
                continue;
            }
        }
    }

    if(m_titlebar!=NULL)
    {
        QVBoxLayout *layout = new QVBoxLayout(ui->titleWidget);
        layout->setContentsMargins(0,0,0,0);

        ui->titleWidget->setFixedHeight(70);
        layout->addWidget(m_titlebar);
    }
}

void HProjectWindow::setStackedLayout()
{
    int index = 0;

    if(m_stackedLayout == NULL)
    {
        m_stackedLayout = new QStackedLayout();
        QHBoxLayout *layout = new QHBoxLayout(ui->stackedWidget);
        layout->setContentsMargins(0,0,0,0);
        layout->addLayout(m_stackedLayout);
    }

    foreach(HWIDGET_PLU_INFO *pluItem,HWidgetLibrary::getInstance()->m_wndList)
    {
        //get plugin obj
        HWidgetPluginInterface *pluInter = reinterpret_cast<HWidgetPluginInterface *>(pluItem->pluClass);
        //
        if (pluItem->pluType == HDefine::H_UI_PRO)
        {
            if (pluItem->pluName == "titleBar"||pluItem->pluName == "statusWidget")
            {
                continue;
            }
            else
            {
                m_stackedLayout->insertWidget(index,pluInter->createWindow(this));

                qDebug()<<pluItem->pluName;
                m_layouHash.insert(pluItem->pluName,index);
                index++;
            }
        }
    }
    switchProWnd("ProjectBuild");
}

bool HProjectWindow::switchProWnd(QString funName)
{
    if (funName.isEmpty())
    {
        return false;
    }
    else
    {
        QHash<QString, int>::const_iterator indexItem = m_layouHash.constBegin();
        while (indexItem != m_layouHash.constEnd())
        {
            if (funName == indexItem.key())
            {
                m_stackedLayout->setCurrentIndex(indexItem.value());

            }

            ++indexItem;
        }
    }
    return true;
}

void HProjectWindow::_setStyle()
{
    //
    HQss::getInstance()->setWidgetStyle(HQss::LightBlue,this);

    //this->setProperty("form","true");

    this->setWindowFlags(Qt::FramelessWindowHint );//设置无边框窗口
    //this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明

    //HWindowApi *api = HWindowApi::getInstance();
    //this->resize(api->screenWidth - 510,api->screenHeight - 150);
    //this->move(api->screenWidth / 2 - this->width() / 2,api->screenHeight / 2 - this->height() / 2);
    setGeometry(qApp->desktop()->availableGeometry());
    this->setProperty("canMove", true);
    this->installEventFilter(HWindowApi::getInstance());
}

void HProjectWindow::bindSigSlots()
{
//    connect(HWindowApi::getInstance(),SIGNAL(titleItemClicked(QString)),this,SLOT(switchProWnd(QString)));
//    connect(HWindowApi::getInstance(),SIGNAL(refreshComponent()),this,SLOT(init_Component()));
//    connect(HWindowApi::getInstance(),SIGNAL(refreshCatgory()),this,SLOT(init_Category()));
    connect(HWindowApi::getInstance(),SIGNAL(refreshProtocol()),this,SLOT(init_Component()));
}
