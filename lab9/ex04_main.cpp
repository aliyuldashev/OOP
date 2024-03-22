#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Banana
{
protected:
    string color = "Yellow";
    string name = "Red";

public:
    Banana(const string &nam = "banana", const string &col = "yellow") : name{nam}, color{col} {};

    const string &getName() const
    {
        return name;
    };

    const string &getColor() const
    {
        return color;
    };
};

class Apple : public Banana
{
public:
    Apple(const string &nam = "apple", const string &col = "red") : Banana{nam, col} {};
};
class RedBanana : public Banana
{
public:
    RedBanana(const string &nam = "banana", const string &col = "red") : Banana{nam, col} {};
};

int main()
{
    Apple a{"red"};
    Banana b;
    RedBanana c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
