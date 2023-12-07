#include <QCoreApplication>
#include <QScopedPointer>
#include <QSharedPointer>
#include "test.h"

void testScope()
{
    QScopedPointer<Test> ptr(new Test());
    ptr->message("Hello");
}

void work(QSharedPointer<Test> ptr)
{
    ptr->message("working");
}

void finish(QSharedPointer<Test> ptr)
{
    ptr->message("finished");
}

void step(QSharedPointer<Test> ptr)
{
    ptr->message("stepping");
    for(int i = 0; i < 4; i++)
    {
        work(ptr);
    }
    finish(ptr);
}

void testShared(Test* test)
{
    QSharedPointer<Test> ptr(test);
    ptr->message("starting");
    step(ptr);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testShared(new Test());

    return a.exec();
}
