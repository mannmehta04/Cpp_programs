#include<iostream>
#include<string.h>
using namespace std;

class String1{
    char *sptr;
    int len;

    public:

    //Display Function
    void display(){
        cout<<sptr<<"\n";
    }

    //String Pointer
    String1(char *sptr) {
        len = strlen(sptr); //Calculate Length for Allocation
        this->sptr = new char[len + 1]; //Dynamic Memory Allocation
        strcpy(this->sptr, sptr); //Copy String to Private Variable
    }

    //Copy Constructor
    String1(const String1 &s) {
        len = s.len; //Copying Length in Private Variable
        sptr = new char[len + 1]; //Allocate Memory accordingly
        strcpy(sptr, s.sptr); //Copy String to Private Variable
    }

    //Concate String
    String1 operator+(String1 s) {
        
        //Allocate total memory & length/size for 2 Strings
        char *concate = new char[len + s.len];

        //Store 1st String in Concate Variable(Allocated before)
        int counter = 0;
        for(int i = 0; i < len; i++, counter++){
            concate[i] = sptr[i];
        }

        //Store 2nd String in Concate Variable(passed as argument)
        for(int i = 0; i < s.len; i++, counter++){
            concate[counter] = s.sptr[i];
        }

        //Final Memory Allocation of Concated String in Object, to return as Object
        String1 a(concate);
        return a; //Returned as Object
    }

    String1 operator+(int delchar){
        //Allocate Memory less than the char to be deleted
        char *final=new char[len-delchar];

        //Copy char after the chars to be deleted
        for(int i=0;i<len-delchar;i++){
            final[i] = sptr[i + delchar];
        }

        //Final Memory Allocation of Concated String in Object, to return as Object
        String1 a(final);
        return a; //Returned as Object
    }

    String1 operator=(String1 copy){
        delete[] sptr;

        sptr= new char[copy.len+1];
        strcpy(sptr,copy.sptr);

        String1 a(copy);
        return a;
    }

    ~String1(){
        delete[] sptr;
    }
};

int main(){

    String1 s1("Mann");
    // String1 s2("Mehta");
    // String1 s3=s1+s2;
    // String1 s4=s2+2;
    String1 s5=s1;

    cout<<"Use of Overloading + with 2 Class Objects: \n";
    s3.display();
    // s4.display();
    s5.display();

    return 0;
}