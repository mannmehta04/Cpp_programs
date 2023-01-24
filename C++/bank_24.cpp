#include<iostream>
#include<string.h>

using namespace std;

class Bank {
    char *name;
    int accno;

    public:
    Bank(char *n, int a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        accno = a;
    }

    void display_bank() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accno << endl;
    }
};

class Savings : private Bank {
    float bal;

    public:
    Savings(char *n, int a, float bal) : Bank(n, a) {
        this->bal = bal;
    }

    void display() {
        display_bank();
        cout << "Balance: " << bal << endl;
    }
};

int main() {
    Savings a1("Mann", 201, 14000);

    a1.display();
    return 0;
}