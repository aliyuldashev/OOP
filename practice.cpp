#include <iostream>
#include <string>
using namespace std;
class Student{
    int id;
    string name;
    
    public:
    Student(string nam, int i): id{i},name{nam};
    void showinfo(){
        cout<< "Id of this student is "<< id << " Name is "<< name << endl;

    }
    void setID(int givenID){
        id = givenID;
    }
    void setName(string givenName){
        name = givenName;
    }
};

int main(){
    Student s1,s2(12214750,"vali");
    s1.setID(12214760);
    s1.setName("ali");
    s2.setID(12290132);
    s1.showinfo();
    s2.showinfo();
    return 0;
}