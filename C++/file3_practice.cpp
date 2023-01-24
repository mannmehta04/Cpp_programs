#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream f;
    char name[30];
    int roll;
    
    char r_name[30];
    int r_roll;

    char w_name[30];
    int w_name;

    f.open("read_file", ios::out);
    cout<<"Enter Data: \n";
    cin>>name;
    cin>>roll;

    f<<name<<roll;
    f.close();

    f.open("read_file",ios::in);
    while(!f.eof()){
        f.getline(r_name,15);
        f>>r_roll;
    }
    f.close();

    f.open("write_file",ios::out);
    while(!f.eof()){
        f<<r_name
        f<<r_roll;
    }
    f.close();
    return 0;
}