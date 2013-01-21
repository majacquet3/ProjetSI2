/** @mainpage ... */

#include <QApplication>
#include "View/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName( "Volcano" ); //évite un warning lors de l'exécution.
    MainWindow w;
    w.show();

    return a.exec();
}
