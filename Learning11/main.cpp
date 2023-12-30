#include <QCoreApplication>
#include <QDebug>>
#include <QTextStream>>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
}

void test()
{
    qDebug() << "test";
    qInfo() << "test";
    qWarning() << "test";
    qCritical() << "test";
    //qFatal() << "fatal";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream qin(stdin);

    bool running = true;
    do
    {
        std::cout << "Enter a command (start, stop, test, or exit)\n";
        QString command = qin.readLine();
        qInfo() << "You entered:" << command;
        if(command.toUpper() == "START") qInstallMessageHandler(myMessageOutput);
        if(command.toUpper() == "STOP") qInstallMessageHandler(0);
        if(command.toUpper() == "TEST") test();
        if(command.toUpper() == "EXIT") running = false;


    }while(running);

    return a.exec();
}
