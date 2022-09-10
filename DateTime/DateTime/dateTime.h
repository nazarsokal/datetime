#ifndef DateTime_h
#define DateTime_h

class DateTime
{
public:
    int day;
    
    int month;
    
    int year;
    
    int hours;
    
    int minutes;
    
    int seconds;
    
    DateTime();
    
    DateTime(int day, int month, int year);
    
    DateTime(int day, int month, int year, int hours, int minutes, int seconds);
    
    static DateTime now();
    
    char* toString();
    
    DateTime addMinutes(int iMinutes);
    
    DateTime addSeconds(int minutes);
    
    DateTime addMonth(int minutes);
    
    DateTime addDays(int minutes);
    
    DateTime addYears(int minutes);
    
    DateTime addHours(int minutes);
    
};


#endif
