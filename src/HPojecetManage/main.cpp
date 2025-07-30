#include"hprojectwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HProjectWindow w;

//    QIcon icon("src/main.ico");
//    w.setWindowIcon(icon);
    w.setWindowTitle(QStringLiteral("可视化开发平台"));
    w.show();

    return a.exec();
}
