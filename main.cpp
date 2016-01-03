#include "HolidayPackageManager.h"

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>

//QString Task::textColor()
//{
//    switch(QDate::currentDate().month())
//    {
//    case 12:
//    case 1:
//    case 2:
//        return "\e[96m"; // Winter - Light Cyan
//    case 3:
//    case 4:
//    case 5:
//        return "\e[91m"; // Spring - Light Red
//    case 6:
//    case 7:
//    case 8:
//        return "\e[92m"; // Summer - Light Green
//    case 9:
//    case 10:
//    case 11:
//        return "\e[93m"; // Autumn - Light Yellow
//    default:
//        return "\e[39m"; // Default
//    }
//}

int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);
    application.setApplicationName("holiday");
    application.setApplicationVersion("0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("Application for obtaining information about upcoming holidays.");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption packageDirOption(QStringList() << "p" << "packageDir", "Set package directory.", "directory");
    parser.addOption(packageDirOption);

    QCommandLineOption packageListOption(QStringList() << "l" << "packageList", "Show list of loaded packages.");
    parser.addOption(packageListOption);

    parser.process(application);

    HolidayPackageManager manager;
    QTextStream stream(stdout);

    stream << "Loading packages... ";

    QString const packageDir = parser.value(packageDirOption).isEmpty() ? QDir::currentPath() +
                                                                          "/packages" : parser.value(packageDirOption);
    if (manager.loadPackages(packageDir))
    {
        stream << "Done!\n";

        int const packagesCount = manager.packagesCount();
        stream << packagesCount << " ";
        packagesCount == 1 ? stream << "package was loaded.\n" : stream << "packages were loaded.\n";
    }
    else
        stream << "Failed!\n";

    if (parser.isSet(packageListOption))
    {
        stream << "\nList of packages: \n";
        foreach (const HolidayPackage &package, manager.getPackages()) {
            stream << "\n" << package.getName() << " package";
            stream << "\nVersion: " << package.getVersion();
            stream << "\nYear: " << package.getYear();
            stream << "\nDescription: " << package.getDescription();
            stream << "\nHolidays count: " << package.getHolidaysCount() << "\n";
        }
    }


    //    QTextStream stream(stdout);
    //    QDate const & currentDate = QDate::currentDate();

    //    stream << "Today is "  << displayColoredText(currentDate.toString("dddd, d MMMM yyyy")) <<
    //           " (" << currentDate.dayOfYear() << " day of the year)\n";

    //    Holiday const holiday = upcomingHoliday();
    //    QDate const & holidayDate = holiday.date();

    //    stream << "There are " << displayColoredText(printDays(currentDate.daysTo(holidayDate))) << " until next holiday\n\n";
    //    stream << "Upcoming holiday is " << displayColoredText(holiday.title()) << " (" << holidayDate.toString("d MMMM") << ")\n";
}
