#include<iostream>
#include<string.h>
#define CHAR_MAX 50

using namespace std;

class Student {
    char *id_number;
    char *name;
    int rank;
    float spi;

    public:
    Student(char *id, char *n, int r, float s) {
        id_number = new char[strlen(id) + 1];
        strcpy(id_number, id);

        name = new char[strlen(name) + 1];
        strcpy(name, n);

        rank = r;
        spi = s;
    }

    //Copy constructor
    Student(const Student& s) {
        id_number = new char[strlen(s.id_number) + 1];
        strcpy(id_number, s.id_number);

        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);

        rank = s.rank;
        spi = s.spi;
    }

    //Default constructor
    Student() {
        id_number = new char[CHAR_MAX];
        name = new char[CHAR_MAX];
        rank = -1;
        spi = -1;
    }

    //no need to pass reference because of copy constructor
    Student& operator =(Student s) {
        delete[] this->id_number;
        delete[] this->name;

        id_number = new char[strlen(s.id_number) + 1];
        strcpy(id_number, s.id_number);

        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);

        rank = s.rank;
        spi = s.spi;

        return *this;
    }

    friend int operator ==(Student, Student);

    ~Student() {
        delete[] id_number;
        delete[] name;
    }
};

int operator ==(Student s1, Student s2) {
    if(s1.rank == s2.rank)
        return 1;
    return 0;
}

int main() {

    Student s1("22CP303", "George", 5, 8.80f);
    Student s2(s1);

    Student s3;

    s3 = s1;

    //All objects represents same student, but in different memory

    if(s1 == s2) 
        cout << "SAME RANK" << endl;
    return 0;
}