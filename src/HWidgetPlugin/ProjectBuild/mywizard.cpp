#include "mywizard.h"
#include "hconfigmanage.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include<QDebug>
//添加头文件
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QUuid>
#include <QDateTime>

//bool MyWizard::IsProjectOpen=false;
//QString MyWizard::CurProjectId="";
//QString MyWizard::CurProjectName="";
//int MyWizard::CurProjectStationNum=0;
//QString MyWizard::CurProjectPath="";
//int MyWizard::CurTabPosition=0;

MyWizard::MyWizard(QWidget *parent) :
    QWizard(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint);

    //去掉帮助按钮
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    //设置导航样式
    this->setWizardStyle(QWizard::ModernStyle);
    this->setWindowTitle("新建项目");
    //去掉向导页面按钮
    this->setOption(QWizard::NoBackButtonOnStartPage);//设置第一页没有上一步的按钮
    //this->setOption(QWizard::NoBackButtonOnLastPage);//设置最后一页没有上一步的按钮
    this->setOption(QWizard::NoCancelButton);//去掉取消按钮

    //---------------------------------------------------
    //在子页面中设置title一下几行才会生效
//    QPixmap pix(QSize(500, 78));
//    pix.fill(QColor(173,173,173));
//    setPixmap(QWizard::BannerPixmap,pix);

//    QIcon icon(":/new/images/infor.png");
//    setPixmap( QWizard::LogoPixmap,icon.pixmap(64));

    //---------------------------------------------------
//    this->setTitleFormat(Qt::RichText);//设置页面主标题的显示格式
//    this->setSubTitleFormat(Qt::RichText);//设置子标题显示格式

    //设置两个按钮
    this->setButtonText(QWizard::NextButton, "下一步>");
    this->setButtonText(QWizard::BackButton, "<上一步");
    this->setButtonText(QWizard::CancelButton,"取 消");
    this->setButtonText(QWizard::FinishButton,"完 成");

    //this->button(QWizard::FinishButton)->setStyleSheet("QPushButton{height:40px;width:80;background-color:rgb(218,240,251);border-style:flat;background-attachment:fixed;}");
    //给完成按钮绑定事件
    //connect(this->button(QWizard::FinishButton), SIGNAL(clicked()), this, SLOT(on_wizard_finishButton_clicked()));
}
QWizardPage *MyWizard::createFirstPage()
{
    QWizardPage *firstPage = new QWizardPage;
    firstPage->setTitle(tr("1.输入项目基本信息"));//设置第一个QWizardPage
    //firstPage->setSubTitle(tr("1.输入项目基本信息"));//设置第一个QWizardPage

    lbl_ProjectName = new QLabel;
    lbl_ProjectName->setText("项目名称（英文，如：Project）");
    edt_ProjectName=new QLineEdit(this);
    edt_ProjectName->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z]+$")));   //只能输入26个英文字母

    lblStationNum = new QLabel;
    lblStationNum->setText("台位/站位个数");
    edt_StationNum=new QLineEdit(this);
    edt_StationNum->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));   //只能输入数字

    lbl_ProjectDescription = new QLabel;
    lbl_ProjectDescription->setText("项目描述");
    edt_ProjectDescription=new QTextEdit(this);

    QGridLayout *firstLayout = new QGridLayout;
    firstLayout->addWidget(lbl_ProjectName,0,0,1,2);
    firstLayout->addWidget(edt_ProjectName,1,0,1,2);
    firstLayout->addWidget(lblStationNum,2,0,1,2);
    firstLayout->addWidget(edt_StationNum,3,0,1,2);
    firstLayout->addWidget(lbl_ProjectDescription,4,0,1,2);
    firstLayout->addWidget(edt_ProjectDescription,5,0,1,2);

    firstPage->setLayout(firstLayout);

