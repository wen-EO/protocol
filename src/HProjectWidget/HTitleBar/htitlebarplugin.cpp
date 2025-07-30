#include "htitlebar.h"
#include "htitlebarplugin.h"

#include "hdefine.h"
HTitlebarPlugin ::HTitlebarPlugin (QObject *parent) :
    QObject(parent)
{

}

QString HTitlebarPlugin ::getPluName() const
{
    QString pluName = tr("titleBar");
    return pluName;
}

QIcon HTitlebarPlugin ::icon() const
{
    return QIcon("");
}

int HTitlebarPlugin ::windowType() const
{
    return HDefine::H_UI_PRO;
}

QWidget *HTitlebarPlugin ::createWindow(QWidget *parent) const
{
   // LayoutWindow *window=new LayoutWindow(parent);
   // window->initQss();
    HTitleBar *window = new HTitleBar(parent);
    return  window;
}
