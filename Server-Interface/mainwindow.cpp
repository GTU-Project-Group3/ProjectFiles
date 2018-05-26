#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QByteArray>
#include<QTableWidgetItem>
#include <QTime>
#include <QTimeEdit>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    t.start();

    qDebug() << " ı am in main thread";
    QIcon right("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/right.png");
    QIcon left("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/left.png");
    ui->right->setIcon(right);
    ui->right->setStyleSheet("border:0pt;");
    ui->left->setIcon(left);
    ui->left->setStyleSheet("border:0pt;");
    server = new QTcpServer(this);
    list = new QList<QTcpSocket*>;

    listPatient = new QList<Patient*>;
    listNursePatient = new QList<nursePatient*>;
    listUser = new QList<User*>;

    doktorsocketid = new QList<qintptr>;
    hemsiresocketid = new QList<qintptr>;

    timeEdit = new QTimeEdit();

   // QTimeEdit* timeEdit = new QTimeEdit();  // created the object

     // write code to initialize QTimeEdit as per your requirement

     // Put below code wherever you want to read QTimeEdit Data

     QTime enTime = timeEdit->time();
     qDebug() << enTime.toString();


    parserPatient();
    parserUser();
    parserNursePatient();

    mapper = new QSignalMapper(this);

    if(!server->listen(QHostAddress::Any,8081)){
        qDebug() <<"server not ok";

    }else{
        qDebug() <<"server ok";
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(slotReadyRead(int)));

    //table olusturulmasi
    ui->TableHasta->setColumnCount(6);
    ui->TableHasta->setRowCount(listPatient->size());
    QTableWidgetItem *header1 = new QTableWidgetItem("Name");
    header1->setTextColor(QColor(46, 52, 54));
    ui->TableHasta->setHorizontalHeaderItem(0,header1);
    QTableWidgetItem *header2 = new QTableWidgetItem("Surname");
    header2->setTextColor(QColor(46, 52, 54));
    ui->TableHasta->setHorizontalHeaderItem(1,header2);
    QTableWidgetItem *header3 = new QTableWidgetItem("Heart");
    header3->setTextColor(QColor(46, 52, 54));
    ui->TableHasta->setHorizontalHeaderItem(2,header3);
    QTableWidgetItem *header4 = new QTableWidgetItem("Blood");
    header4->setTextColor(QColor(46, 52, 54));
    ui->TableHasta->setHorizontalHeaderItem(3,header4);
    QTableWidgetItem *header5 = new QTableWidgetItem("Glikoz");
    header5->setTextColor(QColor(46, 52, 54));
    ui->TableHasta->setHorizontalHeaderItem(4,header5);
    QTableWidgetItem *header6 = new QTableWidgetItem("Update");
    header6->setTextColor(QColor(46, 52, 54));
    ui->TableHasta->setHorizontalHeaderItem(5,header6);

    QTableWidgetItem *headerJob = new QTableWidgetItem("Job");
    headerJob->setTextColor(QColor(46, 52, 54));

    QTableWidgetItem *onlineStatus = new QTableWidgetItem("Status");
    onlineStatus->setTextColor(QColor(46, 52, 54));

    int rowSizeForUser = listUser->size();

    ui->TableDoktor->setColumnCount(4);

    ui->TableDoktor->setRowCount(rowSizeForUser);

    ui->TableDoktor->setHorizontalHeaderItem(0,headerJob);

    ui->TableDoktor->setHorizontalHeaderItem(1,header1);

    ui->TableDoktor->setHorizontalHeaderItem(2,header2);

    ui->TableDoktor->setHorizontalHeaderItem(3,onlineStatus);


    for(int s = 0 ; s < listUser->size(); s++){

        QLabel * Job= new QLabel(ui->TableDoktor);
        Job->setStyleSheet("font-weight: bold;");
        Job->setText(listUser->at(s)->getJob());
        Job->setAlignment(Qt::AlignCenter);
        ui->TableDoktor->setCellWidget(s,0,Job);

        QLabel * userName= new QLabel(ui->TableDoktor);
        userName->setStyleSheet("font-weight: bold;");
        userName->setText(listUser->at(s)->getName());
        userName->setAlignment(Qt::AlignCenter);
        ui->TableDoktor->setCellWidget(s,1,userName);

        QLabel * userSurname= new QLabel(ui->TableDoktor);
        userSurname->setStyleSheet("font-weight: bold;");
        userSurname->setText(listUser->at(s)->getSurname());
        userSurname->setAlignment(Qt::AlignCenter);
        ui->TableDoktor->setCellWidget(s,2,userSurname);

//        QLabel * status= new QLabel(ui->TableDoktor);
//        status->setStyleSheet("font-weight: bold;");
//        status->setText("offline");
//        status->setAlignment(Qt::AlignCenter);
//        ui->TableDoktor->setCellWidget(s,3,status);

        QPixmap iconofline("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/offline3.png");

        QLabel *ofline = new QLabel(ui->TableDoktor);
        ofline->setPixmap(iconofline);
        ofline->setAlignment(Qt::AlignCenter);
        ui->TableDoktor->setCellWidget(s,3,ofline); // Gonder set etme
    }




    //hucrelere label eklenmesi
    for (int var = 0; var < listPatient->size(); ++var) {
        QLabel * label = new QLabel(ui->TableHasta);
        label->setStyleSheet("font-weight: bold;");
        label->setText(listPatient->at(var)->getName());
        label->setAlignment(Qt::AlignCenter);

        ui->TableHasta->setCellWidget(var,0,label); // isimleri set etme
        /* ** **    *   *   *   *       *   *   */
        QLabel * Surname = new QLabel(ui->TableHasta);
        Surname->setText(listPatient->at(var)->getSurname());
        Surname->setStyleSheet("font-weight: bold;");
        Surname->setAlignment(Qt::AlignCenter);
        ui->TableHasta->setCellWidget(var,1,Surname); // soy isimleri set etme
        /*  *   *   *   *   *   *   *   *       *   **/
        QTableWidgetItem * kalp = new QTableWidgetItem();
        kalp->setText(listPatient->at(var)->getKalp());
        kalp->setTextAlignment(Qt::AlignCenter);
        ui->TableHasta->setItem(var,2,kalp); // kalpler set etme
        /*  *   *   *   *   *   *   *   *       *   **/
        QTableWidgetItem * kan = new QTableWidgetItem();
        kan->setText(listPatient->at(var)->getKan());
        kan->setTextAlignment(Qt::AlignCenter);
        ui->TableHasta->setItem(var,3,kan); // kan set etme
        /*  *   *   *   *   *   *   *   *       *   **/
        QTableWidgetItem * seker = new QTableWidgetItem();
        seker->setText(listPatient->at(var)->getSeker());
        seker->setTextAlignment(Qt::AlignCenter);
        ui->TableHasta->setItem(var,4,seker); // kan set etme
        /*  *   *   *   *   *   *   *   *       *   **/

        QPixmap iconn("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/update.png");

        QLabel *gonder = new QLabel(ui->TableHasta);
        gonder->setPixmap(iconn);
        gonder->setAlignment(Qt::AlignCenter);
        ui->TableHasta->setCellWidget(var,5,gonder); // Gonder set etme
        /* table css uygulanmasi */
    }



}

