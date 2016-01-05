#ifndef HOLIDAYOUTPUTER_H
#define HOLIDAYOUTPUTER_H

#include <HolidayPackageManager.h>

#include <QSharedPointer>
#include <QTextStream>

class HolidayOutputer
{
public:
    explicit HolidayOutputer(const QSharedPointer<HolidayPackageManager> manager);

    void beginLoadingPackages();

    void endLoadingPackages(bool succeed);

    void showPackageList();

private:

    static QString textColor();

    QString makeTextColored(const QString &text) const;

    QSharedPointer<HolidayPackageManager> manager;
    QTextStream stream;
};

#endif // HOLIDAYOUTPUTER_H
