#include "Title.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>
int main(int argc, char *argv[])
{
    QSurfaceFormat format;
    format.setVersion(3, 3); //  OpenGL °æ±¾
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    QApplication a(argc, argv);
    Title w;
    w.show();
    return a.exec();
}
