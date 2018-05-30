#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


    QString getLine() const;

    QString getName() const;

    QString getSurname() const;


private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QString name;
    QString surname;
};

#endif // DIALOG_H
