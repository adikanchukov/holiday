#ifndef HOLIDAYPACKAGEEXTRACTOR_H
#define HOLIDAYPACKAGEEXTRACTOR_H

#include "HolidayPackage.h"

#include <QFileInfo>

class HolidayPackageExtractor
{
    enum class Header
    {
        Name,
        Year,
        Count
    };

    enum class Holiday
    {
        Date,
        Name,
        Count
    };

public:
    static HolidayPackage extract(const QFileInfo &packageFileInfo, bool *ok);

};

#endif // HOLIDAYPACKAGEEXTRACTOR_H
