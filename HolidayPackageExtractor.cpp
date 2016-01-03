#include "HolidayPackageExtractor.h"

#include <QTextStream>

static const char SEPARATOR = ';';

HolidayPackage HolidayPackageExtractor::extract(const QFileInfo &packageFileInfo, bool *ok)
{
    QFile packageFile(packageFileInfo.absoluteFilePath());
    HolidayPackage result;


    if (!packageFile.open(QIODevice::ReadOnly))
    {
        *ok = false;
        return result;
    }

    QTextStream packageStream(&packageFile);

    QStringList const packageHeader = packageStream.readLine().split(SEPARATOR);

    if (packageHeader.count() != static_cast<int>(Header::Count))
    {
        *ok = false;
        return result;
    }

    result.setName(packageHeader.at(static_cast<int>(Header::Name)));
    result.setVersion(packageHeader.at(static_cast<int>(Header::Version)).toInt());
    result.setYear(packageHeader.at(static_cast<int>(Header::Year)).toInt());
    result.setDescription(packageStream.readLine());

    HolidayPackage::Holidays holidays;

    while (!packageStream.atEnd())
    {
        QStringList const holidayString = packageStream.readLine().split(SEPARATOR);

        if (holidayString.count() == static_cast<int>(Holiday::Count))
            holidays.push_back(::Holiday(QDate::fromString(holidayString.at(static_cast<int>(Holiday::Date)) +
                                                           QString::number(result.getYear()), "ddMMyyyy"),
                                         holidayString.at(static_cast<int>(Holiday::Name))));
    }

    if (holidays.isEmpty())
        *ok = false;
    else
    {
        *ok = true;
        result.setHolidays(holidays);
    }

    return result;
}
