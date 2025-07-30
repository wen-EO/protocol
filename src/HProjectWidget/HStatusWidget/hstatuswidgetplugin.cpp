#include "hstatuswidget.h"
#include "hstatuswidgetplugin.h"

#include "hdefine.h"
HStatusWidgetPlugin ::HStatusWidgetPlugin (QObject *parent) :
    QObject(parent)
{

}

QString HStatusWidgetPlugin ::getPluName() const
{
    QString pluName = tr("statusWidget");
    return pluName;
}

QIcon HStatusWidgetPlugin ::icon() const
{
    return QIcon("");
}

int HStatusWidgetPlugin ::windowType() const
{
    return HDefine::H_UI_PRO;
}

QWidget *HStatusWidgetPlugin ::createWindow(QWidget *parent) const
{
   // LayoutWindow *window=new LayoutWindow(parent);
   // window->initQss();
    HStatusWidget *window = new HStatusWidget(parent);
    return  window;
}
