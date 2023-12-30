#include <QCoreApplication>
#include <QStorageInfo>
#include <QDebug>
#include <QList>

void displayStorageInfo(QStorageInfo &storage, QString title)
{
    qInfo() << "---" << title << "-----------";
    qInfo() << "Name:" << storage.name();
    qInfo() << "Display:" << storage.displayName();
    qInfo() << "Root:" << storage.isRoot();
    qInfo() << "Path:" << storage.rootPath();
    qInfo() << "Device:" << storage.device();
    qInfo() << "File System:" << storage.fileSystemType();
    qInfo() << "Read Only:" << storage.isReadOnly();
    qInfo() << "Ready:" << storage.isReady();
    qInfo() << "Size:" << storage.bytesTotal()/1000/1000 << "MB";
    qInfo() << "Available:" << storage.bytesAvailable()/1000/1000 << "MB";
    qInfo() << "Free:" << storage.bytesFree()/1000/1000 << "MB";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStorageInfo root = QStorageInfo::root();
    //displayStorageInfo(root, "Root");

    QList<QStorageInfo> devices = QStorageInfo::mountedVolumes();
    foreach (QStorageInfo device, devices)
    {
        displayStorageInfo(device, device.name());
    }

    return a.exec();
}
