#include <iostream>
#include "dateTime.h"

int main()
{
//    std::cout << "Year: " << DateTime::now().year << "\n";
//    std::cout << "Month: " << DateTime::now().month << "\n";
//    std::cout << "Day: " << DateTime::now().day << "\n";
//    std::cout << "Hours: " << DateTime::now().hours << "\n";
//    std::cout << "Minutes: " << DateTime::now().minutes << "\n";
//    std::cout << "Seconds: " << DateTime::now().seconds << "\n";
    
    DateTime dt { DateTime::now() };
    std::cout<< dt.day << "/" << dt.month << "/" << dt.year << " " << dt.hours << ":" << dt.minutes << ":" << dt.seconds << "\n";
    
    DateTime dt_changed = dt.addMinutes(180);
    std::cout<< dt_changed.day << "/" << dt_changed.month << "/" << dt_changed.year << " " << dt_changed.hours << ":" << dt_changed.minutes << ":" << dt_changed.seconds << "\n";
}
