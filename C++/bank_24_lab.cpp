#include<iostream>
#include<string.h>
using namespace std;

class bank{

    protected:
    int accno;
    char *name;

    public:
    bank(int a,const char *n){
        name=new char[strlen(n)+1];
        strcpy(name, n);

        accno=a;
    }
};

class savings: protected bank{
    float balance;

    public:
    savings(float b, int a,const char *n):bank(a, n){
        balance=b;
    }

    void display(){
        cout<<"Account: "<<accno<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Balance: "<<balance<<"\n";
    }
};

int main(){
    // bank b1();
    savings s1(20000,201,"Mann");

    s1.display();

    return 0;
}