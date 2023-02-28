#include<iostream>
#include<set>
using namespace std;

class setOperations{
    int data;
    set<int> set1;

    public:

    void input();
    void display();
    void remove();
    void search();
};

void setOperations::display(){
    set<int> :: iterator it = set1.begin();

    while(it!=set1.end()){
        cout<<"Data: "<<*it<<endl;
        it++;
    }
}

void setOperations::input(){
    int temp;
    cout<<"Enter Data:\t";
    cin>>temp;
    set1.insert(temp);
    // display();
}

void setOperations::remove(){

    set<int> :: iterator it = set1.begin();
    int pos;

    cout<<"Enter Position of Element to be Removed: ";
    cin>>pos;

    for(int i=0;i!=pos;i++){
        it++;
    }

    set1.erase(it);
    display();
}

void setOperations::search(){
    set<int> :: iterator it = set1.begin();
    int element, pos=0;
    bool found;

    cout<<"Enter Element to be Searched: ";
    cin>>element;

    while(*it!=element){
        pos++;
        it++;
    }

    it=set1.find(element);
    cout<<*it<<" found at "<<pos<<" position.";

    // display();
}

int main(){
    
    setOperations sOp1;
    sOp1.input();
    sOp1.input();
    sOp1.input();
    sOp1.remove();
    sOp1.search();

    return 0;
}