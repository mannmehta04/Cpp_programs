#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    string inFile = "";
    string outFile = "";

    if( argc == 3 ) {
      inFile = argv[1];
      outFile = argv[2];
    }

    char buffer[20];
    cout<<"Enter Data for First File: \n";
    cin.getline(buffer, 20);
    
    ofstream binaryWrite("text1.bin", ios::out | ios::binary);
    binaryWrite.write((char *) &buffer, sizeof(buffer));
    binaryWrite.close();

    //Write Data into File 2

    ifstream in(inFile, ios::in | ios::binary);
    ofstream f(outFile, ios::out | ios::binary);

    in.open(inFile);
    f.open(outFile);

    char ch;
    while (in.read((char*)&ch, sizeof(ch))){
      f.write((char*)&ch, sizeof(ch));
    }

    in.close();
    f.close();
}