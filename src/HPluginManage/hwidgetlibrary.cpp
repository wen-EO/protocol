#include "hwidgetlibrary.h"
#include "qpluginloader.h"
#include "qdebug.h"
#include "qdir.h"
#include "qfile.h"
#include "qapplication.h"

HWidgetLibrary* HWidgetLibrary::_pInstance = NULL;
HWidgetLibrary::CGarbo HWidgetLibrary::Garbo;

HWidgetLibrary::HWidgetLibrary()
{
    //加载所有窗口控件.
    loadWidnowPlugin("/bin/sysPlugin/function/");
    //加载组件库组件
    //loadWidnowPlugin("/bin/sysPlugin/demo/");
    //插件所有插件信息.
    loadWindowInfo();
}

HWidgetLibrary::~HWidgetLibrary()
{
}

HWidgetLibrary *HWidgetLibrary::getInstance()
{
    if (_pInstance == NULL)
    {
        _pInstance = new HWidgetLibrary();
    }
    return _pInstance;
}

std::list<hWidget_plu_info *>  HWidgetLibrary::getPluWindow()
{
    return m_wndList;
}
QStringList HWidgetLibrary::scan(QString filePath)
{
    int i = 0;
    //用来临时存储文件路径
    QString strFile;
    //取文件路径并给QDir类型
    QDir dir = filePath;
    //链表，存储文件路径
    QStringList fileList;
    //文件信息
    QFileInfo fileInfo;
#ifdef _WIN32
    fileList << "*.dll";
#else
    fileList << "*.so";
#endif
    //过滤文件
    dir.setNameFilters(fileList);
    //列出所有符合条件的文件
    QFileInfoList fileInfoList = dir.entryInfoList();
    fileList.clear();

    //注意：fileList.at(0) = "*.so" ,从第一个开始才是所需文件完整路径
    while(i < fileInfoList.length())
    {
        fileInfo = fileInfoList.at(i);
        strFile = fileInfo.filePath();
        fileList << strFile;
        i++;
    }
    return fileList;
}
void HWidgetLibrary::loadWindowInfo()
{
    m_wndList.clear();

    //QHash<QString,HWidgetPluginInterface *>::item
    QMap<QString,HWidgetPluginInterface *>::iterator pluItem = m_windows.begin();
    for (; pluItem != m_windows.end(); ++pluItem)
    {
        hWidget_plu_info *plu_info = new hWidget_plu_info;
        plu_info->pluName = pluItem.value()->getPluName();
        plu_info->pluIcon = pluItem.value()->icon();
        plu_info->pluType = pluItem.value()->windowType();
        plu_info->pluClass = pluItem.value();
        m_wndList.push_back(plu_info);
    }
}

int HWidgetLibrary::loadWidnowPlugin(QString path)
{
    int errorCount = 0;

    //获取plugins绝对路径.
    QString pluPath = getAbsolutePath(path);

    //获取目录下面的所有动态库(dll/.so)
    //QStringList pluList = QvtObjectApi::getInstance()->scan(pluPath);
    QStringList pluList = this->scan(pluPath);

    qDebug()<<"gggg"<<pluPath;

    //加载目录下的所有控件插件.
    foreach(QString item,pluList)
    {        
        //加载插件
        qDebug()<<"abababa"<<item;
        QPluginLoader *loder = new QPluginLoader(item);
        loder->load();
        if (loder->isLoaded())
        {
            HWidgetPluginInterface *window = dynamic_cast<HWidgetPluginInterface *>(loder->instance());
            if (window != NULL)
            {
                //将插件对象指针存储在QHash
                m_windows.insert(window->getPluName(),window);
            }else{
                QString logData = QString("Error： %1 窗口插件加载失败").arg(item);
                //QvtLogManage::getInstance()->qvtWriteLog(logData,Qvt_LEVEL_LOG_HIGH);
                errorCount++;
            }
            m_pluHash.push_back(loder);
        }else{
            //错误信息
            QString error = QString("Error： %1 窗口插件加载失败!\t\t\t\t").arg(item);
            error +=  "错误原因:" + loder->errorString();
            QString logData = error;

            //写入日志.
            //QvtLogManage::getInstance()->qvtWriteLog(logData,Qvt_LEVEL_LOG_HIGH);
            errorCount++;
        }
    }

    if (errorCount != 0)
    {
       // return QVT_LOADPLUGIN_ERROR;
    }
    return 0;
}

int HWidgetLibrary::unloadAllWidnowPlugin()
{
    foreach (QPluginLoader *pluItem, m_pluHash) {
        if (pluItem->isLoaded())
        {
            pluItem->unload();
        }
    }
   // return QVT_RET_SUCCEED;
}

QString HWidgetLibrary::getAbsolutePath(QString Dir) const
{
    QString dir = QApplication::applicationDirPath();

    qDebug()<<dir;
    QString dirPath = dir.mid(0,dir.size() - 4);

    dirPath += Dir;
    return dirPath;
}
