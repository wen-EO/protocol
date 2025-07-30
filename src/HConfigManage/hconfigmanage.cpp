#include "hconfigmanage.h"
#include"qapplication.h"
HConfigManage* HConfigManage::m_instance = NULL;
HConfigManage::CGarbo HConfigManage::Garbo;

//bool HConfigManage::IsProjectOpen=false;
//bool HConfigManage::IsNewProject=true;
//QString HConfigManage::CurProjectId="";
//QString HConfigManage::CurProjectName="";
//int HConfigManage::CurProjectStationNum=0;
//QString HConfigManage::CurProjectPath="";
//int HConfigManage::CurTabPosition=0;

HConfigManage::HConfigManage(QObject *parent) : QObject(parent),
    IsProjectOpen(false), IsNewProject(true), CurProjectId(""), CurProjectName(""), CurStationNum(0), CurProjectPath(""), CurTabPosition(0),
    mySQLIP(""),mySQLPort(3306),mySQLDbName(""), mySQLUser(""), mySQLPwd("")
{

}

HConfigManage::~HConfigManage()
{

}

HConfigManage *HConfigManage::getInstance()
{
    if(m_instance==NULL)
    {
        m_instance = new HConfigManage();
        return m_instance;
    }
    else
    {
        return m_instance;
    }
}

QString HConfigManage::getAbsolutePath(const QString relativePath) const
{
    QString dir = QApplication::applicationDirPath();
    QString dirPath = dir.mid(0,dir.size() - 4);
    dirPath += relativePath;
    return dirPath;
}
