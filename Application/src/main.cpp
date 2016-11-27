

#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QSplashScreen>
#include <QThread>

#include <QFontDatabase>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/fonts/Modern_Computer_Bright.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/GreatVibes-Regular.otf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/josefin-slab/JosefinSlab-Light.ttf");

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/photos/icon.ico"));
    splash->show();

    QFile file(":/qss/qss/stylesheet.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    QThread::sleep(1);
    w.show();

    splash->finish(&w);
    delete splash;

    return a.exec();
}









