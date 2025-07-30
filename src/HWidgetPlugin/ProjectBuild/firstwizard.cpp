#include "firstwizard.h"
#include "ui_firstwizard.h"
#include <QLabel>

FirstWizard::FirstWizard(QWizardPage *parent) :
    QWizardPage(parent),
    ui(new Ui::FirstWizard)
{
    ui->setupUi(this);
    setTitle(titleTemplate().arg("Qt软件向导使用"));
    setSubTitle(subTitleTemplate().arg("博客地址：http://blog.csdn.net/jiezhj"));
}

FirstWizard::~FirstWizard()
{
    delete ui;
}

QString titleTemplate()
{
  return QString::fromLatin1("<font color=\"white\" size=\"5\">")+ QString::fromLatin1("%1</font>");
}

QString subTitleTemplate()
{
    return QString::fromLatin1("<font color=\"white\" size=\"3\">")+ QString::fromLatin1("%1</font>");
}