//    firstPage->setButtonText(QWizard::BackButton,"上一步");
//    firstPage->setButtonText(QWizard::NextButton,"下一步");//为next设置一个中文的名字
//    firstPage->setButtonText(QWizard::CancelButton,"取消");
//    firstPage->setButtonText(QWizard::FinishButton,"完成");
    return firstPage;
}
QWizardPage *MyWizard::createSecondPage()
{
    QWizardPage *secondPage = new QWizardPage;
    secondPage->setTitle(tr("2.选择项目开发平台"));

//    rbtn_Windows=new QRadioButton("Windows",this);
//    rbtn_Windows->setChecked(true);
//    rbtn_Linux =new QRadioButton("Linux",this);

    chk_Windows=new QCheckBox("Windows平台",this);
    chk_Linux=new QCheckBox("Linux平台",this);

    chk_containSource=new QCheckBox("是否包含主框架库源码",this);

    QGridLayout *secondLayout = new QGridLayout;
    secondLayout->addWidget(chk_Windows);
    secondLayout->addWidget(chk_Linux);
    secondLayout->addWidget(chk_containSource);
    secondPage->setLayout(secondLayout);

//    secondPage->setButtonText(QWizard::BackButton,"上一步");
//    secondPage->setButtonText(QWizard::NextButton,"下一步");//为next设置一个中文的名字
//    secondPage->setButtonText(QWizard::CancelButton,"取消");
//    secondPage->setButtonText(QWizard::FinishButton,"完成");
    return secondPage;
}
QWizardPage *MyWizard::createThirdPage()
{
    QWizardPage *thirdPage = new QWizardPage;
    thirdPage->setTitle(tr("3.设置显控显示样式"));

    lbl_TabsPos = new QLabel;
    lbl_TabsPos->setText("停靠窗tab的显示方向");
    cbx_TabsPos=new QComboBox(this);
    QStringList strList_TabsPos;
    strList_TabsPos<<" 0-上"<<" 1-下"<<" 3-左"<<" 4-右";
    cbx_TabsPos->addItems(strList_TabsPos);

    lbl_TopLeftCorner= new QLabel;
    lbl_TopLeftCorner->setText("窗口左上角归属");
    cbx_TopLeftCorner=new QComboBox(this);
    QStringList strList_TopLeftCorner;
    strList_TopLeftCorner<<"true:顶部停靠窗"<<"false:左侧停靠窗";
    cbx_TopLeftCorner->addItems(strList_TopLeftCorner);

    lbl_TopRightCorner= new QLabel;
    lbl_TopRightCorner->setText("窗口右上角归属");
    cbx_TopRightCorner=new QComboBox(this);
    QStringList strList_TopRightCorner;
    strList_TopRightCorner<<"true:顶部停靠窗"<<"false:右侧停靠窗";
    cbx_TopRightCorner->addItems(strList_TopRightCorner);

    lbl_BottomRightCorner= new QLabel;
    lbl_BottomRightCorner->setText("窗口左下角归属");
    cbx_BottomRightCorner=new QComboBox(this);
    QStringList strList_BottomRightCorner;
    strList_BottomRightCorner<<"true:底侧停靠窗"<<"false:左侧停靠窗";
    cbx_BottomRightCorner->addItems(strList_BottomRightCorner);

    lbl_BottomLeftCorner= new QLabel;
    lbl_BottomLeftCorner->setText("窗口右下角归属");
    cbx_BottomLeftCorner=new QComboBox(this);
    QStringList strList_BottomLeftCorner;
    strList_BottomLeftCorner<<"true:底侧停靠窗"<<"false:右侧停靠窗";
    cbx_BottomLeftCorner->addItems(strList_BottomLeftCorner);

    lbl_StyleSheet = new QLabel;
    lbl_StyleSheet->setText("显控整体样式");
    cbx_StyleSheet=new QComboBox(this);
    QStringList strList_Qss;
    //strList_Qss<<"显控样式1"<<"显控样式2";
    //QDir dir("E:\\CProject\\proconfig\\bin\\StyleSheet\\");

    //QDir dir(QDir::currentPath()+"\\StyleSheet\\");
    QDir dir(QDir::currentPath()+"\\Project\\MainFrame\\data\\qss\\");
    QStringList nameFilters;
    nameFilters << "*.qss";
    strList_Qss = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    cbx_StyleSheet->addItems(strList_Qss);

    lbl_CenterType = new QLabel;
    lbl_CenterType->setText("中心叠放方式");
    cbx_CenterType=new QComboBox(this);
    QStringList strList_Stack;
    strList_Stack<<"0-堆叠"<<"1-tab页叠放";
    cbx_CenterType->addItems(strList_Stack);

    QGridLayout *thirdLayout = new QGridLayout;
    thirdLayout->addWidget(lbl_TabsPos,0,0,1,4);
    thirdLayout->addWidget(cbx_TabsPos,1,0,1,4);

    thirdLayout->addWidget(lbl_TopLeftCorner,2,0,1,4);
    thirdLayout->addWidget(cbx_TopLeftCorner,3,0,1,4);

    thirdLayout->addWidget(lbl_TopRightCorner,4,0,1,4);
    thirdLayout->addWidget(cbx_TopRightCorner,5,0,1,4);

    thirdLayout->addWidget(lbl_BottomRightCorner,6,0,1,4);
    thirdLayout->addWidget(cbx_BottomRightCorner,7,0,1,4);

    thirdLayout->addWidget(lbl_BottomLeftCorner,8,0,1,4);
    thirdLayout->addWidget(cbx_BottomLeftCorner,9,0,1,4);

    thirdLayout->addWidget(lbl_StyleSheet,10,0,1,4);
    thirdLayout->addWidget(cbx_StyleSheet,11,0,1,4);

    thirdLayout->addWidget(lbl_CenterType,12,0,1,4);
    thirdLayout->addWidget(cbx_CenterType,13,0,1,4);
    thirdPage->setLayout(thirdLayout);

//    thirdPage->setButtonText(QWizard::NextButton,"下一步");
//    thirdPage->setButtonText(QWizard::BackButton,"上一步");
//    thirdPage->setButtonText(QWizard::CancelButton,"取消");
//    thirdPage->setButtonText(QWizard::FinishButton,"完成");
    return thirdPage;
}
QWizardPage *MyWizard::createOutPage()
{
    QWizardPage *outPage = new QWizardPage;
    outPage->setTitle(tr("4.项目生成位置路径"));//设置第一个QWizardPage

    lbl_ProjectPath = new QLabel;
    lbl_ProjectPath->setText("生成位置路径");
    edt_ProjectPath=new QLineEdit(this);
    edt_ProjectPath->setReadOnly(true);
    btn_SelectPath=new QPushButton("选择路径",this);
    connect(btn_SelectPath, SIGNAL(clicked()), this, SLOT(on_pushButton_selectPath_clicked()));
//    connect(btn_SelectPath, &QPushButton::clicked,[edt_ProjectPath](){
//        //文件夹路径
//        QString dirPath = QFileDialog::getExistingDirectory(nullptr, "选择项目生成位置路径","/");
//        if (!dirPath.isEmpty())
//        {
//            edt_ProjectPath->setText(dirPath);
//        }
//    });

    QGridLayout *outLayout = new QGridLayout;
    outLayout->addWidget(lbl_ProjectPath,0,0,1,2);
    outLayout->addWidget(edt_ProjectPath,1,0,1,1);
    outLayout->addWidget(btn_SelectPath,1,1,1,1);
    outPage->setLayout(outLayout);

//    outPage->setButtonText(QWizard::BackButton,"上一步");
//    outPage->setButtonText(QWizard::NextButton,"下一步");
//    outPage->setButtonText(QWizard::CancelButton,"取消");
//    outPage->setButtonText(QWizard::FinishButton,"完成");    
    return outPage;
}
void MyWizard::on_pushButton_selectPath_clicked(){
    //文件夹路径
    QString dirPath = QFileDialog::getExistingDirectory(nullptr, "选择项目生成位置路径","/");
    if (!dirPath.isEmpty())
    {
        edt_ProjectPath->setText(dirPath);
    }
}
bool MyWizard::validateCurrentPage()
{
    bool result=true;
    //qDebug()<< this->currentPage()->nextId();
    if(-1 == this->currentPage()->nextId())//这是 finish按钮时的情况
    {
        //检查必填项
        if (edt_ProjectName->text().isEmpty())
        {
            QMessageBox::warning(this,"警告","请输入项目名称！");
            return false;
        }
        if (edt_StationNum->text().isEmpty())
        {
            QMessageBox::warning(this,"警告","请输入台位/战位个数！");
            return false;
        }
        if (edt_StationNum->text()=="0")
        {
            QMessageBox::warning(this,"警告","台位/战位个数必须大于0！");
            return false;
        }
        if(!chk_Windows->isChecked() && !chk_Windows->isChecked())
        {
            QMessageBox::warning(this,"警告","请选择项目开发平台！");
            return false;
        }
        if (edt_ProjectPath->text().isEmpty())
        {
            QMessageBox::warning(this,"警告","请选择项目生成位置路径！");
            return false;
        }

        //建立并打开数据库，将项目信息写入数据库
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("sysdata.db");
        if (!database.open())
        {
            qDebug() << "Error: Failed to connect database." << database.lastError();
            QMessageBox::warning(this,"警告","项目创建失败！");
            result=false;
        }
        else
        {
            //qDebug() << "Succeed to connect database." ;
            //插入数据
            QSqlQuery sql_query;
            QUuid id = QUuid::createUuid();
            QString strId = id.toString().replace("{","").replace("}","");
            HConfigManage::getInstance()->CurProjectId=strId;
            QString create_time =QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            QString strName=this->edt_ProjectName->text();
            QString strStationNum=this->edt_StationNum->text();
            QString strPositionNum=this->edt_StationNum->text();
            QString strDescription=this->edt_ProjectDescription->toPlainText();
            int strWindows=this->chk_Windows->isChecked()?1:0;
            int strLinux=this->chk_Linux->isChecked()?1:0;
            int strContainSource=this->chk_containSource->isChecked()?1:0;
            int strTabsPos=this->cbx_TabsPos->currentIndex();
            int strCenterType=this->cbx_CenterType->currentIndex();
            int strTopLeftCorner=this->cbx_TopLeftCorner->currentIndex()==0?1:0;
            int strTopRightCorner=this->cbx_TopRightCorner->currentIndex()==0?1:0;
            int strBottomLeftCorner=this->cbx_BottomLeftCorner->currentIndex()==0?1:0;
            int strBottomRightCorner=this->cbx_BottomRightCorner->currentIndex()==0?1:0;
            QString strStyleSheet=this->cbx_StyleSheet->currentText();

            QString strSQL=QString("insert into project_entity(id,create_time,description,name,stationnum,positionnum,windows,linux,containsource,tabspos,centertype,topleftcorner,toprightcorner,bottomleftcorner,bottomrightcorner,stylesheet) values("
                           "'%1','%2','%3','%4',%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,'%16')").arg(strId).arg(create_time).arg(strDescription).arg(strName).arg(strStationNum).arg(strPositionNum).arg(strWindows).arg(strLinux).arg(strContainSource)
                    .arg(strTabsPos).arg(strCenterType).arg(strTopLeftCorner).arg(strTopRightCorner).arg(strBottomLeftCorner).arg(strBottomRightCorner).arg(strStyleSheet);

            //qDebug() << strSQL;
            if(!sql_query.exec(strSQL))
            {
                qDebug() << sql_query.lastError();
                qDebug() << "Error: Failed to insert database." << database.lastError();
                QMessageBox::warning(this,"警告","项目创建失败！");
                return false;
            }
            result=true;
        }
        database.close();

        //return result;

        //创建项目目录
        QDir dir;
        QString projectPath=this->edt_ProjectPath->text();
        QString projectName=this->edt_ProjectName->text();
        QString rootPath = projectPath+"\\"+projectName;
        dir.setPath(rootPath);
        //如果目录已存在，则删除该目录
        dir.removeRecursively();
        //在指定路径建立项目目录Project
        if(dir.mkdir(rootPath))
        {
            //在指定路径建立项目目录MainFrame
            if(dir.mkdir(rootPath+"\\MainFrame"))
            {
                //放入主框架代码目录Project/MainFrame
                if(copyDirectoryFiles(QDir::currentPath()+"\\Project\\MainFrame",rootPath+"\\MainFrame",true))
                {
                    //放入Project/DC.pro，并更名为Project.pro
                    if(copyFileToPath(QDir::currentPath()+"\\Project\\DC.pro",rootPath+"\\"+projectName+".pro",true))
                    {
                        //放入第三方库目录Project/3rdParty
                        if(dir.mkdir(rootPath+"\\3rdParty"))
                        {
                            if(dir.mkdir(rootPath+"\\3rdParty\\include"))
                            {
                               //存放第三方库需要引用的头文件
                               copyDirectoryFiles(QDir::currentPath()+"\\Project\\3rdParty\\include",rootPath+"\\3rdParty\\include",true);
                            }
                            if(this->chk_Windows->isChecked())
                            {
                                if(dir.mkdir(rootPath+"\\3rdParty\\lib"))
                                {
                                   //存放Windows操作系统第三方库文件
                                   copyDirectoryFiles(QDir::currentPath()+"\\Project\\3rdParty\\lib",rootPath+"\\3rdParty\\lib",true);
                                }
                            }
                            if(this->chk_Linux->isChecked())
                            {
                                if(dir.mkdir(rootPath+"\\3rdParty\\so"))
                                {
                                   //存放Linux操作系统第三方库文件
                                   copyDirectoryFiles(QDir::currentPath()+"\\Project\\3rdParty\\so",rootPath+"\\3rdParty\\so",true);
                                }
                            }
                        }
                        //放入主框架库源码目录Project/libs
                        if(this->chk_containSource->isChecked())
                        {
                            if(dir.mkdir(rootPath+"\\libs"))
                            {
                               //存放Windows操作系统第三方库文件
                               copyDirectoryFiles(QDir::currentPath()+"\\Project\\libs",rootPath+"\\libs",true);
                            }
                        }
                        //显控软件配置文件目录
                        QString configFileName=rootPath+"\\MainFrame\\config\\mainframe.ini";
                        QSettings *configIniWrite = new QSettings(configFileName,QSettings::IniFormat);
                        //写入Dock布局配置
                        configIniWrite->setValue("/Dock/BottomRightCorner",this->cbx_BottomRightCorner->currentIndex()==0?true:false);
                        configIniWrite->setValue("/Dock/BottomLeftCorner",this->cbx_BottomLeftCorner->currentIndex()==0?true:false);
                        configIniWrite->setValue("/Dock/TopLeftCorner",this->cbx_TopLeftCorner->currentIndex()==0?true:false);
                        configIniWrite->setValue("/Dock/TopRightCorner",this->cbx_TopRightCorner->currentIndex()==0?true:false);
                        configIniWrite->setValue("/Dock/TabsPos",this->cbx_TabsPos->currentIndex());
                        configIniWrite->setValue("/Dock/CenterType",this->cbx_CenterType->currentIndex());
                        //写入台位/战位配置
                        configIniWrite->setValue("/Station/StationNum",this->edt_StationNum->text());
                        configIniWrite->setValue("/INIT/PositionNum",this->edt_StationNum->text());
                        //写入显示样式配置
                        configIniWrite->setValue("/Palette/StyleSheet",this->cbx_StyleSheet->currentText());

                        //全局变量记录当前项目信息
//                        this->IsProjectOpen=true;
//                        this->CurProjectName=edt_ProjectName->text();
//                        this->CurStationNum=edt_StationNum->text().toInt();
//                        this->CurProjectPath=edt_ProjectPath->text();
//                        this->CurTabPosition=cbx_TabsPos->currentIndex();

                        HConfigManage::getInstance()->IsProjectOpen=true;
                        HConfigManage::getInstance()->IsNewProject=true;
                        HConfigManage::getInstance()->CurProjectName=edt_ProjectName->text();
                        HConfigManage::getInstance()->CurStationNum=edt_StationNum->text().toInt();
                        HConfigManage::getInstance()->CurProjectPath=edt_ProjectPath->text();
                        HConfigManage::getInstance()->CurTabPosition=cbx_TabsPos->currentIndex();

                        QMessageBox::information(this,"提示","项目创建成功！");
                    }
                }
            }
        }


    }
    return result;
}
void MyWizard::on_wizard_finishButton_clicked(){    
    //检查必填项
    if (edt_ProjectName->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","请输入项目名称！");
        return;
    }
    if (edt_StationNum->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","请输入台位/战位个数！");
        return;
    }
    if (edt_StationNum->text()=="0")
    {
        QMessageBox::warning(this,"警告","台位/战位个数必须大于0！");
        return;
    }
    if(!chk_Windows->isChecked() && !chk_Windows->isChecked())
    {
        QMessageBox::warning(this,"警告","请选择项目开发平台！");
        return;
    }
    if (edt_ProjectPath->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择项目生成位置路径！");
        return;
    }
    //创建项目目录
    QDir dir;
    QString rootPath = edt_ProjectPath->text()+"\\Project";
    dir.setPath(rootPath);
    //如果目录不为空，则删除该目录
    dir.removeRecursively();
    //开始创建目录
    if(dir.mkdir(rootPath))
    {
        if(dir.mkdir(rootPath+"\\MainFrame"))
        {
            //主框架程序目录
            if(dir.mkdir(rootPath+"\\MainFrame\\bin"))
            {
                //显控软件可执行文件目录
            }
            if(dir.mkdir(rootPath+"\\MainFrame\\config"))
            {
                //显控软件配置文件目录
                QString configFileName=rootPath+"\\MainFrame\\config\\mainframe.ini";
                //INI_File(configFileName).SetStationNum(this->edt_StationNum->text());
                //INI_File(configFileName).SetPositionNum(this->edt_StationNum->text());

                QSettings *configIniWrite = new QSettings(configFileName,QSettings::IniFormat);
                //写入Dock布局配置
                configIniWrite->setValue("/Dock/BottomRightCorner",this->cbx_BottomRightCorner->currentIndex()==0?true:false);
                configIniWrite->setValue("/Dock/BottomLeftCorner",this->cbx_BottomLeftCorner->currentIndex()==0?true:false);
                configIniWrite->setValue("/Dock/TopLeftCorner",this->cbx_TopLeftCorner->currentIndex()==0?true:false);
                configIniWrite->setValue("/Dock/TopRightCorner",this->cbx_TopRightCorner->currentIndex()==0?true:false);
                configIniWrite->setValue("/Dock/TabsPos",this->cbx_TabsPos->currentIndex());
                configIniWrite->setValue("/Dock/CenterType",this->cbx_CenterType->currentIndex());
                //写入台位/战位配置
                configIniWrite->setValue("/Station/StationNum",this->edt_StationNum->text());
                configIniWrite->setValue("/INIT/PositionNum",this->edt_StationNum->text());
                //写入显示样式配置
                configIniWrite->setValue("/Palette/StyleSheet",this->cbx_StyleSheet->currentText());
            }
        }

        if(dir.mkdir(rootPath+"\\libs"))
        {
            //保存主框架库源码的目录和文件
        }

        if(dir.mkdir(rootPath+"\\3rdParty"))
        {
            if(dir.mkdir(rootPath+"\\3rdParty\\include"))
            {
                //存放第三方库需要引用的头文件
            }
            if(this->chk_Windows->isChecked())
            {
                if(dir.mkdir(rootPath+"\\3rdParty\\lib"))
                {
                    //存放Windows操作系统第三方库文件
                }
            }
            else if(this->chk_Linux->isChecked())
            {
                if(dir.mkdir(rootPath+"\\3rdParty\\so"))
                {
                    //存放Linux操作系统第三方库文件
                }
            }
        }
        QMessageBox::warning(this,"警告","项目创建成功！");
    }
}
//拷贝文件：
bool MyWizard::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir *createfile     = new QDir;
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if

    if(!QFile::copy(sourceDir, toDir))
    {
        return false;
    }
    return true;
}
//拷贝文件夹：
bool MyWizard::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /**< 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /**< 当为目录时，递归的进行copy */
            if(!copyDirectoryFiles(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()),
                coverFileIfExist))
                return false;
        }
        else{            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            /// 进行文件copy
            if(!QFile::copy(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()))){
                    return false;
            }
        }
    }
    return true;
}

