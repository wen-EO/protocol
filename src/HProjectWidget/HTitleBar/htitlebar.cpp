#include "htitlebar.h"
#include "ui_htitlebar.h"
#include "QtAwesome.h"
#include "QPainter"
#include "qdebug.h"
#include "hconfigmanage.h"
#include "qfile.h"
#include "qtoolbutton.h"
#include "hwindowapi.h"
#include "hqss.h"
#include "hwindowapi.h"

#include <QStyleOption>
#include <QDesktopWidget>
#include <QDomDocument>

HTitleBar::HTitleBar(QWidget *parent) :
    QWidget(parent),max(true),m_parent(parent),
    ui(new Ui::HTitleBar),titleName(""),nameSize(""),titleIcon(""),titleIconSize("")
{
    ui->setupUi(this);

    if(m_parent!=NULL)
        location = m_parent->geometry();

    init();

    setTitle("");

    bindSigSlots();
}

HTitleBar::~HTitleBar()
{
    delete ui;
}

void HTitleBar::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void HTitleBar::init()
{
    initStyle();

    getTitleItems();

    fillTitle();

    showColorMenu(false);

    //安装事件监听器,让标题栏识别鼠标双击
    ui->widgetTitle->installEventFilter(this);
}

bool HTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->on_btnMenu_Max_clicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void HTitleBar::initStyle()
{
    this->setProperty("form", "title");
    this->setProperty("nav", "top");

    ui->btnMenu_Min->setFont(QtAwesome::getInstance()->font(20));
    ui->btnMenu_Min->setText(QChar(0xF068));
//    ui->btnMenu_Max->setFont(QtAwesome::getInstance()->font(20));
//    ui->btnMenu_Max->setText( QChar(0xf2d2));
//    ui->btnMenu_Close->setFont(QtAwesome::getInstance()->font(20));
//    ui->btnMenu_Close->setText(QChar(0xF00d));
    ui->btnMenu_Max->setFont(QtAwesome::getInstance()->font(20));
    ui->btnMenu_Max->setText( QChar(0xf079));
    ui->btnMenu_Close->setFont(QtAwesome::getInstance()->font(20));
    ui->btnMenu_Close->setText(QChar(0xF00d));
    HWindowApi *api = HWindowApi::getInstance();
    location={300,150,api->screenWidth-600,api->screenHeight-400};
}

bool HTitleBar::getTitleItems()
{
//    QString filePath = HConfigManage::getInstance()->getAbsolutePath("/config/projectWidget/titleBar.xml");
//    QString filePath = QApplication::applicationDirPath()+"/titleBar.xml";
    QString filePath = HConfigManage::getInstance()->getAbsolutePath("/config/titleBar.xml");
    qDebug()<<filePath;
    if(filePath == "")
        return false ;
    else
    {
        QDomDocument dom;
        QFile r_file(filePath);
        if (!r_file.open( QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }
        dom.setContent(&r_file);
        r_file.close();

        barInfo.clear();

        QDomElement root = dom.documentElement();
        QString root_name = root.tagName();
        //判断XML头格式<titleBar>
        if (root_name == "titleBar")
        {
            //根节点
            QDomElement person = root.firstChildElement();
            if (person.isNull())
            {
                return false;
            }
            QDomNodeList list = root.childNodes();
            int count = list.count();
            //第一层<function>子节点内容
            for (int i = 0;i < count;++i)
            {
                QDomNode dom_node = list.item(i);
                QDomElement element = dom_node.toElement();

                if(element.nodeName()=="title")
                {
                    this->titleName = element.attributeNode("titleName").value();
                    this->nameSize = element.attributeNode("nameSize").value();
                    this->titleIcon = element.attributeNode("titleIcon").value();
                    this->titleIconSize = element.attributeNode("titleIconSize").value();
                }
                else if(element.nodeName()=="item")
                {
                    titleItem info;
                    info.index = element.attributeNode("index").value().toInt();
                    info.name = element.attributeNode("name").value();
                    info.displayName = element.attributeNode("displayName").value();
                    info.icon = element.attributeNode("icon").value();
                    info.iconColor = element.attributeNode("iconColor").value();
                    barInfo.append(info);
                }
            }
        }
    }
}

void HTitleBar::fillTitle()
{
    qSort(barInfo.begin(),barInfo.end(),compareByIndex);

    QList<titleItem>::iterator itr = barInfo.begin();
    for (; itr != barInfo.end();++itr)
    {
        addQToolBtn(*itr);
    }

    QToolButton *btn = btnList.at(0);
    btn->setChecked(true);
}

void HTitleBar::addQToolBtn(const titleItem & item)
{
    QToolButton * btn = new QToolButton(ui->widgetTop);
    btn->setFont(QFont(HQss::FontName));
    btn->setCheckable(true);
    btn->setFixedHeight(50);
    btn->setFixedWidth(70);
    btn->setObjectName(item.name);
    btn->setText(item.displayName);

    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->horizontalLayout_3->addWidget(btn);

    QVariantMap options;
    options.insert("color",QColor(item.iconColor));
    options.insert("scale-factor",1.0);
    //options.insert("anim", qVariantFromValue( new QtAwesomeAnimation(ui->btnConfig) ) );

    //btn->setFont(QtAwesome::getInstance()->font(12));
    btn->setIcon(QtAwesome::getInstance()->icon( item.icon.toInt(0,16), options  ) );

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(itemClicked()));

    btnList.append(btn);
}

