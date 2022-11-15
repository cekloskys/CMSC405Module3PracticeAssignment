// include pre-processor directive
#include <iostream>
#include "./headers/MultiDisplayClock.h"

using namespace std;

int main() {
    // declare a Clock object using no-arg constructor
    Clock clock1;

    cout << "Clock 1 Time : ";
    clock1.printTime();

    // declare local variables that will store
    // the values in the Clock fields
    int hours;
    int minutes;
    int seconds;

    // call setter
    clock1.setTime(5,4,30);

    // call getter
    clock1.getTime(hours, minutes, seconds);

    // display values in local variables
    cout << "Clock 1 Hours : " << hours << endl;
    cout << "Clock 1 Minutes : " << minutes << endl;
    cout << "Clock 1 Seconds : " << seconds << endl;
    cout << "Clock 1 Time : ";
    clock1.printTime();

    // call other Class methods
    clock1.incrementSeconds();
    cout << "Clock 1 Time : ";
    clock1.printTime();

    clock1.incrementMinutes();
    cout << "Clock 1 Time : ";
    clock1.printTime();

    clock1.incrementHours();
    cout << "Clock 1 Time : ";
    clock1.printTime();

    // declare a Clock object using no-arg constructor
    Clock clock2;
    clock2.setTime(5,4,30);
    cout << "Clock 2 Time : ";
    clock2.printTime();

    // use ternary operator to display true or false instead of 1 or 0
    cout << "Clock1 equals Clock2 ? " << 
        (clock1.equalTime(clock2) ? "true" : "false") << endl;

    // declare and initialize Clock object using no-arg constructor
    Clock clock3;
    cout << "Clock 3 Time : ";
    clock3.printTime();
  
    // declare and initialize Clock object using three-arg constructor
    Clock clock4(2,35,50);
    cout << "Clock 5 Time : ";
    clock4.printTime();

    // declare and initialize Clock object using one-arg constructor
    Clock clock5(clock4);
    cout << "Clock 5 Time : ";
    clock5.printTime();

    cout << "Clock4 equals Clock5 ? " << 
        (clock4.equalTime(clock5) ? "true" : "false") << endl;

    // declare and initialize MultiDisplayClock object using no-arg constructor
    MultiDisplayClock mClock1;
    mClock1.setTime(1,50,30,2);
    cout << "MultiDisplayClock 1 Time - Day : ";
    mClock1.printTime();

    mClock1.incrementDay();
    cout << "MultiDisplayClock 1 Time - Day : ";
    mClock1.printTime();

    // declare local variable that will store
    // the value in the MultiDisplayClock field
    int day;
    mClock1.getTime(hours, minutes, seconds, day);
    
    // display values in local variables
    cout << "MultiDisplayClock 1 Hours : " << hours << endl;
    cout << "MultiDisplayClock 1 Minutes : " << minutes << endl;
    cout << "MultiDisplayClock 1 Seconds : " << seconds << endl;
    cout << "MultiDisplayClock 1 Day : " << day << endl;
}