# holidays
**US and German holidays calculation**

## Summary

Calculates holidays for a given year: fixed days as well as floating holidays like Easter.

US holidays are properly moved, if they fall on a weekend.

The implementation is very short and expressive thank to the date-library 
https://github.com/HowardHinnant/date

The date-library will be cloned automatically under build/external during build process.
When the C++20 will be fully supported, the date-library will not be needed. All date-time manipulations
will come from the standard header <chrono>.


## Build & Test

Make following steps to build the library after you cloned it (make sure you have git, cmake and g++ installed):

    $ cd holidays
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    
Run the example, after the build has been succeded

    $ ./holidays
