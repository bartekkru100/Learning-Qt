#include <QCoreApplication>
#include <QObject>
#include <QThread>
#include <QDebug>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    qInfo() << "Starting" << QThread::currentThread();
    qInfo() << "Doing stuff" << QThread::currentThread();

    //Worker worker;
    Worker *worker = new Worker();
    QThread thread;
    thread.setObjectName("Worker Thread");
    worker->moveToThread(&thread);
    QObject::connect(&thread, &QThread::started, worker, &Worker::run);
    thread.start();

    qInfo() << "Finished" << QThread::currentThread();

    return a.exec();
}
