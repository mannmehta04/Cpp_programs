#include<iostream>
#include<string.h>
using namespace std;

class student{

    protected:
    int rollno;
    char *name;

    public:
    student(int r,const char *n){
        name=new char[strlen(n)+1];
        strcpy(name, n);

        rollno=r;
    }
};

class test:protected student{
    
    protected:
    int test_marks[2];
    int credit[2]={10,10};
    char grade[2];

    public:
    test(int r,const char *n):student(r, n){
        for(int i=0;i<2;i++){
            cout<<"Enter Subject "<<i+1<<" marks: ";
            cin>>test_marks[i];
        }
        // for(int i=0;i<2;i++){
        //     cout<<"Enter Subject "<<i+1<<" grade: ";
        //     cin>>grade[i];

        //     cout<<"Your grade: "<<grade[i];
        // }
    }
};

class sports{
    
    protected:
    int sport_points[2];

    public:
    sports(){
        for(int i=0;i<2;i++){
            cout<<"Enter Sport "<<i+1<<" points: ";
            cin>>sport_points[i];
        }
    }
};

class result:protected test, protected sports{

    char grade;
    float total_marks;
    int total_credit;

    public:

    result(int r,const char *n):test(r, n){

    }

    void calc_grade(){
        for(int i=0;i<2;i++){
            cout<<"Enter Grade for Subject "<<i+1<<": ";
            cin>>grade;
            // total_marks=+test_marks[i];
            total_marks=total_marks+(10-2*(grade-'A'))*credit[i];
            total_credit=total_credit+credit[i];
            // cout<<"Total Marks: "<<total_marks<<"\n";
        }
        cout<<"Your SPI is: "<<(total_marks/total_credit);
    }

    void display(){
        cout<<"\n";
        cout<<"Roll No: "<<rollno<<"\n";
        cout<<"Name: "<<name<<"\n\n";
        for(int i=0;i<2;i++){
            cout<<"Test "<<i+1<<" marks: "<<test_marks[i]<<"\n";
            cout<<"Sport "<<i+1<<" points: "<<sport_points[i]<<"\n\n";
        }
        calc_grade();
        // cout<<"Total Marks: "<<total_marks<<"\n";
    }
};

int main(){
    result r1(312,"Mann");
    r1.display();

    return 0;
}