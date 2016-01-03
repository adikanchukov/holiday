#include "HolidayPackageExtractor.h"
#include "HolidayPackageManager.h"

#include <QDir>
#include <QFileInfo>

HolidayPackageManager::HolidayPackageManager()
{
}

bool HolidayPackageManager::loadPackages(const QString &packageDirPath)
{
    if (!QFileInfo::exists(packageDirPath))
        return false;

    QFileInfo packageDirInfo(packageDirPath);

    if (!packageDirInfo.isDir() || !packageDirInfo.isReadable())
        return false;

    QDir packageDir(packageDirPath);

    QFileInfoList const packageFileInfoList = packageDir.entryInfoList(QDir::Files | QDir::Readable);

    foreach (const QFileInfo &packageFileInfo, packageFileInfoList)
    {
        bool ok = false;
        HolidayPackage const package = HolidayPackageExtractor::extract(packageFileInfo, &ok);

        if (ok)
            packages.push_back(package);
    }

    return !packages.isEmpty();
}

int HolidayPackageManager::packagesCount() const
{
    return packages.count();
}

HolidayPackageManager::HolidayPackages HolidayPackageManager::getPackages() const
{
    return packages;
}
