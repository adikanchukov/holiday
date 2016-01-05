#include "HolidayPackageManager.h"
#include "HolidayOutputer.h"

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDir>

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

    QSharedPointer<HolidayPackageManager> manager(new HolidayPackageManager());
    HolidayOutputer outputer(manager);

    outputer.beginLoadingPackages();

    QString const packageDir = parser.value(packageDirOption).isEmpty() ? QDir::currentPath() +
                                                                          "/packages" : parser.value(packageDirOption);
    bool const packagesLoaded = manager->loadPackages(packageDir);

    outputer.endLoadingPackages(packagesLoaded);

    if (packagesLoaded)
        if (parser.isSet(packageListOption))
            outputer.showPackageList();

    //    QTextStream stream(stdout);
    //    QDate const & currentDate = QDate::currentDate();

    //    stream << "Today is "  << displayColoredText(currentDate.toString("dddd, d MMMM yyyy")) <<
    //           " (" << currentDate.dayOfYear() << " day of the year)\n";

    //    Holiday const holiday = upcomingHoliday();
    //    QDate const & holidayDate = holiday.date();

    //    stream << "There are " << displayColoredText(printDays(currentDate.daysTo(holidayDate))) << " until next holiday\n\n";
    //    stream << "Upcoming holiday is " << displayColoredText(holiday.title()) << " (" << holidayDate.toString("d MMMM") << ")\n";
}
