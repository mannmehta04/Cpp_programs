#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream f;
    char c[15];

    f.open("test",ios::out);
    f<<"hello there!";
    f.close();

    f.open("test",ios::in);
    
    // while(!f.eof()){
    //     //read till space and store
    //     f>>c;
    //     cout<<c;
    // }

    while(!f.eof()){
        // read with spaces
        f.getline(c,15);
    }
    cout<<c;
    f.close();

    return 0;
}