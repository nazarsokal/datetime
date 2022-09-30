    DateTime dt{ DateTime::now() };
    std::cout << "Default date: " << dt.day << "/" << dt.month << "/" << dt.year << " " << dt.hours << ":" << dt.minutes << ":" << dt.seconds << "\n";

    DateTime dt_changed_mins = dt.addMinutes(180);
    std::cout << "Adding minutes: " << dt_changed_mins.day << "/" << dt_changed_mins.month << "/" << dt_changed_mins.year << " " << dt_changed_mins.hours << ":" << dt_changed_mins.minutes << ":" << dt_changed_mins.seconds << "\n";

    DateTime dt_changed_sec = dt.addSeconds(300);
    std::cout << "Adding seconds: " << dt_changed_sec.day << "/" << dt_changed_sec.month << "/" << dt_changed_sec.year << " " << dt_changed_sec.hours << ":" << dt_changed_sec.minutes << ":" << dt_changed_sec.seconds << "\n";

    DateTime dt_changed_hrs = dt.addHours(48);
    std::cout << "Adding hours: " << dt_changed_hrs.day << "/" << dt_changed_hrs.month << "/" << dt_changed_hrs.year << " " << dt_changed_hrs.hours << ":" << dt_changed_hrs.minutes << ":" << dt_changed_hrs.seconds << "\n";
    
    DateTime dt_changed_monthes = dt.addMonth(24);
    std::cout << "Adding monthes: " << dt_changed_monthes.day << "/" << dt_changed_monthes.month << "/" << dt_changed_monthes.year << " " << dt_changed_monthes.hours << ":" << dt_changed_hrs.minutes << ":" << dt_changed_monthes.seconds << "\n";
    
    DateTime dt_changed_days = dt.addDays(40);
    std::cout << "Adding days: " << dt_changed_days.day << "/" << dt_changed_days.month << "/" << dt_changed_days.year << " " << dt_changed_days.hours << ":" << dt_changed_days.minutes << ":" << dt_changed_days.seconds << "\n";

    DateTime dt_changed_years = dt.addYears(40);
    std::cout << "Adding years: " << dt_changed_years.day << "/" << dt_changed_years.month << "/" << dt_changed_years.year << " " << dt_changed_years.hours << ":" << dt_changed_days.minutes << ":" << dt_changed_years.seconds << "\n";

    DateTime dt_total;
    std::cout << "Total Month: " << dt_total.totalMonth() << "\n";

    std::cout << "Total Days: " << dt_total.totalDays() << "\n";

    std::cout << "Total Minutes: " << dt_total.totalMinutes() << "\n";

    std::cout << "Total Seconds: " << dt_total.totalSeconds() << "\n";