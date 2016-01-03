#ifndef HOLIDAY_H
#define HOLIDAY_H

#include <QDate>

class Holiday
{
public:

    explicit Holiday();
    explicit Holiday(const QDate &date, const QString &name);

    QDate getDate() const;

    QString getName() const;

    void setDate(const QDate &value);

    void setName(const QString &value);

private:
    QDate date;
    QString name;
};

#endif // HOLIDAY_H
