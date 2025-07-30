#include "basetitlebar.h"
#include "QtAwesome.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QDebug>

#define BUTTON_HEIGHT 30        // 按钮高度;
#define BUTTON_WIDTH 30         // 按钮宽度;
#define TITLE_HEIGHT 35         // 标题栏高度;

BaseTitleBar::BaseTitleBar(QWidget *parent)
    : QWidget(parent)
    , m_colorR(153)
    , m_colorG(153)
    , m_colorB(153)
    , m_isPressed(false)
    , m_buttonType(MIN_MAX_BUTTON)
{
    // 初始化控件;
    initControl();
    // 信号槽的绑定
    initConnections();
    //loadStyleSheet("other/qss/custom1");
}

BaseTitleBar::~BaseTitleBar()
{

}

// 初始化控件;
void BaseTitleBar::initControl()
{
    this->setProperty("form", "title");
    this->setProperty("nav", "top");

    m_pIcon = new QLabel;
    m_pTitleContent = new QLabel;

    m_pButtonMin = new QPushButton;
    m_pButtonRestore = new QPushButton;
    m_pButtonMax = new QPushButton;
    m_pButtonClose = new QPushButton;

    m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    m_pTitleContent->setObjectName("TitleContent");
    m_pButtonMin->setObjectName("ButtonMin");
    m_pButtonRestore->setObjectName("ButtonRestore");
    m_pButtonMax->setObjectName("ButtonMax");
    m_pButtonClose->setObjectName("ButtonClose");

    m_pButtonMin->setFont(QtAwesome::getInstance()->font(20));
    m_pButtonMin->setText(QChar(0xF068));
    m_pButtonMax->setFont(QtAwesome::getInstance()->font(20));
    m_pButtonMax->setText( QChar(0xf096));
    m_pButtonClose->setFont(QtAwesome::getInstance()->font(20));
    m_pButtonClose->setText(QChar(0xF00d));


    lab_Ico = new QLabel;
    lab_Title = new QLabel;

    btnMenu = new QPushButton;
    btnMenu_Max = new QPushButton;
    btnMenu_Min = new QPushButton;
    btnMenu_Close = new QPushButton;

    btnMenu->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    btnMenu_Max->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    btnMenu_Min->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    btnMenu_Close->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    lab_Title->setObjectName("TitleContent");
    btnMenu->setObjectName("ButtonMenu");
    btnMenu_Max->setObjectName("ButtonMenuMax");
    btnMenu_Min->setObjectName("ButtonMenuMin");
    btnMenu_Close->setObjectName("ButtonMenuClose");

    btnMenu_Min->setFont(QtAwesome::getInstance()->font(20));
    btnMenu_Min->setText(QChar(0xF068));
    btnMenu_Max->setFont(QtAwesome::getInstance()->font(20));
    btnMenu_Max->setText( QChar(0xf096));
    btnMenu_Close->setFont(QtAwesome::getInstance()->font(20));
    btnMenu_Close->setText(QChar(0xF00d));

    QHBoxLayout* mylayout = new QHBoxLayout(this);
    mylayout->addWidget(m_pIcon);
    mylayout->addWidget(m_pTitleContent);

    //mylayout->addWidget(m_pButtonRestore);
    mylayout->addWidget(m_pButtonMin);
    mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_pButtonClose);

//    mylayout->addWidget(lab_Ico);
//    mylayout->addWidget(lab_Title);

//    mylayout->addWidget(btnMenu);
//    mylayout->addWidget(btnMenu_Min);
//    mylayout->addWidget(btnMenu_Max);
//    mylayout->addWidget(btnMenu_Close);

    mylayout->setContentsMargins(0, 0, 0, 0);
    mylayout->setSpacing(0);

    m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setFixedHeight(TITLE_HEIGHT);
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    location = this->geometry();
    max = false;
    mousePressed = false;
}

// 信号槽的绑定;
void BaseTitleBar::initConnections()
{
    //connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
    connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}
// 设置标题栏背景色,在paintEvent事件中进行绘制标题栏背景色;
//在构造函数中给了默认值，可以外部设置颜色值改变标题栏背景色;
void BaseTitleBar::setBackgroundColor(int r, int g, int b)
{
    m_colorR = r;
    m_colorG = g;
    m_colorB = b;
    // 重新绘制（调用paintEvent事件）;
    update();
}

// 设置标题栏图标;
void BaseTitleBar::setTitleIcon(QString filePath)
{
    QPixmap titleIcon(filePath);
    m_pIcon->setPixmap(titleIcon.scaled(25 , 25));
}

// 设置标题内容;
void BaseTitleBar::setTitleContent(QString titleContent)
{
    m_pTitleContent->setText(titleContent);
    m_titleContent = titleContent;
}

// 设置标题栏长度;
void BaseTitleBar::setTitleWidth(int width)
{
    this->setFixedWidth(width);
}

