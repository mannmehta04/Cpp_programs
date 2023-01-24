#include<iostream>
using namespace std;

class num2;

class num1{

    int x;
    public:

    num1(){
        cin>>x;
    }
    friend void sum(num1, num2);
};

class num2{
    
    int y;
    public:

    num2(){
        cin>>y;
    }
    friend void sum(num1, num2);
};

void sum(num1 obj1, num2 obj2){
    if(obj1.x>obj2.y){
        cout<<obj1.x<<" is greater";
    }
    else{
        cout<<obj2.y<<" is greater";
    }
    // cout<<obj1.x+obj2.y;
}

int main(){

    num1 n1;
    num2 n2;
    sum(n1,n2);
    return 0;
}