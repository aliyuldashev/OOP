#include <iostream>
using namespace std;
int get(int, int, int(int, int));
int max(int, int);
int min(int, int);
int main()
{
    cout << get(3, 2, max) << endl;
    cout << get(3, 2, min);
    return 0;
}
int max(int num1, int num2)
{
    return ((num1) > (num2)) ? (num1) : (num2);
}
int min(int num1, int num2)
{
    return ((num1) < (num2)) ? (num1) : (num2);
}
int get(int num1, int num2, int (*p)(int, int))
{
    return p(num1, num2);
}
