#ifndef HOLIDAYPACKAGEMANAGER_H
#define HOLIDAYPACKAGEMANAGER_H

#include "HolidayPackage.h"

class HolidayPackageManager
{
public:
    typedef QVector<HolidayPackage> HolidayPackages;

    explicit HolidayPackageManager();

    bool loadPackages(const QString &packageDirPath);

    int packagesCount() const;

    HolidayPackages getPackages() const;

    const Holiday upcomingHoliday(bool *ok) const;

private:
    HolidayPackages packages;
};

#endif // HOLIDAYPACKAGEMANAGER_H
