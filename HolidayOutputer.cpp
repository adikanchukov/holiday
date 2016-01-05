#include "HolidayOutputer.h"

const QString DEFAULT_TEXT_COLOR = "\e[39m";

HolidayOutputer::HolidayOutputer(const QSharedPointer<HolidayPackageManager> manager) : manager(manager), stream(stdout)
{

}

void HolidayOutputer::beginLoadingPackages()
{
    stream << "Loading packages... ";
}

void HolidayOutputer::endLoadingPackages(bool succeed)
{
    if (succeed)
    {
        stream << "Done!\n";
        int const packagesCount = manager->packagesCount();
        stream << packagesCount << " ";
        packagesCount == 1 ? stream << "package was loaded.\n" : stream << "packages were loaded.\n";
    }
    else
        stream << "Failed!\n";

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
