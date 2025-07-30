#ifndef HWINDOWAPI_H
#define HWINDOWAPI_H

#include <QObject>

struct StructInfo;
typedef QVector<StructInfo> _STRUCT_VECTOR_T;

class Q_DECL_EXPORT HWindowApi : public QObject
{
    Q_OBJECT
private:
    explicit HWindowApi(QObject *parent = 0);
    ~HWindowApi();

private:
    static HWindowApi *m_instance;
public:
    static HWindowApi* getInstance();
signals:
    void titleItemClicked(const QString &name);

    void clickTitleItem(const QString& itemName);

    void openProject(const QString& projectId);

    void refreshCatgory();

    void refreshProtocol();

    void structFileSelected(const QString&fileName,const _STRUCT_VECTOR_T& fileInfo);
protected:
    bool eventFilter(QObject *obj, QEvent *evt);

public:
   int screenWidth ;

   int screenHeight ;
private:
    void getScreenWH();

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

    Q_DISABLE_COPY(HWindowApi)
};

#endif // HWINDOWAPI_H
