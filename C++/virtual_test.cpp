#include<iostream>

using namespace std; 

class P{

public:

void print() { cout<<" Inside P"; }
void display(){
    cout<<"P's display";
}

};

class Q: public P
{ 
    public: 
    void print() 
    { cout<<" Inside Q"; 
    }
    virtual void display(){
        cout<<"Q's virtual";
    }
};

class R: public Q{

    public:
    void display(){
        cout<<"R's virtual";
    }
};

int main()

{

P *p;
Q q;


p=&q;
p->display();

// r.print();

}