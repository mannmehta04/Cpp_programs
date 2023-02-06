
// This Program is not Completed. It might still have some additions.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

fstream f("text1.dat", ios::out | ios::binary);
fstream in("text1.dat", ios::in | ios::binary);


class Employee{
    int emp_id;
    string emp_name;
    string emp_dept;
    
    public:

    //default constructor
    Employee(){

    }

    // Employee(int emp_id, const char emp_name, const char emp_dept){
    //     this -> emp_id = emp_id;
    //     this -> emp_name = emp_name;
    //     this -> emp_dept = emp_dept;
    // }

    // void addData(int e, string n, string d){
    //     f<<endl;
    //     f<<"New Employee Data:"<<endl;
    //     f<<"Employee Id:\t"<<e<<endl;
    //     f<<"Employee Name:\t"<<n<<endl;
    //     f<<"Employee Department:\t"<<d<<endl;
    // }

    void addData(Employee obj){

        f<<endl;
        f.write((char*)&obj, sizeof(obj));

    }
    

    void updateData(int e){
        int id;
        string name, dept;

        // deleteData(e);

        //user input
        cout<<"Enter Updated Data:";
        cout<<"Enter Id: ";
        cin>>id;
        cout<<endl;

        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Department: ";
        cin>>dept;
        
        //writing in file
        f<<endl;
        f<<"New Employee Data:"<<endl;
        f<<"Employee Id:\t"<<id<<endl;
        f<<"Employee Name:\t"<<name<<endl;
        f<<"Employee Department:\t"<<dept<<endl;
    }

    void searchData(int e){
        char array[250];

        //read till end of file
        while(!in.eof()){
            int i;
            in>>array[i];

            i++;
        }

        //divide number in parts
        int p1, p2, p3;
        p3=e%10;
        // cout<<"p3: "<<p3<<" ";
        p2=(e/10)%10;
        // cout<<"p2: "<<p2<<" ";
        p1=((e/10)/10)%10;
        // cout<<"p1: "<<p1<<" "<<endl;

        // //just display captured data
        // for(int i=0; i<250;i++){
        //     cout<<"Data["<<i<<"]: "<<array[i]<<endl;
        // }

        for (int i=0; i<250; i++){
            if(array[i]==p1 && array[i+1]==p2 && array[i+2]==p3){
                cout<<"Data Found: "<<array[i];
                cout<<array[i+1];
                cout<<array[i+2];
                break;
            }
        }

    }

    void deleteData(int e){

    }

    void display(){

        // char ch;
        // while (!in.eof()){
        //     cout<<"\t~~~ Employee Data: ~~~"<<endl;
        //     cout<<"Employee Id: ";
        //     cout<<"Employee Name: ";
        //     cout<<"Employee Department: ";
        // }

    }
};

int main(){

    Employee e1;

    //store something in e1!!!
    e1.addData(e1);
    // e1.addData(401, "user", "cp");
    e1.searchData(401);

    return 0;
}