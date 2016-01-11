#include "HolidayPackageExtractor.h"
#include "HolidayPackageManager.h"

#include <QDir>
#include <QFileInfo>

#include <limits>

HolidayPackageManager::HolidayPackageManager()
{
}

HolidayPackageManager::LoadPackagesStatus HolidayPackageManager::loadPackages(const QString &packageDirPath)
{
    if (!QFileInfo::exists(packageDirPath))
        return NOT_EXISTS_DIRECTORY;

    QFileInfo packageDirInfo(packageDirPath);

    if (!packageDirInfo.isDir() || !packageDirInfo.isReadable())
        return INVALID_DIRECTORY;

    QDir packageDir(packageDirPath);

    QFileInfoList const packageFileInfoList = packageDir.entryInfoList(QDir::Files | QDir::Readable);

    foreach (const QFileInfo &packageFileInfo, packageFileInfoList)
    {
        bool ok = false;
        HolidayPackage const package = HolidayPackageExtractor::extract(packageFileInfo, &ok);

        if (ok)
            packages.push_back(package);
    }

    if (packages.isEmpty())
        return NO_PACKAGES;
    else
        return OK;
}

int HolidayPackageManager::packagesCount() const
{
    return packages.count();
}

HolidayPackageManager::HolidayPackages HolidayPackageManager::getPackages() const
{
    return packages;
}

const Holiday HolidayPackageManager::upcomingHoliday(bool *ok) const
{
    *ok = false;
    Holiday result(QDate(std::numeric_limits<int>::max(), 12, 31), QString());

    foreach (const HolidayPackage& package, packages)
        foreach (const Holiday& holiday , package.getHolidays()) {
            const QDate& holidayDate = holiday.getDate();
            if (holidayDate >= QDate::currentDate() && holidayDate < result.getDate())
            {
                *ok = true;
                result = holiday;
            }
        }

    return result;
}
