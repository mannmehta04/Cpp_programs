
// This program is in progress.

#include<iostream>
#include<queue>
#define max 3
using namespace std;

class priority{
    int que[3];
    priority_queue<int> pq1;
    priority_queue<int> temp;

    public:

    void display();
    void add(int data);
    void remove();
    void checkPriority(int data);
};

void priority::display(){
    while(!pq1.empty()){
        cout<<pq1.top()<<endl;
        pq1.pop();
    }
}

void priority::add(int dummyData){
    pq1.push(dummyData);
    // display();
}

void priority::remove(){
    while(!pq1.empty()){
        pq1.pop();
        // display();
    }
}

// void priority::checkPriority(int data){
//     bool found;

//     while(!pq1.empty()){
//         if(pq1.top()==data){
//             found=1;
            
//         }
//     }
// }

int main(){
    
    priority p1;
    p1.add(10);
    p1.add(20);
    p1.add(30);
    p1.remove();
    
    return 0;
}
