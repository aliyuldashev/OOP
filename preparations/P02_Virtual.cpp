#include <iostream>
using namespace std;
const int nbuf = 3;


class  Person {
private:
    const char* m_name;
    const char* m_gender;
    const char* m_date;
public:
    friend class UniStudent;
    friend class Employee;
    Person(const char* name, const char* gender, const char* date) {
        m_name = new char[strlen(name) + 1];
        m_name = name;
       
        m_gender = new char[strlen(gender) + 1];
        m_gender = gender;
        
        m_date = new char[strlen(date) + 1];
        m_date = date;

    }
    Person(UniStudent& st) {

    }

    ~Person() {
        delete[]m_name;
        delete[]m_gender;
        delete[]m_date;
    }

    virtual void info() {
        cout << "Name: " << m_name << endl;
        cout << "Gender: " << m_gender << ", Date of birth: " << m_date << endl;
    }
    
};

class UniStudent : private Person {
    int g_date;
    const char* m_m;
public:
    friend class Person;
    UniStudent(const char* name, const char* gender, const char* date, int year, const char* m):g_date{ year }
    {
        m_name = new char[strlen(name) + 1];
        m_name = name;

        m_gender = new char[strlen(gender) + 1];
        m_gender = gender;

        m_date = new char[strlen(date) + 1];
        m_date = date;

        m_m = new char[strlen(m) + 1];
        m_m = m;
    }
    ~UniStudent() {
        delete[]m_m;
    }
    void info() {
        cout << "Name: " << m_name << endl;
        cout << "Gender: " << m_gender << ", Date of birth: " << m_date << endl;
        cout << "Graduation year: " << g_date << ", Major: " << m_m<< endl;

    }
};

class Employee : private Person {
    int e_id;
    double m_salary;
public:
    friend class Person;
    Employee(const char* name, const char* gender, const char* date, int id, double salary):
     e_id{id}, m_salary{salary}
    {

    }
    void info() {
        cout << "Name: " << m_name << endl;
        cout << "Gender: " << m_gender << ", Date of birth: " << m_date << endl;
        cout << "Employee ID: " << e_id << ", Hourly salary: " << m_salary << endl;
    }
};

int main() {
    // Person: name, gender, date of birth
    Person James{ "James", "Male", "Jan 1, 1980" };
    // University Student: name, gender, date of birth, graudation year, major
    UniStudent Alice{ "Alice", "Female", "Jan 1, 2002", 2026, "ISE" };
    // Employee: name, gender, date of birth, employee ID, hourly salary
    Employee Victor{ "Victor", "Male", "Jan 1, 1995", 123456, 20.5 };

    Person* member[nbuf] = { &James, &Alice, &Victor };
    int i;
    for (i = 0; i < nbuf; ++i) {
        cout << "===================== info. of our member ";
        cout << i + 1 << " =====================" << endl;
        member[i]->Info();
    }

    return 0;
}