void HTitleBar::showColorMenu(bool show)
{
    if(!show)
    {
        ui->btnMenu->hide();
    }
    else
    {
        ui->btnMenu->setFont(QtAwesome::getInstance()->font(18));
        //ui->btnMenu->setText(QChar(0xf0d7));
        ui->btnMenu->setText(QChar(0xf0c9));
        ui->btnMenu->setFocusPolicy(Qt::NoFocus);
        ui->btnMenu->setPopupMode(QToolButton::InstantPopup);
        QStringList name;
        name<<"black"<<"white"<<"blue";
        foreach (QString str, name)
        {
            QAction *action = new QAction(str, this);
            ui->btnMenu->addAction(action);
            connect(action, SIGNAL(triggered(bool)), this, SLOT(changeStyle()));
        }
        ui->btnMenu->show();
    }
}

void HTitleBar::setTitle(const QString &title)
{
    ui->labTitle->setFont(QFont(HQss::FontName,this->nameSize.toInt()));
    ui->labTitle->setText(this->titleName);
    ui->labIco->setFont(QtAwesome::getInstance()->font(this->titleIconSize.toInt()));
    ui->labIco->setText(QChar(this->titleIcon.toInt(0,16)));
}

void HTitleBar::changeStyle()
{
    QAction *act = (QAction *)sender();
    QString name = act->text();
    if(name == "black")
    {
        //HQss::getInstance()->changeStyle(HQss::FlatBlack);
    }
    else if(name == "white")
    {
        //HQss::getInstance()->changeStyle(HQss::FlatWhite);
    }
    else if (name == "blue")
    {
        //HQss::getInstance()->changeStyle(HQss::LightBlue);
    }
}

void HTitleBar::getItemClicked(const QString &name)
{
    if(!name.isEmpty())
    {
        foreach(QToolButton *btn,btnList)
        {
            if(btn->text()==name)
            {
                emit btn->click();
            }
        }
    }
}

bool HTitleBar::compareByIndex(const HTitleBar::titleItem &r1, const HTitleBar::titleItem &r2)
{
    return r1.index < r2.index;
}

void HTitleBar::bindSigSlots()
{
     connect(HWindowApi::getInstance(),SIGNAL(clickTitleItem(QString)),this,SLOT(getItemClicked(QString)));
}

void HTitleBar::on_btnMenu_Min_clicked()
{
    if(m_parent!=NULL)
    {
        m_parent->showMinimized();
    }
}

void HTitleBar::on_btnMenu_Max_clicked()
{
    //the current state is Maxed
    //will be normalSized
    if(m_parent!=NULL)
    {
        if (max)
        {
            m_parent->setGeometry(location);
            m_parent->setProperty("canMove", true);
            //ui->btnMenu_Max->setText( QChar(0xf2d0));
            ui->btnMenu_Max->setText( QChar(0xf096));
        } else {
            location = m_parent->geometry();
            m_parent->setGeometry(qApp->desktop()->availableGeometry());
            //ui->btnMenu_Max->setText( QChar(0xf2d2));
            ui->btnMenu_Max->setText( QChar(0xf079));
            m_parent->setProperty("canMove", false);
        }

        max = !max;
    }
    else
    {
        return ;
    }
}

void HTitleBar::on_btnMenu_Close_clicked()
{
 //   exit(0);
    m_parent->close();
}

void HTitleBar::itemClicked()
{
    QToolButton *btn = (QToolButton *)sender();
    QList<QToolButton *> btns = this->findChildren<QToolButton *>();
    foreach (QToolButton *b, btnList)
    {
        titleItem item;
        for(int i=0;i<barInfo.size();i++)
        {
            if(barInfo.at(i).name == b->objectName())
            {
                item = barInfo.at(i);
                break;
            }
        }

        if (btn == b)
        {
            b->setChecked(true);

            QVariantMap options;
            //options.insert("color",QColor(0,100,190));
            options.insert("color",QColor(255,255,255));
            options.insert("scale-factor",1.0);
            b->setIcon(QtAwesome::getInstance()->icon( item.icon.toInt(0,16), options  ) );
        }
        else
        {
            b->setChecked(false);

            QVariantMap options;
            options.insert("color",item.iconColor);
            options.insert("scale-factor",1.0);
            b->setIcon(QtAwesome::getInstance()->icon( item.icon.toInt(0,16), options  ) );
        }
    }

    QString name = btn->objectName();
    emit HWindowApi::getInstance()->titleItemClicked(name);
}
