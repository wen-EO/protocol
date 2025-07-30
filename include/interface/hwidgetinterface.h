#ifndef HWIDGETINTERFACE_H
#define HWIDGETINTERFACE_H


#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtGui/QIcon>

class QWidget;

QT_BEGIN_NAMESPACE

class HWidgetPluginInterface
{
public:
    virtual ~HWidgetPluginInterface(){}
    virtual QString getPluName() const = 0;
    virtual QIcon icon() const = 0;
    virtual int windowType() const = 0;
    virtual QWidget *createWindow(QWidget *parent) const = 0;
};

#define HWidgetPluginInterface_iid "org.qt-project.HWidgetPluginInterface"

Q_DECLARE_INTERFACE(HWidgetPluginInterface, HWidgetPluginInterface_iid)

class HWidgetPluginCollectionInterface
{
public:
    virtual ~HWidgetPluginCollectionInterface(){}

    virtual QHash<QString,HWidgetPluginInterface *> customWidgets() const = 0;
};

#define HWidgetPluginCollectionInterface_iid "org.qt-project.HWidgetPluginCollectionInterface"

Q_DECLARE_INTERFACE(HWidgetPluginCollectionInterface, HWidgetPluginCollectionInterface_iid)



#endif // HWIDGETINTERFACE_H