MainWindow::~MainWindow()
{
  //  t.wait();
  //  t.exit();
    server->close();
    delete list;
    delete ui;

    delete timeEdit;

    delete listUser;
    delete listNursePatient;
    delete listPatient;

    delete doktorsocketid;
    delete hemsiresocketid;

}


void MainWindow::slotNewConnection()
{

    qWarning() << "newConnection";
    list->append(server->nextPendingConnection());

    //here you map each client to its number in the list
    mapper->setMapping(list->last(), list->length()-1);

    //here we say, that when ever a client from the QList sends readyRead() the mapper should be used
    //with the property (list->length()-1) defined in the line above
    connect(list->last(), SIGNAL(readyRead()), mapper, SLOT(map()));

    QString str = QString::number(doktorsocketid->size()) + "," + QString::number(hemsiresocketid->size());


   // list->last()->write(QString::number(doktorsocketid->size()).toUtf8());

    //    send( list->last()->socketDescriptor(),QString::number(doktorsocketid->size()).toUtf8(),sizeof(char)*1024,0);

    list->last()->write(str.toUtf8());

}

void MainWindow::slotReadyRead(int index)
{


  //  int processing;
    QString process;

   // QByteArray template1;

    process =  list->at(index)->readAll();

    qDebug() << process;
   // processing = (tr(template1)).toInt();


    QTime enTime = timeEdit->time();
    qDebug() << enTime.toString();


    for(int j = 0 ; j < listNursePatient->size()  ;j++){
        int valuePansuman = listNursePatient->at(j)->getPansuman().toInt();
        int valueTansiyon = listNursePatient->at(j)->getTansiyon().toInt();
        listNursePatient->at(j)->setPansuman( QString::number( valuePansuman - enTime.minute() ) );
        listNursePatient->at(j)->setTansiyon(  QString::number(valueTansiyon- enTime.minute() ) );
    }

    QString ack="ack";

    for(int k = 0 ; k < list->size() && index != k ;k++){

        if( send(list->at(k)->socketDescriptor() , ack.toUtf8() , ack.size() , 0) < 0 ){
//            QLabel * status= new QLabel(ui->TableDoktor);
//            status->setStyleSheet("font-weight: bold;");
//            status->setText("offline");                      // online durumu arayuze yaziliyor.
//            status->setAlignment(Qt::AlignCenter);
//            ui->TableDoktor->setCellWidget(k,3,status);

            QPixmap iconofline("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/offline3.png");

            QLabel *ofline = new QLabel(ui->TableDoktor);
            ofline->setPixmap(iconofline);
            ofline->setAlignment(Qt::AlignCenter);
            ui->TableDoktor->setCellWidget(k,3,ofline); // Gonder set etme



            for(int l = 0 ; l < doktorsocketid->size(); l++){

                if(list->at(k)->socketDescriptor() == doktorsocketid->at(l)){
                    doktorsocketid->removeAt(l);
                    break;
                }

            }

            for(int m = 0 ; m < hemsiresocketid->size(); m++){

                if(list->at(k)->socketDescriptor() == hemsiresocketid->at(m)){
                    hemsiresocketid->removeAt(m);
                    break;
                }

            }
        }


    }


    if(process == "1"){
        char d= 'D';
        char n='H';
        char sendcontrol = '0';
        bool control = true;
        QString strInf;
        QString hastaind;
        QString hastaind1;
        qDebug() << "ses icine girdi";


        list->at(index)->waitForReadyRead(10000);

        strInf =  list->at(index)->readAll();

        // to do parser

        qDebug() << strInf;

        if(strInf.split(" ").size() >= 2 ){
            for(int i = 0 ; i < listUser->size() ; i++){

                qDebug() <<"asdasds  " <<strInf.split(" ").at(1);
                if(strInf.split(" ").at(1) == listUser->at(i)->getName()){

                    qDebug() <<"asdasds  " <<strInf.split(" ").at(1);
                    if(listUser->at(i)->getJob() == "Doctor"){

//                        QLabel * status= new QLabel(ui->TableDoktor);
//                        status->setStyleSheet("font-weight: bold;");
//                        status->setText("online");                      // online durumu arayuze yaziliyor.
//                        status->setAlignment(Qt::AlignCenter);
//                        ui->TableDoktor->setCellWidget(i,3,status);


                        QPixmap iconofline("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/online3.png");

                        QLabel *ofline = new QLabel(ui->TableDoktor);
                        ofline->setPixmap(iconofline);
                        ofline->setAlignment(Qt::AlignCenter);
                        ui->TableDoktor->setCellWidget(i,3,ofline); // Gonder set etme

                         onlineD++;
                        qDebug() << "Girdi";
                        send( list->at(index)->socketDescriptor(),&d,sizeof(char),0);

                        list->at(index)->waitForReadyRead(2000);
                        int ind;
                        hastaind = list->at(index)->readAll();
                        ind = hastaind.toInt();
                        ind = ind % listPatient->size();

                        doktorsocketid->append(list->at(index)->socketDescriptor());

                        qDebug() << "gelen index" <<ind;
                        if(ind < 0)
                            ind += listPatient->size();

                        QString strtemp= listPatient->at(ind)->stringfunction();
                        send( list->at(index)->socketDescriptor(),strtemp.toUtf8(),strtemp.size(),0);
                        control = false;
                        break;
                    }else if(listUser->at(i)->getJob() == "Hemsire"){

//                        QLabel * status= new QLabel(ui->TableDoktor);
//                        status->setStyleSheet("font-weight: bold;");
//                        status->setText("online");                      // online durumu arayuze yaziliyor.
//                        status->setAlignment(Qt::AlignCenter);
//                        ui->TableDoktor->setCellWidget(i,3,status);

                        QPixmap iconofline("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/online3.png");

                        QLabel *ofline = new QLabel(ui->TableDoktor);
                        ofline->setPixmap(iconofline);
                        ofline->setAlignment(Qt::AlignCenter);
                        ui->TableDoktor->setCellWidget(i,3,ofline); // Gonder set etme

                         onlineH++;
                        send( list->at(index)->socketDescriptor(),&n,sizeof(char),0);
                        list->at(index)->waitForReadyRead(2000);
                        int ind1;
                        hastaind1 = list->at(index)->readAll();
                        ind1 = hastaind1.toInt();
                        ind1 = ind1 % listNursePatient->size();

                        hemsiresocketid->append(list->at(index)->socketDescriptor());
                        qDebug() << "gelen index" <<ind1;
                        if(ind1 < 0)
                            ind1 += listNursePatient->size();
                        QString strtemp1= listNursePatient->at(ind1)->stringfunction();
                        send( list->at(index)->socketDescriptor(),strtemp1.toUtf8(),strtemp1.size(),0);

                        control = false;
                        break;
                    }
                }
            }
        }
        if(control ){

            send( list->at(index)->socketDescriptor(),&sendcontrol,sizeof(char),0);
        }
    }

    else if(process == "2" ){

        //gelen sayiya göre

        int hastaindexi;
        qDebug() << "2 ye girdi";

        list->at(index)->waitForReadyRead(1000);
        hastaindexi = (tr(list->at(index)->readAll())).toInt();
        hastaindexi = hastaindexi%listPatient->size();

        if(hastaindexi < 0){
            hastaindexi += listPatient->size();
        }

        QString st= listPatient->at(hastaindexi)->stringfunction();

        send( list->at(index)->socketDescriptor(),st.toUtf8(),st.size(),0);



    }
    else if(process == "5"){

        QString doktormesaj;


        for(int i = 0 ; i < list->size(); i++){

            for(int j = 0 ; j < doktorsocketid->size() ; j++){
                if(list->at(i)->socketDescriptor() == doktorsocketid->at(j)){
                     list->at(i)->waitForReadyRead(11000);
                     doktormesaj = list->at(i)->readAll();
                     qDebug() << doktormesaj;

                     if (hemsiresocketid->size() != 0){
                         send( hemsiresocketid->at(0),doktormesaj.toUtf8(),doktormesaj.size(),0);

                     }
                     break;
                }
            }
        }

       // list->at(index)->waitForReadyRead(11000);

     //   doktormesaj = list->at(index)->readAll();

       // qDebug() << doktormesaj;
    }

    else if(process == "6"){

        QString hemsiremesaj;

        //list->at(i)->ConnectingState

        for(int i = 0 ; i < list->size(); i++){

            for(int j = 0 ; j < hemsiresocketid->size() ; j++){
                if(list->at(i)->socketDescriptor() == hemsiresocketid->at(j)){
                     list->at(i)->waitForReadyRead(11000);
                     hemsiremesaj = list->at(i)->readAll();
                     qDebug() << hemsiremesaj;
                     if (doktorsocketid->size() != 0){
                         send( doktorsocketid->at(0),hemsiremesaj.toUtf8(),hemsiremesaj.size(),0);

                     }
                     break;
                }
            }
        }

      //  list->at(index)->waitForReadyRead(11000);

      //  hemsiremesaj = list->at(index)->readAll();

       // qDebug() << hemsiremesaj;
    }


    else if(process == "8"){

        QString nurseindex;
        int hastaindexiNurse;

        qDebug() << "10 a girdi";
        // hemsirenin hasta bilgilerini alacagi yer
        list->at(index)->waitForReadyRead(1000);

        nurseindex = (list->at(index)->readAll());
        hastaindexiNurse = nurseindex.toInt();
        hastaindexiNurse = hastaindexiNurse%listNursePatient->size();
        if(hastaindexiNurse < 0){
            hastaindexiNurse += listNursePatient->size();
        }
        QString st1= listNursePatient->at(hastaindexiNurse)->stringfunction();
        qDebug() << st1;
        send( list->at(index)->socketDescriptor(),st1.toUtf8(),st1.size(),0);
    }





}
void MainWindow::parserPatient()
{
    ifstream file("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/patients.csv");

    QString temp;
    string temp1;
    QStringList listStr;

    qDebug() << "FILE ";

    getline(file,temp1);
    while(getline(file,temp1)){

        qDebug() << temp1.c_str();
        temp = temp1.c_str();
        listStr = temp.split(',');

        listPatient->append(new Patient(listStr.at(0),listStr.at(1),listStr.at(2),listStr.at(3),listStr.at(4),
                                        listStr.at(5),listStr.at(6),listStr.at(7)));
    }




}
void MainWindow::parserNursePatient()
{
    ifstream file("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/nursePatient.csv");

    QString temp;
    string temp1;
    QStringList listStr;

    qDebug() << "FILE ";

    getline(file,temp1);
    while(getline(file,temp1)){

        qDebug() << temp1.c_str();
        temp = temp1.c_str();
        listStr = temp.split(',');

        listNursePatient->append(new nursePatient(listStr.at(0),listStr.at(1),listStr.at(2),listStr.at(3),listStr.at(4),
                                        listStr.at(5),listStr.at(6),listStr.at(7),listStr.at(8)));
    }




}

