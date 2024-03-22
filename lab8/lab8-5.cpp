#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

const int arSize = 20;

class IntArray {
private:
    int m_len{ 0 };
    int* m_data{ nullptr };
public:
    IntArray(int len)
        : m_len{ len }
    {
        m_data = new int[m_len];
    }

    ~IntArray() {
        if (m_data) delete[] m_data;
    }

    // Friend functions
    friend void setArray(IntArray& arr, int* data, int size);
    friend void displayArray(const IntArray& arr);
};

void setArray(IntArray& arr, int* data, int size) {
    if (size != arr.m_len) {
        std::cout << "Error: Array sizes do not match!" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        arr.m_data[i] = data[i];
    }
}

void displayArray(const IntArray& arr) {
    for (int i = 0; i < arr.m_len; ++i) {
        std::cout << "[" << i << "]" << arr.m_data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int data[arSize];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < arSize; ++i) {
        data[i] = rand() % 100;
    }

    IntArray arr{ arSize };
    setArray(arr, data, arSize);
    displayArray(arr);

    return 0;
}
