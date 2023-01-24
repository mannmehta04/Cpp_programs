
 
78 lines (57 sloc) 1.37 KB
#include<iostream>
#include<string.h>

using namespace std;

class String1 {
    char *str;
    int length;

    public:
    String1(char *str) {
        length = strlen(str);
        this->str = new char[length + 1];
        strcpy(this->str, str); 
    }

    String1(const String1 &s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    void display() {
        cout << str << endl;
    }

    String1 operator+(String1 s) {
        char *answer = new char[length + s.length];

        int counter = 0;
        for(int i = 0; i < length; i++, counter++)
            answer[i] = str[i];

        for(int i = 0; i < s.length; i++, counter++)
            answer[counter] = s.str[i];

        String1 a(answer);
        return a;
    }

    String1 operator+(int offset) {
        char *answer = new char[length - offset];

        for(int i = 0; i < length - offset; i++) 
            answer[i] = str[i + offset];

        String1 a(answer);
        return a;
    }

    String1 operator=(String1 s) {
        delete[] str;

        str = new char[s.length];
        strcpy(str, s.str);

        length = s.length;

        return *this;
    }

    ~String1() {
        delete[] str;
    }
};

int main() {
    String1 s1("foo");
    String1 s2("bar");
    String1 s3 = s1 + s2;

    s3.display();

    s3 = s3 + 3;
    s3.display();

    return 0;
}
Footer
© 2022 GitHub, Inc.
Footer navigation

    Terms
    Privacy
    Security
    Status
    Docs
    Contact GitHub
    Pricing
    API
    Training
    Blog
    About

