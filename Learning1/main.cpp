#include <QCoreApplication>
#include "test.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;
    QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    test.dostuff();
    int value = a.exec();

    return value;
}
