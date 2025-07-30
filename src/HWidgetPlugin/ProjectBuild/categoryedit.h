#ifndef CATEGORYEDIT_H
#define CATEGORYEDIT_H

#include <QDialog>

namespace Ui {
class CategoryEdit;
}

class CategoryEdit : public QDialog
{
    Q_OBJECT


signals:
    void setCategoryInfo(QString id,QString name,QString description);

public:
    explicit CategoryEdit(QWidget *parent = nullptr);
    ~CategoryEdit();

    void sendData(QStringList);

private slots:
    void on_btn_OK_clicked();

    void on_btn_Cancel_clicked();

private:
    Ui::CategoryEdit *ui;

    QString m_category_id;
};

#endif // CATEGORYEDIT_H
