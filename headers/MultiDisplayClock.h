// include pre-processor directives
#include <iostream>
#include "Clock.h"

// use C++ standard library namespace
using namespace std;

// class declaration
class MultiDisplayClock : public Clock
{
    private:
        // field to store multidisplay clocks's day
        int day;
    public:
        // This method sets the day, hr, min, and sec fields
        // to the specified day, hr, min, and sec if they are
        // valid, else it sets the hr, min, and sec to 0.
        void setTime(int, int, int, int);
        // This method returns the day, hr, min, and sec fields by assigning
        // their values to the specified day, hr, min, and sec.
        void getTime(int&, int&, int&, int&) const;
        // This method displays the day, hr, min, and sec fields to
        // stdout in HH:MM:SS Day format.
        void printTime() const;
        // This method increments the day field by one and if
        // the before increment day is y, the day is reset
        // to 1.
        void incrementDay();
};

// method definitions 
void MultiDisplayClock::setTime(int hours, int minutes, int seconds, int days)
{
    if (hours >= 0 && hours < 24) {
        this->Clock::setHour(hours);
    } else {
        this->Clock::setHour(0);
    }

    if (minutes >= 0 && minutes < 60) {
        this->Clock::setMinute(minutes);
    } else {
        this->Clock::setMinute(0);
    }

    if (seconds >= 0 && seconds < 60) {
        this->Clock::setSecond(seconds);
    } else {
        this->Clock::setSecond(0);
    }

    if (days >= 1 && hours < 7) {
        day = days;
    } else {
        day = 1;
    }
}

void MultiDisplayClock::getTime(int& hours, int& minutes , int& seconds, int& days) const
{
    this->Clock::getHour(hours);
    this->Clock::getMinute(minutes);
    this->Clock::getSecond(seconds);
    days = day;
}

void MultiDisplayClock::incrementDay()
{
    day++;
    if (day > 6){
        day = 1;
    }
}

void MultiDisplayClock::printTime() const
{
    int hours;
    int minutes;
    int seconds;

    this->Clock::getHour(hours);
    this->Clock::getMinute(minutes);
    this->Clock::getSecond(seconds);

    if (hours < 10){
        cout << "0";
    }
    cout << hours << ":";

    if (minutes < 10){
        cout << "0";
    }
    cout << minutes << ":";

    if (seconds < 10){
        cout << "0";
    }
    cout << seconds << " - ";

    switch (day) {
        case 1:
            cout << "Sunday" << endl;
            break;
        case 2:
            cout << "Monday" << endl;
            break;
        case 3:
            cout << "Tuesday" << endl;
            break;
        case 4:
            cout << "Wednesday" << endl;
            break;
        case 5:
            cout << "Thursday" << endl;
            break;
        case 6:
            cout << "Friday" << endl;
            break;
        case 7:
            cout << "Saturday" << endl;
            break;
    }
}