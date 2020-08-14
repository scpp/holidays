/***************************************************************************
 *   Copyright (C) 2020 by Vladimir Mirnyy, mirnyy.eu                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the MIT License                                 *
 ***************************************************************************/

#pragma once

#include <cstdint>

#if !defined(__clang__) && __cplusplus > 201907L
    // C++20 is supported
    // This is not tested yet
    #include <chrono>
    namespace datenamespace = std::chrono;
#else
    #include "date.h"
    namespace datenamespace = date;
#endif


class easter
{
public:
    // Easter Sunday in Gregorian calender, Anonymous Gregorian algorithm: https://en.wikipedia.org/wiki/Computus
    static datenamespace::year_month_day western_gregorian(const uint16_t y);

    // Easter Sunday in Eastern Orthodox Church (Julian calender), Meeus's Julian algorithm: https://en.wikipedia.org/wiki/Computus
    static datenamespace::year_month_day eastern_julian(const uint16_t y);

    // Easter Sunday in Eastern Orthodox Church (Gregorian calender)
    static datenamespace::year_month_day eastern_gregorian(const uint16_t y);
};


//====================================================================================
class holidays
{
public:
    // New Year's Day            Jan 1
    static datenamespace::year_month_day new_years_day(const uint16_t y);

    // Good Friday: Friday before Easter
    static datenamespace::year_month_day good_friday(const uint16_t y);

    // Christmas Day         Dec 24
    static datenamespace::year_month_day christmas_eve(const uint16_t y);

    // Christmas Day         Dec 25
    static datenamespace::year_month_day christmas_day(const uint16_t y);
};


//====================================================================================
class holidays_us : public holidays
{
public:
    //   http://www.usa.gov/citizens/holidays.shtml

    // New Year's Day            Jan 1 (moved from weekend, if needed)
    static datenamespace::year_month_day new_years_day(const uint16_t y);

    // Martin Luther King, Jr. third Mon in Jan
    static datenamespace::year_month_day ml_king_day(const uint16_t y);

    // Washington's Birthday third Mon in Feb
    static datenamespace::year_month_day presidents_day(const uint16_t y);

    // Memorial Day: last Mon in May
    static datenamespace::year_month_day memorial_day(const uint16_t y);

    // Independence Day      July 4
    static datenamespace::year_month_day independence_day(const uint16_t y);

    // Labor Day             first Mon in Sept
    static datenamespace::year_month_day labor_day(const uint16_t y);

    // Columbus Day          second Mon in Oct
    static datenamespace::year_month_day columbus_day(const uint16_t y);

    // Veterans Day          Nov 11
    static datenamespace::year_month_day veterans_day(const uint16_t y);

    // Thanksgiving Day      fourth Thur in Nov
    static datenamespace::year_month_day thanksgiving_day(const uint16_t y);

    // Christmas Day         Dec 25 (moved from weekend, if needed)
    static datenamespace::year_month_day christmas_day(const uint16_t y);

    // Saturday holidays are moved to Fri; Sun to Mon
    static datenamespace::year_month_day move_from_weekend(const datenamespace::year_month_day& ymd);
};


//====================================================================================
class holidays_de : public holidays
{
public:
    // Monday after Easter
    static datenamespace::year_month_day easter_monday(const uint16_t y);

    // Labor Day (Tag der Arbeit)   first of May
    static datenamespace::year_month_day labor_day(const uint16_t y);

    // Pentecost (Pfingsten):  7 weeks (49 days) after Easter
    static datenamespace::year_month_day pentecost(const uint16_t y);

    // Monday after Pentecost (Pfingstmontag):  50 days after Easter
    static datenamespace::year_month_day pentecost_monday(const uint16_t y);

    // Ascension day (Christi Himmelfahrt):  39 days after Easter
    static datenamespace::year_month_day ascension(const uint16_t y);

    // anniversary of German unification:  3rd of October
    static datenamespace::year_month_day german_unification(const uint16_t y);

    // Second Christmas Day         Dec 26
    static datenamespace::year_month_day christmas_day2(const uint16_t y);


    // Epiphany (Heilige Drei Koenige)         Jan 6   (only in Baden-Württemberg, Bayern, Sachsen-Anhalt)
    static datenamespace::year_month_day epiphany(const uint16_t y);

    // International women's day         March 8  (only in Berlin)
    static datenamespace::year_month_day womens_day(const uint16_t y);

    // Corpus Christi (Fronleichnam)  60 days after Easter  (only in Baden-Württemberg, Bayern, Hessen, Nordrhein-Westfalen, Rheinland-Pfalz, Saarland)
    static datenamespace::year_month_day corpus_christi(const uint16_t y);

    // Assumption day (Maria Himmelfahrt)  Aug 28 (only in Saarland)
    static datenamespace::year_month_day assumption(const uint16_t y);

    // Children's day (Weltkindertag)      Sep 20 (only in Thüringen)
    static datenamespace::year_month_day childrens_day(const uint16_t y);

    // Reformation day (Reformationstag)   Okt 31 (only in Brandenburg, Bremen, Hamburg, Mecklenburg-Vorpommern, Niedersachsen, Sachsen, Sachsen-Anhalt, Schleswig-Holstein, Thüringen)
    static datenamespace::year_month_day reformation(const uint16_t y);

    // Hallowmas (Allerheiligen)      Nov 1 (only in Thueringen)
    static datenamespace::year_month_day hallowmas(const uint16_t y);

    // Day of Prayer and Repentance (Buß- und Bettag)  Wed before Nov 23  (only in Sachsen)
    static datenamespace::year_month_day prayer_and_repentance(const uint16_t y);
};

