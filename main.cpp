#include "mainwindow.h"
#include <View/Headers/ellipserenderer.h>
#include <Model/Headers/ellipse.h>

#include <QApplication>
#include <QPixmap>
#include <View/Headers/rectanglerenderer.h>
#include <app.h>
#include <ellipsesetupdialog.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();
    w.update();
    return a.exec();
}
