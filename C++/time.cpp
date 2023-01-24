#include<iostream>
#include<string.h>

using namespace std;

class Time {
    int hour;
    int minute;
    int second;

    public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    void display() {
        cout << "HOUR: " << hour << endl;
        cout << "MINUTE: " << minute << endl;
        cout << "SECOND: " << second << endl;
    }

    friend Time operator+(Time t1, Time t2);
    friend Time operator+(int, Time);
    friend Time operator++(Time&);
    friend Time operator++(Time&, int);
};

Time operator+(Time t1, Time t2) {
    int second = t1.second + t2.second;
    int minute = t1.minute + t2.minute;
    int hour = t1.hour + t2.hour;

    minute += second / 60;
    second %= 60;

    hour += minute / 60;
    minute %= 60;

    Time t(hour, minute, second);
    return t;
}

Time operator+(int n, Time t1) {
    int second = n + t1.second;
    int minute = t1.minute;
    int hour = t1.hour;

    minute += second / 60;
    second %= 60;

    hour += minute / 60;
    minute %= 60;

    Time t(hour, minute, second);
    return t;
}

Time operator++(Time& t1) {
    int second = 1 + t1.second;
    int minute = t1.minute;
    int hour = t1.hour;

    minute += second / 60;
    second %= 60;

    hour += minute / 60;
    minute %= 60;

    t1.hour = hour;
    t1.minute = minute;
    t1.second = second;

    Time t(hour, minute, second);
    return t;
}

Time operator++(Time& t1, int n) {
    int second = 1 + t1.second;
    int minute = t1.minute;
    int hour = t1.hour;

    minute += second / 60;
    second %= 60;

    hour += minute / 60;
    minute %= 60;

    Time t(t1.hour, t1.minute, t1.second);

    t1.hour = hour;
    t1.minute = minute;
    t1.second = second;
    return t;
}

int main() {
    Time t1(2, 5, 10);
    Time t2(4, 7, 54);

    Time t3 = t1 + t2;

    t3++;
    ++t3;

    t3.display();
    return 0;
}