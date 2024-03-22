#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

class Test
{
private:
    int integer, ID;
    static int number;

public:
    Test(int num) : ID{number + 1}, integer{num}
    {
        number += 1;
    }

    static int NumOfObjects()
    {
        return number;
    }

    int getData()
    {
        return integer;
    }

    int getID()
    {
        return ID;
    }
};

int Test::number = 0; // Initialize the static member

int main()
{
    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;

    Test t1{10}, t2{20}, t3{30}, t4{40};
    cout << "[t1] data: " << t1.getData() << ", id: " << t1.getID() << endl;
    cout << "[t2] data: " << t2.getData() << ", id: " << t2.getID() << endl;
    cout << "[t3] data: " << t3.getData() << ", id:" << t3.getID() << endl;
    cout << "[t4] data: " << t4.getData() << ", id: " << t4.getID() << endl;
    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;

    return 0;
}
