#include<iostream>

using namespace std;

class homework{
    int x;
    int y;

    public:

    homework(int a,int b){
        x=a;
        y=b;
    }
    void display(){
        cout<<"x:"<<x<<endl<<"y:"<<y<<endl;
    }
    int operator <(homework ob);
};

int homework :: operator <(homework ob){

    if(x<ob.x && y<ob.y){
        return 1;
    }
    return 0;
}

int main(){
    homework h1(3,4);
    homework h2(1,2);
    if(h1<h2){
        cout<<"h1 is smaller tham h2";
    }
    else{
        cout<<"h2 is smaller than h1";
    }
}