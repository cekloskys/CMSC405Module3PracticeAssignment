// include pre-processor directives
#include <iostream>

// use C++ standard library namespace
using namespace std;

// class declaration
class Clock
{
    private:
        // field to store clock's hour
        int hr; 
        // field to store clock's minutes
        int min;
        // field to store clock's seconds
        int sec;
    public:
        // This constructor sets the time to 
        // 00:00:00.
        Clock();
        // This constructor sets the hr, min, and sec
        // field values to the specified hr, min, and sec.
        Clock(int, int, int);
        // This constructor sets the hr, min, and sec
        // field values to otherClock's hr, min, and sec.
        Clock(const Clock&);
        // This method sets the hr field to the
        // specified hr if the specified hr is between
        // 0 and 24, else it sets the hr field to 0.
        void setHour(int);
        // This method sets the min field to the
        // specified min if the specified min is between
        // 0 and 60, else it sets the min field to 0.
        void setMinute(int);
        // This method sets the sec field to the
        // specified sec if the specified sec is between
        // 0 and 60, else it sets the sec field to 0.
        void setSecond(int);
        // This method sets the hr, min, and sec fields
        // to the specified hr, min, and sec if they are
        // valid, else it sets the hr, min, and sec to 0.
        void setTime(int, int, int);
        // getter methods for fields
        // This method returns the hr field by assigning
        // its value to the specified hr.
        void getHour(int&) const;
        // This method returns the min field by assigning
        // its value to the specified min.
        void getMinute(int&) const;
        // This method returns the sec field by assigning
        // its value to the specified sec.
        void getSecond(int&) const;
        // This method returns the hr, min, and sec fields by assigning
        // their values to the specified hr, min, and sec.
        void getTime(int&, int&, int&) const;
        // This method displays the hr, min, and sec fields to
        // stdout in HH:MM:SS format.
        void printTime() const;
        // This method increments the sec field by one and if
        // the before increment time is 23:59:59, the time is reset
        // to 00:00:00.
        void incrementSeconds();
        // This method increments the min field by one and if
        // the before increment time is 23:59:53, the time is reset
        // to 00:00:53.
        void incrementMinutes();
        // This method increments the hr field by one and if
        // the before increment time is 23:45:53, the time is reset
        // to 00:45:53.
        void incrementHours();
        // This method returns true if this time is equal to
        // otherClock, else it returns false
        bool equalTime(const Clock&) const;
};

// constructor and method definitions 
Clock::Clock()
{
    hr = 0;
    min = 0;
    sec = 0;
}

Clock::Clock(int hr, int min, int sec)
{
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}

Clock::Clock(const Clock& otherClock)
{
    this->hr = otherClock.hr;
    this->min = otherClock.min;
    this->sec = otherClock.sec;
}

void Clock::setHour(int hours)
{
    if (hours >= 0 && hours < 24) {
        hr = hours;
    } else {
        hr = 0;
    }
}

void Clock::setMinute(int minutes)
{
    if (minutes >= 0 && minutes < 60) {
        min = minutes;
    } else {
        min = 0;
    }
}

void Clock::setSecond(int seconds)
{
    if (seconds >= 0 && seconds < 60) {
        sec = seconds;
    } else {
        sec = 0;
    }
}

void Clock::setTime(int hours, int minutes, int seconds)
{
    if (hours >= 0 && hours < 24) {
        hr = hours;
    } else {
        hr = 0;
    }

    if (minutes >= 0 && minutes < 60) {
        min = minutes;
    } else {
        min = 0;
    }

    if (seconds >= 0 && seconds < 60) {
        sec = seconds;
    } else {
        sec = 0;
    }
}

void Clock::getHour(int& hours) const
{
    hours = hr;
}

void Clock::getMinute(int& minutes) const
{
    minutes = min;
}

void Clock::getSecond(int& seconds) const
{
    seconds = sec;
}

void Clock::getTime(int& hours, int& minutes , int& seconds) const
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

void Clock::printTime() const
{
    if (hr < 10){
        cout << "0";
    }
    cout << hr << ":";

    if (min < 10){
        cout << "0";
    }
    cout << min << ":";

    if (sec < 10){
        cout << "0";
    }
    cout << sec << endl;
}

void Clock::incrementHours()
{
    hr++;
    if (hr > 23){
        min = 0;
    }
}

void Clock::incrementMinutes()
{
    min++;
    if (min > 59){
        min = 0;
        incrementHours();
    }
}

void Clock::incrementSeconds()
{
    sec++;
    if (sec > 59){
        sec = 0;
        incrementMinutes();
    }
}

bool Clock::equalTime(const Clock& otherClock) const
{
    return (hr == otherClock.hr &&
        min == otherClock.min &&
        sec == otherClock.sec);
}