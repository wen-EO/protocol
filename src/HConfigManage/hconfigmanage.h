#ifndef HCONFIGMANAGE_H
#define HCONFIGMANAGE_H

#include"hwidgetdefine.h"
#include <QObject>

class Q_DECL_EXPORT HConfigManage : public QObject
{
    Q_OBJECT
private:
    explicit HConfigManage(QObject *parent=NULL);
    ~HConfigManage();
    static HConfigManage * m_instance;
public:
    static HConfigManage* getInstance();

    QString getAbsolutePath(const QString relativePath) const;

    bool IsProjectOpen;
    bool IsNewProject;
    QString CurProjectId;
    QString CurProjectName;
    int CurStationNum;
    QString CurProjectPath;
    int CurTabPosition;

    QString mySQLIP;
    int mySQLPort;
    QString mySQLDbName;
    QString mySQLUser;
    QString mySQLPwd;

    std::list<hWidget_plu_info *> m_wndList;
    std::list<category_info *> m_categoryList;

public:
    class CGarbo
    {
    public:

        ~CGarbo()
        {
            if (m_instance != NULL)

            {
                delete m_instance;
                m_instance = NULL;
            }
        }

    };
    static CGarbo Garbo;

    Q_DISABLE_COPY(HConfigManage)
};

#endif // HCONFIGMANAGE_H
