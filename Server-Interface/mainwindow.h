#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "patient.h"
#include "user.h"
#include "nursepatient.h"
#include <QMainWindow>
#include <QtDebug>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSignalMapper>
#include <QList>
#include <QString>
#include "mythread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void parserUser();
    void parserPatient();
    void parserNursePatient();


private:
    Ui::MainWindow *ui;

    QTcpServer *server;
    QTcpSocket *socket;

    QList<QTcpSocket*> *list;

    QList<Patient*> *listPatient;
    QList<User*> *listUser;
    QList<nursePatient*> *listNursePatient;

    QSignalMapper *mapper;
    int onlineD = 0;
    int onlineH = 0;
    //MyThread t;

private slots:
    void slotNewConnection();
    void slotReadyRead(int index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};


#endif // MAINWINDOW_H
