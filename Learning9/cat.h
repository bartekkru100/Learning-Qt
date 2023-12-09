#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QString>

class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);
    ~Cat();
    void setAge(int age);
    void setName(QString name);
    int getAge();
    QString getName();
private:
    int age;
    QString name;
signals:
};

#endif // CAT_H
