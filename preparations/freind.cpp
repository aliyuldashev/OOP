#include <iostream>
using namespace std;
class Storage
{
private:
    int m_nValue;
    double m_dValue;

public:
    Storage(int nValue, double dValue) : m_nValue{nValue}, m_dValue{dValue} {}

    // Make the Display class a friend of Storage
    friend class Display;
};
class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst) : m_displayIntFirst{displayIntFirst} {}

    void displayItem(const Storage &storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue;
        else
            std::cout << storage.m_dValue << ' ' << storage.m_nValue;

        std::cout << '\n';
    }
};
int main()
{
    Storage storage{5, 6.7};
    Display dispa(false);
    dispa.displayItem(storage);
    return 0;
};