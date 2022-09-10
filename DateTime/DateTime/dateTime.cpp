#include <iostream>
#include "dateTime.h"
#include <ctime>

DateTime::DateTime()
{
    this->day = 1;
    this->month = 1;
    this->year = 1;
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

DateTime::DateTime(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

DateTime::DateTime(int day, int month, int year, int hours, int minutes, int seconds)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

DateTime DateTime::now()
{
    time_t now = time(0);
    tm* tmNow = gmtime(&now);
    
    DateTime output;
    
    output.day = tmNow->tm_mday;
    output.month = tmNow->tm_mon + 1;
    output.year = tmNow->tm_year + 1900;
    output.hours = tmNow->tm_hour + 3;
    output.minutes = tmNow->tm_min;
    output.seconds = tmNow->tm_sec;
    /*
     int    tm_sec   seconds [0,61]
          int    tm_min   minutes [0,59]
          int    tm_hour  hour [0,23]
          int    tm_mday  day of month [1,31]
          int    tm_mon   month of year [0,11]
          int    tm_year  years since 1900
          int    tm_wday  day of week [0,6] (Sunday = 0)
          int    tm_yday  day of year [0,365]
          int    tm_isdst daylight savings flag
     */
    
    return output;
}
