#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(QString id, QString name , QString surname , QString job){
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->job = job;
    }

    QString stringfunction(){
        QString str= id+","+name+","+surname+","+job;

        return str;
    }


    QString getId() const;
    void setId(QString value);

    QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    QString getJob() const;
    void setJob(const QString &value);

private:
    QString id;
    QString name;
    QString surname;
    QString job;

};
#endif // USER_H
