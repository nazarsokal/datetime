#include <iostream>
#include "dateTime.h"
#include <cstring>
#pragma warning (disable: 496)
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

char*  DateTime::toString()
{
    char* output = new char[128];
    
    std::strcat(output, std::to_string(day).c_str());
    std::strcat(output, "/");
    std::strcat(output, std::to_string(month).c_str());
    std::strcat(output, "/");
    std::strcat(output, std::to_string(year).c_str());
    std::strcat(output, " ");
    std::strcat(output, std::to_string(hours).c_str());
    std::strcat(output, ":");
    std::strcat(output, std::to_string(minutes).c_str());
    std::strcat(output, ":");
    std::strcat(output, std::to_string(seconds).c_str());
    std::strcat(output, ":");
    
    return output;
}

DateTime DateTime::addMinutes(int iMinutes)
{
    DateTime dt_now = DateTime::now();
    
    int new_min = dt_now.minutes + iMinutes;
    
    //std::cout << "Minutes: " << new_dt.minutes << "\n";  DateTime new_dt(dt_now.year,dt_now.month,dt_now.day,dt_now.hours,new_min,dt_now.seconds);
      /*dt_now.minutes += iMinutes;*/
    
    if(new_min / 60 >= 1)
    {
        for (int i = 0; i <= new_min / 60; i++)
        {
            new_min -= 60;
            dt_now.hours++;
        }
    }
    
    DateTime new_dt(dt_now.year,dt_now.month,dt_now.day,dt_now.hours,new_min,dt_now.seconds);
    return new_dt;
    
}

//DateTime addSeconds(int minutes)
//{
//
//}
//
//
//DateTime addMonth(int minutes)
//{
//
//}
//
//
//DateTime addDays(int minutes)
//{
//
//}
//
//
//DateTime addYears(int minutes)
//{
//
//}
//
//
//DateTime addHours(int minutes)
//{
//
//}

