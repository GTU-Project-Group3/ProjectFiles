#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();

    QString getName() const;

    QString getSurname() const;

    QString getDoktorid() const;

    QString getNurseid() const;

    QString getKalp() const;

    QString getKan() const;

    QString getSeker() const;

    QString getOda() const;

    QString getPansuman() const;

    QString getTansiyon() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog2 *ui;

    QString name;
    QString surname;
   QString doktorid;
   QString nurseid;
   QString kalp;
   QString kan;
   QString seker;
   QString oda;
   QString pansuman;
   QString tansiyon;
};

#endif // DIALOG2_H