void MainWindow::parserUser()
{
    ifstream file("/home/akilok/Desktop/projesonhal/ProjectFiles/Server-Interface/users.csv");

    QString temp;
    string temp1;
    QStringList listStr;

    qDebug() << "FILE ";

    getline(file,temp1);
    while(getline(file,temp1)){

        qDebug() << temp1.c_str();
        temp = temp1.c_str();
        listStr = temp.split(',');
        qDebug() << listStr.size();
        listUser->append(new User(listStr.at(0),listStr.at(1),listStr.at(2),listStr.at(3)));
    }




}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "butona basildi\n";

    ui->stackedWidget->setCurrentIndex(1);

}



void MainWindow::on_TableHasta_cellClicked(int row, int column)
{
    if(column == 5){//update buttona tiklandi ise

        QString kan =  ui->TableHasta->item(row,2)->text();
        QString kalp =  ui->TableHasta->item(row,3)->text();
        QString seker = ui->TableHasta->item(row,4)->text();
        qDebug() <<listPatient->at(row)->getSeker(); // isim bu
        listPatient->at(row)->setKan(kan);
        listPatient->at(row)->setKalp(kalp);
        listPatient->at(row)->setSeker(seker);
        qDebug() <<"son hali:"<<listPatient->at(row)->getSeker(); // isim bu
        qDebug()<<kan<<kalp<<seker;//update edildi sıkıntılı durum var ise clienta bildirilir
        QString temp;
        int hemsiresayisi = hemsiresocketid->size();
        int doktorsayisi = doktorsocketid->size();

        temp ="ACIL DURUM\n"+ QString::number(doktorsayisi) +"," + QString::number(hemsiresayisi) + "\n"  +listPatient->at(row)->getName()+"\n"+kan+"\n"+kalp+"\n"+seker;
        // acil durumda gonderilen mesaj

        qDebug()<<temp;


        //BURADA DOKTOR VE HEMSIRE SAYISI DA YOLLANACAK.

        //BELLI DEGERLER KONTROL EDILECEK ONA GORE DOKTOR VEYA HEMSIREYE GONDERILECEK.



        if(hemsiresocketid->size() != 0 )
            send( hemsiresocketid->last(),temp.toUtf8(),temp.size(),0);

        if(doktorsocketid->size() != 0)
            send( doktorsocketid->last(),temp.toUtf8(),temp.size(),0);

    }




}

void MainWindow::on_right_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    int size = ui->stackedWidget->size().height();
    index++;
    index = index % size;
 ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::on_left_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    int size = ui->stackedWidget->size().height();
    index--;
    index = index % size;
 ui->stackedWidget->setCurrentIndex(index);
}
