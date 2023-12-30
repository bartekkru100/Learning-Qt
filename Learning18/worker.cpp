#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{}

int Worker::count() const
{
    return m_count;
}

void Worker::setCount(int newCount)
{
    m_count = newCount;
}

bool Worker::producer() const
{
    return m_producer;
}

void Worker::setProducer(bool newProducer)
{
    m_producer = newProducer;
}

QTimer *Worker::timer() const
{
    return m_timer;
}

void Worker::setTimer(QTimer *newTimer)
{
    m_timer = newTimer;
}

void Worker::consume(int value)
{
    qInfo() << this << "Consuming" << value << QThread::currentThread();
}

void Worker::start()
{
    qInfo() << this << "Starting" << QThread::currentThread();
    m_timer = new QTimer(this);
    QObject::connect(m_timer, &QTimer::timeout, this, &Worker::timeout);

    if(m_producer)
    {
        qInfo() << this << "Starting timer" << QThread::currentThread();
        m_timer->setInterval(1000);
        m_timer->start();
    }
}

void Worker::quit()
{
    qInfo() << this << "Quitting" << QThread::currentThread();
    m_timer->stop();
    emit finished();
}

void Worker::timeout()
{
    int value = QRandomGenerator::global()->bounded(1000);
    qInfo() << this << "Producing" << value <<  QThread::currentThread();
    emit produced(value);
    m_count++;
    if(m_count == 5) quit();
}
