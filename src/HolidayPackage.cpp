#include "HolidayPackage.h"

HolidayPackage::HolidayPackage()
{
}

HolidayPackage::HolidayPackage(const QString &fileName, const QString &name, size_t year, const QString &description,
                               const HolidayPackage::Holidays &holidays) : fileName(fileName), name(name), year(year), description(description),
    holidays(holidays)
{

}

QString HolidayPackage::getFileName() const
{
    return fileName;
}

QString HolidayPackage::getName() const
{
    return name;
}

size_t HolidayPackage::getYear() const
{
    return year;
}

QString HolidayPackage::getDescription() const
{
    return description;
}

HolidayPackage::Holidays HolidayPackage::getHolidays() const
{
    return holidays;
}

int HolidayPackage::getHolidaysCount() const
{
    return holidays.count();
}

void HolidayPackage::setFileName(const QString &value)
{
    fileName = value;
}

void HolidayPackage::setName(const QString &value)
{
    name = value;
}

void HolidayPackage::setYear(const size_t &value)
{
    year = value;
}

void HolidayPackage::setDescription(const QString &value)
{
    description = value;
}

void HolidayPackage::setHolidays(const Holidays &value)
{
    holidays = value;
}
