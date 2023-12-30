#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

void compileTime()
{
#ifdef Q_OS_LINUX
    qDebug() << "this is Linus";
#endif
#ifdef Q_OS_WIN
    qDebug() << "this is Windows";
#endif
}

void runTime()
{
    QSysInfo info;
    qInfo() << "prettyProductName:"      << info.prettyProductName();
    qInfo() << "productType:"            << info.productType();
    qInfo() << "productVersion:"         << info.productVersion();
    qInfo() << "machineHostName:"        << info.machineHostName();
    qInfo() << "machineUniqueId:"        << info.machineUniqueId();
    qInfo() << "currentCpuArchitecture:" << info.currentCpuArchitecture();
    qInfo() << "buildAbi:"               << info.buildAbi();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    compileTime();

    runTime();

    return a.exec();
}
