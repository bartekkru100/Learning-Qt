#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QString>

void testCurrent()
{
    qInfo() << QDir::currentPath();

    QDir dir;
    qInfo() << dir.absolutePath();
}

void testList(QString path, bool recursive = false)
{
    QDir root(path);
    if(!root.exists())
    {
        qWarning() << "Path not found" << path;
        return;
    }

    QFileInfoList list = root.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries);

    foreach(QFileInfo file, list)
    {
        qInfo() << "------------------------";
        qInfo() << "Name" << file.fileName();
        qInfo() << "Path" << file.filePath();
        qInfo() << "Absolute" << file.absoluteFilePath();
        qInfo() << "Created" << file.birthTime().toString();
        qInfo() << "Modified" << file.lastModified().toString();
        qInfo() << "Size" << file.size();

        QString type = "Unknown";
        file.isDir() ? type = "Dir" : type = "File";
        qInfo() << "Type" << type;

        if(recursive && file.isDir()) testList(file.absoluteFilePath());
    }
}

void testModify(QDir root)
{
    if(root.exists("test"))
    {
        qInfo() << "test folder already exists";
        return;
    }

    if(root.mkdir("test"))
    {
        QDir dir("test");
        qInfo() << "created" << dir.absolutePath();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //testCurrent();
    //testList(QDir::currentPath());
    testModify(QDir::current());

    return a.exec();
}
