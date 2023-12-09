#include <QCoreApplication>
#include <QMap>
#include "cat.h"
#include <QString>
#include <QSharedPointer>
#include <QRandomGenerator>

typedef QMap<QString, QSharedPointer<Cat>> CatMap_t;

CatMap_t getCats()
{
    CatMap_t cats;

    for(int i = 0; i < 5; i++)
    {
        QSharedPointer<Cat> ptr(new Cat);
        ptr->setAge(QRandomGenerator::global()->bounded(1, 15));
        ptr->setName("Unknown");
        cats.insert("pet" + QString::number(i), ptr);
    }
    return cats;
}

void display(CatMap_t &cats)
{
    foreach(QString key, cats.keys())
    {
        QSharedPointer<Cat> ptr = cats.value(key);
        qInfo() << key << ptr->getName() << ptr->getAge() << ptr.data();
    }
}

void modifyCat(CatMap_t &cats, QString key)
{
    if(cats.contains(key))
    {
        qInfo() << "Modidying" << key;
        cats[key]->setName("Fluffy");
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CatMap_t cats = getCats();
    modifyCat(cats, "pet2");
    display(cats);

    return a.exec();
}
