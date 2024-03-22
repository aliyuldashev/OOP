#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
const int arSize = 20;

class IntArrayHandler; // Forward declaration

class IntArray
{
private:
    int m_len{0};
    int *m_data{nullptr};

public:
    friend class IntArrayHandler;

    IntArray(int len)
        : m_len{len}
    {
        m_data = new int[m_len];
    }

    ~IntArray()
    {
        if (m_data)
            delete[] m_data;
    }
};

class IntArrayHandler
{
private:
    IntArray *m_array{nullptr};

public:
    IntArrayHandler(IntArray *arr)
        : m_array{arr} {}

    void setIntArray(IntArray *arr)
    {
        m_array = arr;
    }

    void setArray(int *data, int size)
    {
        if (m_array)
        {
            for (int i = 0; i < size; ++i)
            {
                m_array->m_data[i] = data[i];
            }
        }
    }

    void displayArray() const;

    void stat() const;
};

void IntArrayHandler::displayArray() const
{
    if (m_array)
    {
        for (int i = 0; i < arSize; ++i)
        {
            cout << "[" << i << "]" << m_array->m_data[i] << " " << endl;
        }
        cout << endl;
    }
}

void IntArrayHandler::stat() const
{
    if (m_array)
    {
        int sum = 0, min = m_array->m_data[0], max = m_array->m_data[0];

        for (int i = 0; i < arSize; ++i)
        {
            sum += m_array->m_data[i];
            if (m_array->m_data[i] < min)
                min = m_array->m_data[i];
            if (m_array->m_data[i] > max)
                max = m_array->m_data[i];
        }

        cout << "Sum: " << sum << endl;
        cout << "Min: " << min << endl;
        cout << "Max: " << max << endl;
    }
}

int main()
{
    int data1[arSize], data2[arSize];
    IntArray ar1{arSize}, ar2{arSize};
    srand(static_cast<unsigned int>(time(NULL)));

    for (int i = 0; i < arSize; ++i)
    {
        data1[i] = rand() % 100;
        data2[i] = rand() % 100;
    }

    IntArrayHandler handler{&ar1};
    handler.setArray(data1, arSize);
    cout << "==ar1: displayArray()===" << endl;
    handler.displayArray();
    cout << "======ar1: stat()=======" << endl;
    handler.stat();
    cout << "==========================" << endl;

    handler.setIntArray(&ar2);
    handler.setArray(data2, arSize);
    cout << "==ar2: displayArray()===" << endl;
    handler.displayArray();
    cout << "======ar2: stat()=======" << endl;
    handler.stat();
    cout << "==========================" << endl;

    return 0;
}
