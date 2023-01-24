#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream fout;
    char string[30];

    fout.open("file1");
    fout<<"India";
    fout<<"USA";
    cout<<"Data Write Complete \n\n";

    fout.close();

    ifstream fin;
    fin.open("file1");
    while(!fin.eof()){
        fin.getline(string,15);
    }
    cout<<string;
    fin.close();
}