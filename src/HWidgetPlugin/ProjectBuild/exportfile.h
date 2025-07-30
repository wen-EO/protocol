#ifndef EXPORTFILE_H
#define EXPORTFILE_H

#include <QString>
class ExportFile
{
public:
    ExportFile();

public:
     //参数：模板类型/路径名称/标题/技术/区域/发震时间/震级/位置/事件
    void OutputPDF(int Type,QString PathName,QString Title, QString Technology,QString Area,QString STime,QString Level,QString Location,QString Event);
    void OutputWord(int Type,QString PathName,QString Title, QString Technology,QString Area,QString STime,QString Level,QString Location,QString Event);

    //参数：模板类型/路径名称/行/列/字符串链表/表名
    void OutputPDF(QString PathName,QString Title,QString html);
    void OutputWord(QString PathName,QString Title,QString html);

    //生成表格
    QString CreatForm(int nRow,int nCol,QStringList List,QString FormName);
    //生成图片
    QString CreatPic(QString Path,QString PicName);
    //生成文字
    QString CreatText(QString str);

};

#endif // EXPORTFILE_H
