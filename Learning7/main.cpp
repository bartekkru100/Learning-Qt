#include <QCoreApplication>
#include <QString>

void stats(QByteArray &data)
{
    qInfo() << "length" << data.length() << "capacity" << data.capacity();
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray stuff;
    qInfo() << stuff;

    QByteArray data("Hello");
    qInfo() << data;

    QByteArray buffer(10, '\t');
    qInfo() << buffer;

    QByteArray person(QString("Brian").toLocal8Bit());
    qInfo() << person;

    data.reserve(25);
    stats(data);

    data.resize(10);
    stats(data);

    data.truncate(8);
    stats(data);

    data.clear();
    stats(data);

    data.resize(5);
    data.fill('\x02');
    stats(data);

    data.replace(0, 0, QByteArray("Sweet"));
    stats(data);

    data.fill('*');
    data.insert(3, QByteArray("Hello World"));
    stats(data);

    data.append("!");
    stats(data);

    data.remove(0, 3);

    int first = data.indexOf("*");
    int last = data.lastIndexOf("*");
    qInfo() << data.mid(first, (last - first) + 1);

    data.clear();
    data.append("      Bartosz Kruszona");

    QByteArray::tr


    return a.exec();
}
