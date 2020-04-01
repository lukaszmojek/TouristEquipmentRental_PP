#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto fileDatabase = new FileDatabase();
    MainWindow *w = new MainWindow(*fileDatabase);
    (*w).show();
    return a.exec();
}
