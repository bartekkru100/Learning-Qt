#include <QCoreApplication>
#include <QList>
#include <QRandomGenerator>

QList<int> getNumbers()
{
    QList<int> list;

    list << 300 << 400 << 500;

    int max = QRandomGenerator::global()->bounded(1, 10);
    for(int i = 0; i < max; i++)
    {
        list.append(QRandomGenerator::global()->bounded(1, 100));
    }

    return list;
}

void testNumbers()
{
    QList<int> list = getNumbers();
    qInfo() << list;

    qInfo() << list.length();

    for(int i = 0; i < list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i) << "or" << list[i];
    }

    qInfo() << "---------------";

    foreach(int i, list)
    {
        qInfo() << i;
    }
}

void test_modifying()
{
    QList list = getNumbers();

    list[0] = 1000;

    list.append(99);
    list << 2000 << 3000;

    list.insert(0, 55);

    for(int i = 0; i < list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i);
    }


    qInfo() << "length" << list.length();
    list.removeAt(0);
    qInfo() << "removeAt" << list.length();
    list.removeOne(2000);
    qInfo() << "removeAt" << list.length();
    list.removeAll(2000);
    qInfo() << "removeAt" << list.length();
}

void test_search()
{

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test_modifying();

    return a.exec();
}
