#ifndef PATIENT_H
#define PATIENT_H

#include <QString>

class Patient
{
public:
    Patient(QString id,QString name, QString surname , QString doctor, QString nurse, QString kalp, QString kan , QString seker ){
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->doctorId = doctor;
        this->nurseId = nurse;
        this->kalp = kalp;
        this->kan = kan;
        this->seker = seker;

    }

    QString stringfunction(int doktor , int hemsire , int hastasayisi ){
        QString str= id+","+name+","+surname+","+kalp+","
                +kan+","+seker+","+QString::number(doktor)+","+
                QString::number(hemsire)+","+QString::number(hastasayisi);

        return str;
    }

    QString getId() const;
    void setId(QString value);

    QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    QString getDoctorId() const;
    void setDoctorId(QString value);

    QString getNurseId() const;
    void setNurseId(QString value);

    QString getKalp() const;
    void setKalp(QString value);

    QString getKan() const;
    void setKan(QString value);

    QString getSeker() const;
    void setSeker(QString value);

private:
    QString id;
    QString name;
    QString surname;
    QString doctorId;
    QString nurseId;
    QString kalp;
    QString kan;
    QString seker;
};
#endif // PATIENT_H
