#include "cat.h"
#include <QDebug>

Cat::Cat(QObject *parent) : QObject{parent}
{
    qInfo() << this << "constructed";
}

Cat::~Cat()
{
    qInfo() << this << "deconstructed";
}

void Cat::setAge(int age)
{
    this->age = age;
}

void Cat::setName(QString name)
{
    this->name = name;
}

int Cat::getAge()
{
    return age;
}

QString Cat::getName()
{
    return name;
}
