/***************************************************************************
 *   Copyright (C) 2020 by Vladimir Mirnyy, mirnyy.eu                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the MIT License                                 *
 ***************************************************************************/

#include "holidays.h"

#include <iostream>


using namespace datenamespace;
using namespace std;


int main(int argc, char** argv)
{
    // Sample year
    uint16_t y = 2021;
    
    if (argc > 1) {
        // take year from the first parameter
        y = static_cast<uint16_t>(std::stoi(argv[1]));
    }

    cout << "US holidays in " << y << endl;
    cout << holidays_us::new_years_day(y) << endl;
    cout << holidays_us::ml_king_day(y) << endl;
    cout << holidays_us::presidents_day(y) << endl;
    cout << holidays_us::memorial_day(y) << endl;
    cout << holidays_us::independence_day(y) << endl;
    cout << holidays_us::labor_day(y) << endl;
    cout << holidays_us::columbus_day(y) << endl;
    cout << holidays_us::veterans_day(y) << endl;
    cout << holidays_us::thanksgiving_day(y) << endl;
    cout << holidays_us::christmas_day(y) << endl << endl;
    
    cout << "German holidays (general only) in " << y << endl;
    cout << holidays_de::new_years_day(y) << endl;
    cout << holidays_de::good_friday(y) << endl;
    cout << holidays_de::pentecost(y) << endl;
    cout << holidays_de::pentecost_monday(y) << endl;
    cout << holidays_de::ascension(y) << endl;
    cout << holidays_de::german_unification(y) << endl;
    cout << holidays_de::christmas_day(y) << endl;
    cout << holidays_de::christmas_day2(y) << endl;
    
    return 0;
}
