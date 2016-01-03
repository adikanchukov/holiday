#include "HolidayPackage.h"

HolidayPackage::HolidayPackage()
{
}

HolidayPackage::HolidayPackage(const QString &name, size_t version, size_t year, const QString &description,
                               const HolidayPackage::Holidays &holidays) : name(name), version(version), year(year), description(description),
    holidays(holidays)
{

}

QString HolidayPackage::getName() const
{
    return name;
}

size_t HolidayPackage::getVersion() const
{
    return version;
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

void HolidayPackage::setName(const QString &value)
{
    name = value;
}

void HolidayPackage::setVersion(const size_t &value)
{
    version = value;
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
