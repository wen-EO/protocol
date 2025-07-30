#ifndef MYWIZARD_H
#define MYWIZARD_H

#include <QWizard>
#include <QWizardPage>
#include <QRadioButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QPixmap>
#include <QHBoxLayout>

class MyWizard : public QWizard
{
    Q_OBJECT
public:
    explicit MyWizard(QWidget *parent = 0);
    QWizardPage *createFirstPage();
    QWizardPage *createSecondPage();
    QWizardPage *createThirdPage();
    QWizardPage *createOutPage();

//    static bool IsProjectOpen;
//    static QString CurProjectId;
//    static QString CurProjectName;
//    static int CurProjectStationNum;
//    static QString CurProjectPath;
//    static int CurTabPosition;

private:
    QLabel *lbl_ProjectName;
    QLineEdit *edt_ProjectName;
    QLabel *lblStationNum;
    QLineEdit *edt_StationNum;
    QLabel *lbl_ProjectDescription;
    QTextEdit *edt_ProjectDescription;

//    QRadioButton *rbtn_Windows;
//    QRadioButton *rbtn_Linux;
    QCheckBox *chk_Windows;
    QCheckBox *chk_Linux;
    QCheckBox *chk_containSource;

    QLabel *lbl_TabsPos;
    QComboBox *cbx_TabsPos;
    QLabel *lbl_TopLeftCorner;
    QComboBox *cbx_TopLeftCorner;
    QLabel *lbl_TopRightCorner;
    QComboBox *cbx_TopRightCorner;
    QLabel *lbl_BottomRightCorner;
    QComboBox *cbx_BottomRightCorner;
    QLabel *lbl_BottomLeftCorner;
    QComboBox *cbx_BottomLeftCorner;
    QLabel *lbl_StyleSheet;
    QComboBox *cbx_StyleSheet;
    QLabel *lbl_CenterType;
    QComboBox *cbx_CenterType;

    QLabel *lbl_ProjectPath;
    QLineEdit *edt_ProjectPath;
    QPushButton *btn_SelectPath;
signals:

private slots:
    void on_pushButton_selectPath_clicked();
    void on_wizard_finishButton_clicked();
    bool validateCurrentPage();
    bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);
};

#endif // MYWIZARD_H
