#include "user.h"


QString User::getId() const
{
    return id;
}

void User::setId(QString value)
{
    id = value;
}

QString User::getName() const
{
    return name;
}

void User::setName(const QString &value)
{
    name = value;
}

QString User::getSurname() const
{
    return surname;
}

void User::setSurname(const QString &value)
{
    surname = value;
}

QString User::getJob() const
{
    return job;
}

void User::setJob(const QString &value)
{
    job = value;
}

