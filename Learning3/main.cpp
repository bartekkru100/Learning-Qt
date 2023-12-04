#include <QCoreApplication>
#include <QTimer>
#include "test.h"

Test* getTest(QObject* parent)
{
    return new Test(parent);
}

Test* getTest()
{
    return new Test();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000,&a,QCoreApplication::quit);

    Test* dog = getTest(&a);
    dog->setObjectName("Spot");

    Test* cat = getTest();
    cat->setObjectName("poop");
    cat->setParent(dog);

    int value = a.exec();
    qInfo() << "Exit code:" << value;

    return value;
}
