#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout << "Please enter your name:" << Qt::endl;

    QString name = qin.readLine();
    qout << "You entered" << name << "\n" << Qt::endl;
    qout << "Enter your age\n";

    qout.flush();

    int age = qin.readLine().toInt();

    return a.exec();
}
