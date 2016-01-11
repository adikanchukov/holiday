#ifndef HOLIDAYPACKAGEMANAGER_H
#define HOLIDAYPACKAGEMANAGER_H

#include "HolidayPackage.h"

class HolidayPackageManager
{
public:

    enum LoadPackagesStatus
    {
        OK,
        NOT_EXISTS_DIRECTORY,
        INVALID_DIRECTORY,
        NO_PACKAGES
    };

    typedef QVector<HolidayPackage> HolidayPackages;

    explicit HolidayPackageManager();

    LoadPackagesStatus loadPackages(const QString &packageDirPath);

    int packagesCount() const;

    HolidayPackages getPackages() const;

    const Holiday upcomingHoliday(bool *ok) const;

private:
    HolidayPackages packages;
};

#endif // HOLIDAYPACKAGEMANAGER_H
