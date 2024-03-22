#include "DateFunctions.h"

unsigned long unixtime_to_julian(const int& year, const int& month, const int& day) 
{
    unsigned long a = (14 - month) / 12;
    unsigned long y = year + 4800 - a;
    unsigned long m = month + 12 * a - 3;
    unsigned long JDN = day + (153 * m + 2) / 5 + (365 * y) + (y / 4) - (y / 100) + (y / 400) - 32045;
    return JDN;
}

bool isleap(const int& year)
{
    return;
}