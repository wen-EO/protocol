#ifndef HSTATUSWIDGETPLUGIN_H
#define HSTATUSWIDGETPLUGIN_H

#include"hwidgetinterface.h"

class HStatusWidgetPlugin : public QObject , public HWidgetPluginInterface
{
    Q_OBJECT

    Q_INTERFACES(HWidgetPluginInterface)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.HWidgetPluginInterface")
#endif // QT_VERSION >= 0x050000

public:
    explicit HStatusWidgetPlugin (QObject *parent = 0);

    virtual QString getPluName() const;
    virtual QIcon icon() const;
    virtual int windowType() const;
    virtual QWidget *createWindow(QWidget *parent) const;

signals:

public slots:
};

#endif
