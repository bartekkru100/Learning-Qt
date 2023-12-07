#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
    qInfo() << this << "Constructed" << parent;
}

void Test::message(QString value)
{
    qInfo() << this << value;
}

Test::~Test()
{
    qInfo() << this << "Deconstructed" << parent();

}
