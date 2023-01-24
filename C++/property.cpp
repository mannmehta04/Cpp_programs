#include<iostream>
using namespace std;

class property{
    char address[20];
    int room;
    char condition[2];

    public:

    void setproperty();
    void display();
};

void property::display(){
    cout<<"Matching Results: \n";
    cout<<address<<"\t"<<room<<"\t"<<condition<<endl;
}

void property::setproperty(){
        cout<<"Enter Address \n";
        cin>>address;
        cout<<"Enter Room number \n";
        cin>>room;
        cout<<"Enter Condition \n";
        cin>>condition;
    }

class Rental : public property{
    
    public:

    int rent;
    int cap;

    void setrental(){
        cout<<"Enter Rent \n";
        cin>>rent;
        cout<<"Enter Capacity \n";
        cin>>cap;
    }
};

class Sale : public property{
    
    public:
    
    int price;

    void setsale(){
        cout<<"Enter Price for Sale Property: \n";
        cin>>price;
    }
};

int main(){
    Rental r1[2];
    Sale s1[2];

    cout<<"Enter 1-1 Detail for Rental and Sale Properties Each. \n";
    for(int i=0; i<2; i++){
        cout<<"Renatal Property "<<i+1<<": \n";
        r1[i].setproperty();
        cout<<"Sale Property "<<i+1<<": \n";
        s1[i].setproperty();
    }

    for(int i=0; i<2; i++){
        r1[i].setrental();
    }

    for(int i=0; i<2; i++){
        s1[i].setsale();
    }

    for(int i=0; i<2; i++){
        if(r1[i].rent<5000 && s1[i].price<600000){
            r1[i].display();
            s1[i].display();
        }
        else{
            cout<<"No more data to Display. \n";
        }
    }

    return 0;
}