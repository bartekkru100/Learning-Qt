#include <QCoreApplication>
#include "test.h"

typedef QList<Test*> testList;

testList getList()
{
    testList list;
    for(int i = 0; i < 5; i++)
    {
        list.append(new Test());
        list.last()->setObjectName("test " + QString::number(i));
    }
    return list;
}

void diplay(testList list)
{
    foreach(Test* item, list)
    {
        qInfo() << item;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testList list = getList();
    diplay(list);
    qInfo() << "Deleting...";
    qDeleteAll(list.begin(), list.end());
    list.clear();

    return a.exec();
}
