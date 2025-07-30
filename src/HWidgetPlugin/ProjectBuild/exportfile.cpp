#include "exportfile.h"
#include <QPainter>
#include <QPrinter>
#include <QTextDocument>
#include <QTextBlock>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QStringList>
//#pragma execution_character_set("utf-8")

ExportFile::ExportFile()
{

}
/*
  导出PDF
  参数：模板类型
  */
void ExportFile::OutputPDF(int Type,QString PathName,QString Title, QString Technology,QString Area,QString STime,QString Level,QString Location,QString Event)
{
    QString html;
    html="<html><div align='center' style='line-height:40px;font-size:20px'>"+Title+"<p></p></div>"+html+"</html>";

    //设置字体
    QFont font("Microsoft YaHei", 10, 50 ,0);//参数：字体，大小，粗体，斜体

    //导出PDF
    QPrinter printer_text;
    printer_text.setPageSize(QPrinter::A4);  //设置纸张大小为A4
    printer_text.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
    printer_text.setOutputFileName(PathName);//PathName "F:/1.pdf"
    QTextDocument text_document;
    text_document.setDefaultFont(font);
    text_document.setHtml(html);
    text_document.print(&printer_text);
    text_document.end();
    //QTextBlock it = text_document.end();

}
void ExportFile::OutputPDF(QString PathName,QString Title,QString html)
{

    html="<html><div align='center' style='line-height:40px;font-size:20px'>"+Title+"</div>"+html+"</html>";

    //设置字体
    QFont font("Microsoft YaHei", 10, 50 ,0);//参数：字体，大小，粗体，斜体

    //导出PDF
    QPrinter printer_text;
    printer_text.setPageSize(QPrinter::A4);  //设置纸张大小为A4
    printer_text.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
    printer_text.setOutputFileName(PathName);//PathName "F:/1.pdf"
    QTextDocument text_document;
    text_document.setDefaultFont(font);
    text_document.setHtml(html);
    text_document.print(&printer_text);
    text_document.end();
    //QTextBlock it = text_document.end();

}
/*
  导出Word
  参数：模板类型
  */
void ExportFile::OutputWord(int Type,QString PathName,QString Title, QString Technology,QString Area,QString STime,QString Level,QString Location,QString Event)
{
    QString html;
    html="<html><div align='center' style='line-height:40px;font-size:20px'>"+Title+"<p></p></div>"+html+"</html>";

    //导出word
    QFile WordDoc(PathName);
    WordDoc.open(QIODevice::WriteOnly | QIODevice::Append );
    QTextStream stream(&WordDoc);
    stream << html << endl;

}
void ExportFile::OutputWord(QString PathName,QString Title,QString html)
{
   // QString html;
    html="<html><div align='center' style='line-height:40px;font-size:20px'>"+Title+"<p></p></div>"+html+"</html>";

    //导出word
    QFile WordDoc(PathName);
    WordDoc.open(QIODevice::WriteOnly | QIODevice::Append );
    QTextStream stream(&WordDoc);
    stream << html << endl;

}

//生成表格    字体
QString ExportFile::CreatForm(int nRow,int nCol,QStringList List,QString FormName)
{
    QString html;
    int flg =0;
    //表头
    QString sHeader;
    for (int i=0;i<nCol;i++)
    {

        if(flg<List.count())
            sHeader+="<th>"+List[flg++]+"</th>";
        else
            sHeader+="<th></th>";
    }
    //内容
    QString sBody;
    //for (int i=0;i<nRow-1;i++) zhaoz
    for (int i=0;i<nRow;i++)
    {
         sBody+="<tr>";
        for (int j=0;j<nCol;j++)
        {
            if(flg<List.count())
                sBody+="<th>"+List[flg++]+"</th>";
            else
                sBody+="<th></th>";
        }
        sBody+="</tr>";
    }

    html= "<div><p></p><table border='1' cellspacing='0' cellpadding='0' width='100%'>"
         "<thead>"
         "<tr>"
         +sHeader+
         "</tr>"
         "</thead>"
         "<tbody>"
         +sBody+
         "</tbody>"
         "</table>"
         "<div style='text-align:center;font-size:12px;margin-top:5px'>"+FormName+"</div></div>";

    return html;
}
QString  ExportFile::CreatPic(QString Path,QString PicName)
{
    QString html;

    html = "<div><p></p><p></p><img align=\"middle\" src = \"" + Path + "\"  width=\"600\" height=\"" + "\"/><br>"
           "<div style='text-align:center;font-size:12px;margin-top:5px'>"+PicName+"</div></div>";


    return html;
}
QString  ExportFile::CreatText(QString str)
{
    QString html;

    html="<div style='line-height:30px;font-size:15px'>&nbsp;&nbsp;"+str+"</div>";

    return html;
}
