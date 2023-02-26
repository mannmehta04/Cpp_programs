#include<iostream>
#include<map>
#define max 3
using namespace std;

class mapping{
    int freq;
    string data;
    map<string,int> dataMap;

    public:

    void input();
    void display();
};

void mapping::input(){
    for(int i=0;i<max;i++){
        cout<<"Enter Data: ";
        cin>>data;
        cout<<endl;
        // dataMap[id]=name;

        dataMap[data]++;
    }
}

void mapping::display(){
    map<string, int>::iterator it = dataMap.begin();
    cout<<"Printing Data in Dictionary Order:\n\n";
    cout<<"\t Key \t\t Frequency"<<endl;
    while(it!=dataMap.end()){
        cout<<"\t "<<it-> first<<" \t\t "<<it->second<<endl;
        it++;
    }
}

int main(){

    mapping m1;
    m1.input();
    m1.display();

    return 0;
}