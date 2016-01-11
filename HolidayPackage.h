#ifndef HOLIDAYPACKAGE_H
#define HOLIDAYPACKAGE_H

#include "Holiday.h"

#include <QString>
#include <QVector>

class HolidayPackage
{

public:
    typedef QVector<Holiday> Holidays;

    explicit HolidayPackage();
    explicit HolidayPackage(const QString &fileName, const QString &name, size_t year, const QString &description, const Holidays &holidays);

    QString getFileName() const;

    QString getName() const;

    size_t getYear() const;

    QString getDescription() const;

    Holidays getHolidays() const;

    int getHolidaysCount() const;

    void setFileName(const QString &value);

    void setName(const QString &value);

    void setYear(const size_t &value);

    void setDescription(const QString &value);

    void setHolidays(const Holidays &value);

private:
    QString fileName;
    QString name;
    size_t year;
    QString description;
    Holidays holidays;
};

#endif // HOLIDAYPACKAGE_H
