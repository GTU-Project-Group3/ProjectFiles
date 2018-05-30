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
#include <QTableWidgetItem>
#include <QTimeEdit>
#include <QLabel>
#include "dialog.h"
#include "dialog2.h"

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
    QList<QString> flowMess;
    QString HTMLTable(QString name,QString surName ,QString msg,QString type);


private:
    Ui::MainWindow *ui;
    Dialog *dia;
    Dialog2 *dia2;

    QTcpServer *server;
    QTcpSocket *socket;

    QList<QTcpSocket*> *list;
    QTimeEdit* timeEdit;

    QList<User*> *listUser;
    QList<nursePatient*> *listNursePatient;
    QList<Patient*> *listPatient;

    QList<qintptr> *doktorsocketid;
    QList<qintptr> *hemsiresocketid;

    QList<qintptr> *sockets;

    QList<int> *doktorinfo;
    QList<int> *hemsireinfo;



    QSignalMapper *mapper;
    int onlineD = 0;
    int onlineH = 0;
    //MyThread t;

private slots:
    void slotNewConnection();
    void slotReadyRead(int index);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_TableHasta_itemPressed(QTableWidgetItem *item);
    void on_TableHasta_cellChanged(int row, int column);
    void on_TableHasta_cellClicked(int row, int column);
    void on_right_clicked();
    void on_left_clicked();
    void on_actionHem_ire_Ekle_triggered();
    void on_actionDoktor_Ekle_triggered();
    void on_actionHasta_Ekle_triggered();
};


#endif // MAINWINDOW_H
