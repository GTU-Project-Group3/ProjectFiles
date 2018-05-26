#ifndef NURSEPATIENT_H
#define NURSEPATIENT_H

#include <QString>

class nursePatient
{
public:

    nursePatient(QString id,QString odanumarasi,QString name, QString surname , QString pansuman, QString tansiyon, QString onlineDoc, QString onlineHem , QString hastaSayisi ){
        this->id = id;
        this->odanumarasi = odanumarasi;
        this->name = name;
        this->surname = surname;
        this->pansuman = pansuman;
        this->tansiyon = tansiyon;
        this->onlineDoc = onlineDoc;
        this->onlineHem = onlineHem;
        this->hastaSayisi = hastaSayisi;

    }

    QString stringfunction(int doktor , int hemsire , int hastasayisi ){
        QString str= id+","+odanumarasi+","+name+","+surname+","+pansuman+","
                +tansiyon+","+QString::number(doktor)+","+
                QString::number(hemsire)+","+QString::number(hastasayisi);

        return str;
    }

    QString getId() const;
    void setId(const QString &value);

    QString getOdanumarasi() const;
    void setOdanumarasi(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    QString getPansuman() const;
    void setPansuman(const QString &value);

    QString getTansiyon() const;
    void setTansiyon(const QString &value);

    QString getOnlineDoc() const;
    void setOnlineDoc(const QString &value);

    QString getOnlineHem() const;
    void setOnlineHem(const QString &value);

    QString getHastaSayisi() const;
    void setHastaSayisi(const QString &value);

private:
    QString id;
    QString odanumarasi;
    QString name;
    QString surname;
    QString pansuman;
    QString tansiyon;
    QString onlineDoc;
    QString onlineHem;
    QString hastaSayisi;
};

#endif // NURSEPATIENT_H
