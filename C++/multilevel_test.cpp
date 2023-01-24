#include<iostream>

using namespace std; 

class P{

public:

int x=0;

void print() { cout<<" Inside P"; }
void display(){
    cout<<"P's display"<<x;
}

};

class Q:public P{ 
    
    public: 
    int x=1;

    void print() 
    { cout<<" Inside Q"<<x; 
    }
    virtual void display(){
        cout<<"Q's virtual";
    }
};

class R:public P{

    public:
    int x=2;

    void display(){
        cout<<"R's virtual"<<x;
    }
};

class S:public Q, public R{

    public:
    int x=3;

    void display(){
        cout<<"S's virtual"<<x;
    }
};

int main()

{

S obj;
obj.display();

// P *p;
// R r;
// p=&r;
// p->display();

// r.print();

}