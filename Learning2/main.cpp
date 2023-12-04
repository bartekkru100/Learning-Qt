#include <QCoreApplication>
#include "cat.h"

void test(Cat &cat)
{
    qInfo() << &cat;
}

void test2(Cat *cat)
{
    qInfo() << cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat kitty;
    test(kitty);
    test2(&kitty);

    return a.exec();
}
