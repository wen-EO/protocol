#ifndef HWIDGETLIBRARY_H
#define HWIDGETLIBRARY_H

#include <QObject>
#include"hwidgetdefine.h"
#include"hwidgetinterface.h"
#include<QMap>

class QPluginLoader;
class Q_DECL_EXPORT HWidgetLibrary : public QObject
{
   Q_OBJECT

private:
    explicit HWidgetLibrary();
    ~HWidgetLibrary();
public:
    static HWidgetLibrary* getInstance();

public:

    std::list<hWidget_plu_info *> m_wndList;

public:

    /**
     * @brief  getPluWindow     : 获取插件窗口接口.
     * @param  pluName          : 插件名称.
     * @param  wndList          : 创建插件指针对象链表.
     * @param  parent           : 插件窗口父窗口对象指针.
     */
    std::list<hWidget_plu_info *> getPluWindow();


    QStringList scan(QString filePath);
private:
    //存储所有控件插件的Hash表.
    QMap<QString,HWidgetPluginInterface *> m_windows;
    QMap<QString,HWidgetPluginInterface *>::iterator pluItem;

    //所有插件对象Hash链表.
    QList<QPluginLoader *> m_pluHash;

private:
    void loadWindowInfo();

private:
    //控件仓库对象单例指针.
    static HWidgetLibrary* _pInstance;

private:

    /**
     * @brief  loadWidgetPlugin : 加载工具功能插件接口.
     * @return 0                : 所有工具控件插件加载成功.
     * @return !0               : 某些工具控件插件加载失败.
     */
    int loadWidnowPlugin(QString path);

    /**
     * @brief  loadWidgetPlugin : 加载工具功能插件接口.
     * @return QVT_RET_SUCCEED  : 所有工具控件插件卸载成功.
     * @return QVT_RET_FAILURE  : 某些工具控件插件卸载失败.
     */
    int unloadAllWidnowPlugin();

    /**
     * @brief  getAbsolutePath        : 获取相对Qvt工具的绝对路径.
     * @param  Dir                    : 需获得的路径目录名称.
     * @return dirPath                : 获取成功,返回拼接后的绝对路径.
     * @return ""                     : 获取路径失败.
     */
    QString getAbsolutePath(QString Dir) const;

public:
    class CGarbo
    {
    public:

        ~CGarbo()
        {
            if (_pInstance != NULL)

            {
                delete _pInstance;
                _pInstance = NULL;
            }
        }

    };
    static CGarbo Garbo;

    Q_DISABLE_COPY(HWidgetLibrary)
};


#endif // HWIDGETLIBRARY_H
