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

char* DateTime::toString()
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
    int dt_hours = dt_now.hours;


    while (new_min / 60 >= 1)
    {
        dt_hours++;
        new_min -= 60;
    }

    DateTime new_dt(dt_now.year, dt_now.month, dt_now.day, dt_hours, new_min, dt_now.seconds);
    return new_dt;

}

DateTime DateTime::addSeconds(int iSeconds)
{
    DateTime dt_now = DateTime::now();

    int dt_mins = dt_now.minutes;
    int new_seconds = dt_now.seconds + iSeconds;


    while (new_seconds / 60 >= 1)
    {
        dt_mins++;
        new_seconds -= 60;
    }

    DateTime new_dt(dt_now.year, dt_now.month, dt_now.day, dt_now.hours, dt_mins, new_seconds);
    return new_dt;
}

DateTime DateTime::addHours(int iHours)
{
    DateTime dt_now = DateTime::now();

    int new_hours = dt_now.hours + iHours;
    int dt_day = dt_now.day;


    while (new_hours / 24 >= 1)
    {
        dt_day++;
        new_hours -= 24;
    }

    DateTime new_dt(dt_now.year, dt_now.month, dt_day, new_hours, dt_now.minutes, dt_now.seconds);
    return new_dt;
}
DateTime DateTime::addMonth(int iMonthes)
{
    DateTime dt_now = DateTime::now();

    int new_month = dt_now.month + iMonthes;
    int dt_year = dt_now.year;


    while (new_month / 12 >= 1)
    {
        dt_year++;
        new_month -= 12;
    }

    DateTime new_dt(dt_year, new_month, dt_now.day, dt_now.hours, dt_now.minutes, dt_now.seconds);
    return new_dt;
}

DateTime DateTime::addDays(int iDays)
{
    DateTime dt_now = DateTime::now();

    int new_days = dt_now.day + iDays;
    int dt_month = dt_now.month;

    int a = 0;

    while (new_days / 30 >= 1)
    {
        if (a % 2 == 0)
        {
            dt_month++;
            new_days -= 30;
            a++;
        }
        else
        {
            dt_month++;
            new_days -= 31;
            a++;
        }
    }

    DateTime new_dt(dt_now.year, dt_month, new_days, dt_now.hours, dt_now.minutes, dt_now.seconds);
    return new_dt;
}

DateTime DateTime::addYears(int iYears)
{
    DateTime dt_now = DateTime::now();

    int new_years = dt_now.year + iYears;

    DateTime new_dt(new_years, dt_now.month, dt_now.day, dt_now.hours, dt_now.minutes, dt_now.seconds);
    return new_dt;
}

long DateTime::totalMonth()
{
    DateTime dt_now = DateTime::now();

    long t_m_d = (dt_now.year * 12) + dt_now.month;

    return t_m_d;
}

long DateTime::totalDays()
{
    DateTime dt_now = DateTime::now();

    long t_d_d = (dt_now.year * 365) + (dt_now.month * 30) + dt_now.day;

    return t_d_d;
}

long DateTime::totalMinutes()
{
    DateTime dt_now = DateTime::now();

    long t_m_d = (dt_now.year * 525949);

    return t_m_d;
}

long DateTime::totalSeconds()
{
    DateTime dt_now = DateTime::now();

    long t_m_d = (dt_now.year * 31556926);

    return t_m_d;
}