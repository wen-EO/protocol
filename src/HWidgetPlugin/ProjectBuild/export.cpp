#include "export.h"
#include "ui_export.h"
#include "hwidgetlibrary.h"
#include "hconfigmanage.h"
#include <QFileDialog>

Export::Export(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Export)
{
    ui->setupUi(this);
    //去掉帮助按钮
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

    //加载协议类型
    foreach(CATEGORY_INFO *categoryItem,HConfigManage::getInstance()->m_categoryList)
    {
        ui->cbx_category->addItem(categoryItem->categoryName);
    }
}


Export::~Export()
{
    delete ui;
}
//选择路径
void Export::on_pushButton_clicked()
{
    // 弹出文件对话框，指定默认后缀为.h
        QString defaultFileName = "new_header.h";
        QString filePath = QFileDialog::getSaveFileName(
            this,
            tr("选择保存路径"),
            defaultFileName,
            tr("C++ Header Files (*.h);;All Files (*)")
        );

        if (!filePath.isEmpty()) {
            // 确保文件以.h结尾
            if (!filePath.endsWith(".h", Qt::CaseInsensitive)) {
                filePath += ".h";
            }
            ui->filePosition->setText(filePath);
        }
}

