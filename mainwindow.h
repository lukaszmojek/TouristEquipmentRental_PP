#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filedatabase.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    FileDatabase fileDatabase;

private slots:
    void on_lineEdit_2_textChanged(const QString &arg1);

public:
    MainWindow(FileDatabase fileDatabase, QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
