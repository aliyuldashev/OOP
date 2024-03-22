#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    string sex;
    int age;
    string mail;

    void introduceMyself()
    {
        cout << "My name is " << name << endl;
        cout << "I am " << sex << " and " << age << " years old" << endl;
        cout << "My email address is " << mail << endl;
    }
};

int main()
{
    Person ryu = {"VictorRyu", "male", 30, "IGS2130v1@inha.ac.kr"};
    Person laura = {"LauraLee", "female", 23, "IGS2130v2@inha.ac.kr"};
    ryu.introduceMyself();
    cout << endl;
    laura.introduceMyself();
    return 0;
}
