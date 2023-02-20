// This program is in progress.

#include<iostream>
#include<map>
#define max 3
using namespace std;

class mapping{
    int freq;
    string name;
    map<string,int> dataMap;

    public:

    void input();
    void lexiograph();
    void display();
};

void mapping::input(){
    for(int i=0;i<max;i++){
        cout<<"Enter Name: ";
        cin>>name;
        cout<<endl;
        // dataMap[id]=name;

        dataMap[name]++;
    }
}

void mapping::display(){
    map<string, int>::iterator it = dataMap.begin();
    cout<<"\t Key \t\t Frequency"<<endl;
    while(it!=dataMap.end()){
        cout<<"\t "<<it-> first<<" \t\t "<<it->second<<endl;
        it++;
    }
}

// This part is still in progress.
void mapping::lexiograph(){
    map<string, int>::iterator it1 = dataMap.begin();
    map<string, int>::iterator it2 = dataMap.begin();
    it2++;

    cout<<"Sorting: "<<endl;

    while(it1!=dataMap.end()){
        while(it2!=dataMap.end()){
            if(it1->second > it2->second){
                
            }
        }
    }
}

int main(){

    mapping m1;
    m1.input();
    m1.display();
    // m1.lexiograph();

    return 0;
}