#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QStringView>

void readonly(QStringView name)
{
    qInfo() << "name" << name.data() << name;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString firstname = "Brian";
    QString lastname = "Cairns";

    readonly(firstname);
    qInfo() << "name" << firstname.data() << firstname;

    QString fullname = firstname + " " + lastname;

    foreach(QStringView part, QStringView(fullname).split(QChar(' ')))
    {
        qInfo() << "part" << part;
        if(part.startsWith(QStringView(firstname), Qt::CaseSensitive))
        {
            qInfo() << "Firstname detected" << part;
        }
    }

    return a.exec();
}
