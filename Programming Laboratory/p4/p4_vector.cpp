#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> v1={2,4,6};

void display(){
    int i=0;

    for(const int &data : v1){
        cout<<"v1 ["<<i<<"]: "<<data<<endl;
        i++;
    }
}

void push(vector<int> &d){
    int data;   //can use template

    cout<<"Enter Data to be inserted:";
    cin>>data;

    d.push_back(data);
}

void push_random(vector<int> &d){
    int pos;
    int data;   //can use template

    cout<<"Enter Position at which Data will be inserted:";
    cin>>pos;
    cout<<"Enter Data to be inserted:";
    cin>>data;

    d.insert(d.begin()+(pos-1), data); 
}

void pop(vector<int> &d){
    d.pop_back();

    cout<<"Element Successfully Removed."<<endl;
}

void pop_random(vector<int> &d){
    vector<int>::iterator c;
    int pos;

    cout<<"Enter position of data to be removed:";
    cin>>pos;

    c = v1.begin();
    c = c + (pos-1);

    d.erase(c);
    cout<<"Element has been Removed."<<endl;
}

void sorting(vector<int> &d){
    cout<<"Current Data:"<<endl;
    display();

    sort(d.begin(), d.end());
    
    cout<<"Sorted Data:"<<endl;
    display();
}


int main(){

    while(1){
        int choice;
    
        cout<<endl;
        cout<<"\t ~~~ Vector Implimentaion ~~~"<<endl;
        cout<<"\t 1. Add Data to Last"<<endl;
        cout<<"\t 2. Add Data to Random Position"<<endl;
        cout<<"\t 3. Remove Last Data"<<endl;
        cout<<"\t 4. Remove Any Random Data"<<endl;
        cout<<"\t 5. Sort Data"<<endl;
        cout<<"\t 6. Display"<<endl;
        cout<<"\t 7. Exit"<<endl;
        cout<<"\t Enter Your Selection: \t";
        cin>>choice;

        switch (choice)
        {
        case 1:
            push(v1);
            break;

        case 2:
            push_random(v1);
            break;

        case 3:
            pop(v1);
            break;

        case 4:
            pop_random(v1);
            break;
        
        case 5:
            sorting(v1);
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);

        default:
            cout<<"\t Invalid Input. Try Again."<<endl;
            continue;
        }
    }

    return 0;
}