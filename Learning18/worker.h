#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    int count() const;
    void setCount(int newCount);

    bool producer() const;
    void setProducer(bool newProducer);

    QTimer *timer() const;
    void setTimer(QTimer *newTimer);

signals:
    void produced(int value);
    void finished();

public slots:
    void consume(int value);
    void start();
    void quit();

private:
    QTimer *m_timer;
    bool m_producer;
    int m_count;

    void timeout();
};

#endif // WORKER_H
