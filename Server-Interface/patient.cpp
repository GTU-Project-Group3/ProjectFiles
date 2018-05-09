#include "patient.h"



QString Patient::getId() const
{
    return id;
}

void Patient::setId(QString value)
{
    id = value;
}

QString Patient::getName() const
{
    return name;
}

void Patient::setName(const QString &value)
{
    name = value;
}

QString Patient::getSurname() const
{
    return surname;
}

void Patient::setSurname(const QString &value)
{
    surname = value;
}

QString Patient::getDoctorId() const
{
    return doctorId;
}

void Patient::setDoctorId(QString value)
{
    doctorId = value;
}

QString Patient::getNurseId() const
{
    return nurseId;
}

void Patient::setNurseId(QString value)
{
    nurseId = value;
}

QString Patient::getKalp() const
{
    return kalp;
}

void Patient::setKalp(QString value)
{
    kalp = value;
}

QString Patient::getKan() const
{
    return kan;
}

void Patient::setKan(QString value)
{
    kan = value;
}

QString Patient::getSeker() const
{
    return seker;
}

void Patient::setSeker(QString value)
{
    seker = value;
}

