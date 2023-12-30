#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

void basics()
{
    QFile file("test.txt");
    if(!file.open(QIODevice::ReadWrite))
    {
        qCritical() << "Could not open file";
        qCritical() << file.errorString();
        return;
    }
    qInfo() << "Writing file...";
    file.write(QByteArray("Hello World"));
    file.flush();

    qInfo() << "Reading file...";
    file.seek(0);
    qInfo() << file.readAll();
    file.close();
}

bool writeFile(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Could not open file";
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    for(int i = 0; i < 5; i++)
    {
        stream << QString::number(i) << " Hello World\n";
    }

    file.close();
    return true;
}

bool readFile(QString filename)
{
    QFile file(filename);
    if(!file.exists())
    {
        qCritical() << "File not found";
        return false;
    }
    if(!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Could not open file";
        qCritical() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    //QString data = stream.readAll();

    while(!stream.atEnd())
    {
        QString line = stream.readLine();
        qInfo() << line;
    }

    file.close();
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    basics();
    writeFile("lol.txt");
    readFile("lol.txt");

    return a.exec();
}
