#include "Title.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QApplication a(argc, argv);
    Title w;
    w.show();
    return a.exec();
}
