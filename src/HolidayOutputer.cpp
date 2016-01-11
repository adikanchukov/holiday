#include "HolidayOutputer.h"

const QString DEFAULT_TEXT_COLOR = "\e[39m";

HolidayOutputer::HolidayOutputer(const QSharedPointer<HolidayPackageManager> manager) : manager(manager), stream(stdout)
{

}

void HolidayOutputer::beginLoadingPackages()
{
    stream << "Loading packages... ";
}

void HolidayOutputer::endLoadingPackages(HolidayPackageManager::LoadPackagesStatus status)
{
    switch(status)
    {
    case HolidayPackageManager::OK:
    {
        stream << "Done!\n";
        int const packagesCount = manager->packagesCount();
        stream << packagesCount << " ";
        packagesCount == 1 ? stream << "package was loaded.\n" : stream << "packages were loaded.\n";
    }
    case HolidayPackageManager::NOT_EXISTS_DIRECTORY:
    {
        stream << "Failed!\nSpecified package directory does not exists.\n";
        break;
    }
    case HolidayPackageManager::INVALID_DIRECTORY:
    {
        stream << "Failed!\nSpecified package directory is invalid.\n";
        break;
    }
    case HolidayPackageManager::NO_PACKAGES:
    {
        stream << "Failed!\nThere are no packages in the specified package directory.\n";
        break;
    }
    default:
    {
        stream << "\nUnexpected status, please contact developers.\n";
        break;
    }
    }
}

void HolidayOutputer::showPackageList()
{
    stream << "\nList of packages: \n";
    foreach (const HolidayPackage &package, manager->getPackages())
    {
        stream << "\n" << makeTextColored(package.getName() + " package");
        stream << "\nYear: " << package.getYear();
        stream << "\nDescription: " << package.getDescription();
        stream << "\nHolidays count: " << package.getHolidaysCount() << "\n";
    }
}

void HolidayOutputer::showUpcomingHoliday()
{
    stream << "\nToday is "  << makeTextColored(QDate::currentDate().toString("dddd, d MMMM yyyy")) <<
               " (" << QDate::currentDate().dayOfYear() << " day of the year).";

    bool ok = false;
    const Holiday holiday = manager->upcomingHoliday(&ok);
    int const daysLeft = QDate::currentDate().daysTo(holiday.getDate());

    if (!ok)
        stream << "\nNo upcoming holiday that i know.\n";
    else
    {
        QString const holidayName = holiday.getName();
        QString const holidayDateFormat = holiday.getDate().year() == QDate::currentDate().year() ? "d MMMM" : "d MMMM yyyy";
        QString const holidayInfoText = " left until " + makeTextColored(holidayName) +
                                        " (" + holiday.getDate().toString(holidayDateFormat) + ").";
        if (daysLeft == 0)
            stream << makeTextColored("Today") << " is " << makeTextColored(holidayName) << "!\n";
        else if (daysLeft == 1)
            stream << "\nThere is " << makeTextColored("1 day") << holidayInfoText << "\n";
        else
            stream << "\nThere are " << makeTextColored(QString::number(daysLeft) +  " days") << holidayInfoText << "\n";
    }
}

QString HolidayOutputer::textColor()
{
    static QString color;

    if (color.isEmpty())
        switch(QDate::currentDate().month())
        {
        case 12:
        case 1:
        case 2:
        {
            color = "\e[96m"; // Winter - Light Cyan
            break;
        }
        case 3:
        case 4:
        case 5:
        {
            color = "\e[91m"; // Spring - Light Red
            break;
        }
        case 6:
        case 7:
        case 8:
        {
            color = "\e[92m"; // Summer - Light Green
            break;
        }
        case 9:
        case 10:
        case 11:
        {
            color = "\e[93m"; // Autumn - Light Yellow
            break;
        }
        default:
        {
            color = DEFAULT_TEXT_COLOR;
            break;
        }
        }

    return color;
}

QString HolidayOutputer::makeTextColored(const QString &text) const
{
    return textColor() + text + DEFAULT_TEXT_COLOR;
}
