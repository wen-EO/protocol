#include "hwindowapi.h"
#include "qevent.h"
#include"qwidget.h"
#include"qdesktopwidget.h"
#include"qapplication.h"

#include "BasicIdlType.h"
HWindowApi* HWindowApi::m_instance = NULL;
HWindowApi::CGarbo HWindowApi::Garbo;
HWindowApi::HWindowApi(QObject *parent) : QObject(parent)
{
    getScreenWH();
}

HWindowApi::~HWindowApi()
{

}

HWindowApi *HWindowApi::getInstance()
{
    if(m_instance == NULL)
    {
        m_instance = new HWindowApi;
        return m_instance;
    }
    else
    {
        return m_instance;
    }
}
void HWindowApi::getScreenWH()
{
    QDesktopWidget *_desktop = QApplication::desktop();
    //获取屏幕0的宽/高
    QRect rect = _desktop->screenGeometry(0);
    screenWidth = rect.width();
    screenHeight = rect.height();
}

bool HWindowApi::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *w = (QWidget *)obj;
    if (!w->property("canMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - w->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
            mousePressed = false;
            return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            w->move(event->globalPos() - mousePoint);
            return true;
        }
    }
    return QObject::eventFilter(obj, evt);
}
