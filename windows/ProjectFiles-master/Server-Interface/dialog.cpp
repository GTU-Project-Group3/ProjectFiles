#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
   // line = "akif sari";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    name = ui->name->text();
    surname = ui->surname->text();


    if(name == "" || surname == "" ){
        ui->label->setText("Bütün alanları doldurunuz");
    }
    else{
        ui->label->setText("");
        this->close();
    }
}


QString Dialog::getSurname() const
{
    return surname;
}

QString Dialog::getName() const
{
    return name;
}
