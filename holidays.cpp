/***************************************************************************
 *   Copyright (C) 2020 by Vladimir Mirnyy, mirnyy.eu                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the MIT License                                 *
 ***************************************************************************/

#include "holidays.h"

using namespace datenamespace;


year_month_day easter::western_gregorian(const uint16_t y)
{
    const uint16_t a = y % 19;
    const uint16_t b = y / 100;
    const uint16_t c = y % 100;
    const uint16_t d = b / 4;
    const uint16_t e = b % 4;
    const uint16_t f = (b + 8) / 25;
    const uint16_t g = (b-f+1)/3;
    const uint16_t h = (19*a+b-d-g+15)%30;
    const uint16_t i = c/4;
    const uint16_t k = c%4;
    const uint16_t l = (32+2*e+2*i-h-k)%7;
    const uint16_t m = (a+11*h+22*l)/451;
    const uint16_t p = h+l-7*m+114;
    const uint16_t easterMonth = p/31;
    const uint16_t easterDay = (p%31)+1;
    return year(y)/easterMonth/easterDay;
}

year_month_day easter::eastern_julian(const uint16_t y)
{
    const uint16_t a = y % 4;
    const uint16_t b = y % 7;
    const uint16_t c = y % 19;
    const uint16_t d = (19*c + 15) % 30;
    const uint16_t e = (2*a + 4*b - d + 34) % 7;
    const uint16_t p = d + e + 114;
    const uint16_t easterMonth = p/31;
    const uint16_t easterDay = (p%31)+1;
    return year(y)/easterMonth/easterDay;  // +13 days to convert from Julian to Gregorian calender
}

year_month_day easter::eastern_gregorian(const uint16_t y)
{
    return sys_days{easter::eastern_julian(y)} + days{13};  // +13 days to convert from Julian to Gregorian calender
}


//====================================================================================
year_month_day holidays::new_years_day(const uint16_t y)
{
    return year(y)/1/1;
}

year_month_day holidays::easter(const uint16_t y)
{
    return easter::western_gregorian(y);
}

year_month_day holidays::good_friday(const uint16_t y)
{
    return sys_days{easter::western_gregorian(y)} - days{2};
}

year_month_day holidays::christmas_eve(const uint16_t y)
{
    return year(y)/12/24;
}

year_month_day holidays::christmas_day(const uint16_t y)
{
    return year(y)/12/25;
}


//====================================================================================
year_month_day holidays_us::new_years_day(const uint16_t y)
{
    return move_from_weekend(holidays::new_years_day(y));
}

year_month_day holidays_us::ml_king_day(const uint16_t y)
{
    return year_month_day{year(y)/1/mon[3]};
}

year_month_day holidays_us::presidents_day(const uint16_t y)
{
    return year_month_day{year(y)/2/mon[3]};
}

year_month_day holidays_us::memorial_day(const uint16_t y)
{
    return year_month_day{year(y)/5/mon[last]};
}

year_month_day holidays_us::independence_day(const uint16_t y)
{
    return move_from_weekend(year(y)/7/4);
}

year_month_day holidays_us::labor_day(const uint16_t y)
{
    return year_month_day{year(y)/9/mon[1]};
}

year_month_day holidays_us::columbus_day(const uint16_t y)
{
    return year_month_day{year(y)/10/mon[2]};
}

year_month_day holidays_us::veterans_day(const uint16_t y)
{
    return move_from_weekend(year(y)/11/11);
}

year_month_day holidays_us::thanksgiving_day(const uint16_t y)
{
    return year_month_day{year(y)/11/thu[4]};
}

year_month_day holidays_us::christmas_day(const uint16_t y)
{
    return move_from_weekend(holidays::christmas_day(y));
}

year_month_day holidays_us::move_from_weekend(const year_month_day &ymd)
{
    if (weekday{ymd} == Saturday) return sys_days{ymd} - days{1};
    if (weekday{ymd} == Sunday)   return sys_days{ymd} + days{1};
    return ymd;
}


//====================================================================================
year_month_day holidays_de::easter_monday(const uint16_t y)
{
    return sys_days{easter::western_gregorian(y)} + days{1};
}

year_month_day holidays_de::labor_day(const uint16_t y)
{
    return year_month_day{year(y)/5/1};
}

year_month_day holidays_de::pentecost(const uint16_t y)
{
    return sys_days{easter::western_gregorian(y)} + days{49};
}

year_month_day holidays_de::pentecost_monday(const uint16_t y)
{
    return sys_days{easter::western_gregorian(y)} + days{50};
}

year_month_day holidays_de::ascension(const uint16_t y)
{
    return sys_days{easter::western_gregorian(y)} + days{39};
}

year_month_day holidays_de::german_unification(const uint16_t y)
{
    return year_month_day{year(y)/10/3};
}

year_month_day holidays_de::christmas_day2(const uint16_t y)
{
    return sys_days(holidays::christmas_day(y)) + days{1};
}


year_month_day holidays_de::epiphany(const uint16_t y)
{
    return year_month_day{year(y)/1/6};
}

year_month_day holidays_de::womens_day(const uint16_t y)
{
    return year_month_day{year(y)/3/8};
}

year_month_day holidays_de::corpus_christi(const uint16_t y)
{
    return sys_days{easter::western_gregorian(y)} + days{60};
}

year_month_day holidays_de::assumption(const uint16_t y)
{
    return year_month_day{year(y)/8/15};
}

year_month_day holidays_de::childrens_day(const uint16_t y)
{
    return year_month_day{year(y)/9/20};
}

year_month_day holidays_de::reformation(const uint16_t y)
{
    return year_month_day{year(y)/10/31};
}

year_month_day holidays_de::hallowmas(const uint16_t y)
{
    return year_month_day{year(y)/11/1};
}

year_month_day holidays_de::prayer_and_repentance(const uint16_t y)
{
    uint16_t day = 22;
    while (weekday{year(y)/11/day} != Wednesday && day > 0) day--;
    return year(y)/11/day;
}

