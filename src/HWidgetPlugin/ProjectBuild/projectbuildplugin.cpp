#include "projectbuild.h"
#include "projectbuildplugin.h"

#include "hdefine.h"
ProjectBuildPlugin ::ProjectBuildPlugin (QObject *parent) :
    QObject(parent)
{

}

QString ProjectBuildPlugin ::getPluName() const
{
    QString pluName = tr("ProjectBuild");
    return pluName;
}

QIcon ProjectBuildPlugin ::icon() const
{
    return QIcon("");
}

int ProjectBuildPlugin ::windowType() const
{
    return HDefine::H_UI_PRO;
}

QWidget *ProjectBuildPlugin ::createWindow(QWidget *parent) const
{

    ProjectBuild *window = new ProjectBuild(parent);
    return  window;
}
