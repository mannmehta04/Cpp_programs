#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;

class bank{

    public:

    int acc_no;
    float bal;
    char *name;
    int date_of_creation[3]={1,1,2000};
    int todays_date[3]={10,11,2022};

    bank(){
        cout<<"Enter Account Number: \n";
        cin>>acc_no;
        cout<<"Enter Balance: \n";
        cin>>bal;
        cout<<"Enter Name: \n";
        name=new char(15);
        cin>>name;

        cout<<"Enter in this Order; Day, Month, Year: \n";
        cout<<"Date of Creating Account: \n";
        for(int i=0;i<3;i++){
            cin>>date_of_creation[i];
        }
    }

    void display();
    void deposit();
};

void bank::display(){
    cout<<"Customer Detail: \n";
    cout<<"Account Number: "<<acc_no<<"\n";
    cout<<"Account Balance: "<<bal<<"\n";
    cout<<"Account Name: "<<name<<"\n";
    cout<<"Account Creation Date: "<<"\n";
    for(int i=0;i<3;i++){
        cout<<date_of_creation[i]<<"\t";
    }
    cout<<"\n";
}

void bank::deposit(){
    int a;
    cout<<"Enter Amount to be Depositted \n";
    cin>>a;
    bal+=a;
    cout<<"\nUpdated Balance \n";
    cout<<"Balance: "<<bal<<"\n";
}

class saving: public bank{
    float compound_intrest;

    public:

    void withdraw();
    void calcintrest();
};

void saving::withdraw(){
    int a;
    cout<<"Enter Amount to be Withdrawn \n";
    cin>>a;
    bal-=a;
    cout<<"\nUpdated Balance \n";
    cout<<"Balance: "<<bal<<"\n";
}

void saving::calcintrest(){
    double rate = 7.5, years = todays_date[2]-date_of_creation[2];

    double A = bal * (pow((1 + rate / 100), years));
    double CI = A - bal;

    cout << "Total Compound interest is " << CI << "\n\n";

    bal+=CI;
    cout<<"Updated Balance \n";
    cout<<"Balance: "<<bal<<"\n";
}

class current: public bank{
    int checkbook_number;
    int minimum_bal=1500;
    int service_charge=500;

    public:

    void checkbal(){
        cout<<"Enter Latest Checkbook Number: \n";
        cin>>checkbook_number;

        if(bal<minimum_bal){
            cout<<"Your Balance is "<< bal <<" and below Minimum Amount. \n Please Submit "<< service_charge <<" as Service Charge. \n";
        }
        else{
            cout<<"Your Balance is: "<<bal<<"\n";
        }
        cout<<"CheckBook Number is: "<<checkbook_number<<"\n";
    }
};

int main(){
    saving s1;
    current c1;
    s1.display();
    s1.deposit();
    s1.withdraw();
    s1.calcintrest();
    c1.checkbal();
    return 0;
}