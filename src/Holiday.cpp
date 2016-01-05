#include "Holiday.h"

Holiday::Holiday()
{
}

Holiday::Holiday(const QDate &date, const QString &name) : date(date), name(name)
{
}

QDate Holiday::getDate() const
{
    return date;
}

QString Holiday::getName() const
{
    return name;
}

void Holiday::setDate(const QDate &value)
{
    date = value;
}

void Holiday::setName(const QString &value)
{
    name = value;
}
