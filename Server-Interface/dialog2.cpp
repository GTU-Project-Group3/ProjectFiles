#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    name = ui->name->text();
    surname = ui->surname->text();
    doktorid = ui->doktorid->text();
    nurseid = ui->nurseid->text();
    kalp= ui->kalp->text();
    kan= ui->kan->text();
    seker= ui->seker->text();
    oda= ui->oda_numarasi->text();
    pansuman= ui->pansuman->text();
    tansiyon= ui->tansiyon->text();

    if(name == "" || surname == "" || doktorid == "" || nurseid == "" || kalp == "" || kan == "" || seker == ""
             || oda == ""  || pansuman == ""  || tansiyon == ""){
        ui->mesaj->setText("Bütün alanları doldurunuz");
    }
    else{
        ui->mesaj->setText("");
        this->close();
    }
}

QString Dialog2::getTansiyon() const
{
    return tansiyon;
}

QString Dialog2::getPansuman() const
{
    return pansuman;
}

QString Dialog2::getOda() const
{
    return oda;
}

QString Dialog2::getSeker() const
{
    return seker;
}

QString Dialog2::getKan() const
{
    return kan;
}

QString Dialog2::getKalp() const
{
    return kalp;
}

QString Dialog2::getNurseid() const
{
    return nurseid;
}

QString Dialog2::getDoktorid() const
{
    return doktorid;
}

QString Dialog2::getSurname() const
{
    return surname;
}

QString Dialog2::getName() const
{
    return name;
}