// 设置标题栏上按钮类型;
// 由于不同窗口标题栏上的按钮都不一样，所以可以自定义标题栏中的按钮;
// 这里提供了四个按钮，分别为最小化、还原、最大化、关闭按钮，如果需要其他按钮可自行添加设置;
void BaseTitleBar::setButtonType(ButtonType buttonType)
{
    m_buttonType = buttonType;

    switch (buttonType)
    {
    case MIN_BUTTON:
        {
            m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
        }
        break;
    case MIN_MAX_BUTTON:
        {
            m_pButtonRestore->setVisible(false);
        }
        break;
    case ONLY_CLOSE_BUTTON:
        {
            m_pButtonMin->setVisible(false);
            m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
        }
        break;
    default:
        break;
    }
}

// 设置标题栏中的标题是否会自动滚动，跑马灯的效果;
// 一般情况下标题栏中的标题内容是不滚动的，但是既然自定义就看自己需要嘛，想怎么设计就怎么搞O(∩_∩)O！
void BaseTitleBar::setTitleRoll()
{
    connect(&m_titleRollTimer, SIGNAL(timeout()), this, SLOT(onRollTitle()));
    m_titleRollTimer.start(200);
}

// 保存窗口最大化前窗口的位置以及大小;
void BaseTitleBar::saveRestoreInfo(const QPoint point, const QSize size)
{
    m_restorePos = point;
    m_restoreSize = size;
}

// 获取窗口最大化前窗口的位置以及大小;
void BaseTitleBar::getRestoreInfo(QPoint& point, QSize& size)
{
    point = m_restorePos;
    size = m_restoreSize;
}

// 绘制标题栏背景色;
void BaseTitleBar::paintEvent(QPaintEvent *event)
{
    //设置背景色;
//    QPainter painter(this);
//    QPainterPath pathBack;
//    pathBack.setFillRule(Qt::WindingFill);
//    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
//    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
//    painter.fillPath(pathBack, QBrush(QColor(m_colorR, m_colorG, m_colorB)));

    // 当窗口最大化或者还原后，窗口长度变了，标题栏的长度应当一起改变;
    if (this->width() != this->parentWidget()->width())
    {
        this->setFixedWidth(this->parentWidget()->width());
    }
    QWidget::paintEvent(event);
}

// 加载本地样式文件;
// 可以将样式直接写在文件中，程序运行时直接加载进来;
void BaseTitleBar::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/" + sheetName + ".css");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}
// 以下为按钮操作响应的槽;
void BaseTitleBar::onButtonMinClicked()
{
    emit signalButtonMinClicked();
}

void BaseTitleBar::onButtonRestoreClicked()
{
    m_pButtonRestore->setVisible(false);
    m_pButtonMax->setVisible(true);
    emit signalButtonRestoreClicked();
}

void BaseTitleBar::onButtonMaxClicked()
{
    m_pButtonMax->setVisible(false);
    m_pButtonRestore->setVisible(true);
    emit signalButtonMaxClicked();
}

void BaseTitleBar::onButtonCloseClicked()
{
    emit signalButtonCloseClicked();
}

// 该方法主要是让标题栏中的标题显示为滚动的效果;
void BaseTitleBar::onRollTitle()
{
    static int nPos = 0;
    QString titleContent = m_titleContent;
    // 当截取的位置比字符串长时，从头开始;
    if (nPos > titleContent.length())
        nPos = 0;

    m_pTitleContent->setText(titleContent.mid(nPos));
    nPos++;
}





bool BaseTitleBar::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->on_btnMenu_Max_clicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}



void BaseTitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isPressed = true;
        mousePoint = event->globalPos() - this->pos();
        event->accept();
    }
}
//鼠标移动
void BaseTitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed && (event->buttons() && Qt::LeftButton) && !max) {
        this->move(event->globalPos() - mousePoint);

        QPoint movePoint=event->globalPos()-mousePoint;
        QPoint widgetPos=this->parentWidget()->pos();
        this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
        event->accept();
    }
    return QWidget::mouseMoveEvent(event);
}
//鼠标释放
void BaseTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;
    return QWidget::mouseReleaseEvent(event);
}






void BaseTitleBar::on_btnMenu_Close_clicked()
{
    //qApp->exit();
}

void BaseTitleBar::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        btnMenu_Max->setFont(QtAwesome::getInstance()->font(20));
        btnMenu_Max->setText( QChar(0xf096));
        btnMenu_Max->setToolTip("最大化");
    } else {
        location = this->geometry();
        //this->setGeometry(qApp->desktop()->availableGeometry());
        btnMenu_Max->setFont(QtAwesome::getInstance()->font(20));
        btnMenu_Max->setText( QChar(0xf079));
        btnMenu_Max->setToolTip("还原");
    }
    max = !max;
}

void BaseTitleBar::on_btnMenu_Min_clicked()
{
    this->showMinimized();
}
