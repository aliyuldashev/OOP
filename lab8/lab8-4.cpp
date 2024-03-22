#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int m_hours;
    int m_minutes;
    int m_seconds;

public:
    Time(int hours, int minutes, int seconds) : m_hours(hours), m_minutes(minutes), m_seconds(seconds) {}

    void printTime() 
    {

        cout << setfill('0') << setw(2) << m_hours << ":";

        cout << setfill('0') << setw(2) << m_minutes << ":";

        cout << setfill('0') << setw(2) << m_seconds;

        if (m_hours < 12)
            cout << " AM";
        else
            cout << " PM";

        cout << endl;
    }
    void printTime() const
    {
        int hours = m_hours;
        string period = " AM";
        if (m_hours >= 12)
        {
            period = " PM";
            if (m_hours > 12)
                hours = m_hours - 12;
        }

        
        cout << setfill('0') << setw(2) << hours << ":";

        cout << setfill('0') << setw(2) << m_minutes << ":";

        cout << setfill('0') << setw(2) << m_seconds << period;

        cout << endl;
    }
};

int main()
{
    const Time t0{7, 3, 5};
    Time t1{13, 45, 9};
    const Time t2{t1};

    cout << "t0: ";
    t0.printTime();
    cout << "t1: ";
    t1.printTime();
    cout << "t2: ";
    t2.printTime();

    return 0;
}
