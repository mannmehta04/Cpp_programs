#include<iostream>
using namespace std;

class library{

    int bookid;
    char name[20];
    char author[20];
    int copies;

    public:

    void setdata(){
        cout<<"Enter Details of Book: \n";
        cout<<"Book ID: ";
        cin>>bookid;
        cout<<"Book Name: ";
        cin>>name;
        cout<<"Book Author: ";
        cin>>author;
        cout<<"Book Copies: ";
        cin>>copies;
    }

};





class issue_return : public library{
    int date_of_issue[3]={0, 0, 0};
    int date_of_return[3]={0, 0, 0};
    int fineperday=5;
    int maxdays=21;

    const int monthDays[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

    public:

    issue_return(){
        cout<<"Enter in this Order; Day, Month, Year: \n";
        cout<<"Date of Issue: \n";
        for(int i=0;i<3;i++){
            cin>>date_of_issue[i];
        }
        cout<<"Date of Return: \n";
        for(int i=0;i<3;i++){
            cin>>date_of_return[i];
        }
    }

    int countLeapYearDays(int d[]){
        int years = d[2];
        if (d[1] <= 2)
            years--;
        return ( (years / 4) - (years / 100) + (years / 400) );
    }

    int countNoOfDays(int date1[], int date2[]){

        long int dayCount1 = (date1[2] * 365);
        dayCount1 += monthDays[date1[1]];
        dayCount1 += date1[0];
        dayCount1 += countLeapYearDays(date1);

        long int dayCount2 = (date2[2] * 365);
        dayCount2 += monthDays[date2[1]];
        dayCount2 += date2[0];
        dayCount2 += countLeapYearDays(date2);

        return ( abs(dayCount1 - dayCount2) );
    }

    void totalfine();
    void checkavail();
};

void issue_return::totalfine(){

    int totaldays, totalfine=0;

    totaldays=countNoOfDays(date_of_issue, date_of_return);

    if(totaldays>maxdays){
        cout<<"This book is overdue by "<<totaldays-maxdays<<" days."<<endl;
        totalfine=(totaldays-maxdays)*fineperday;
    }

    cout<<"Fine to be Submitted: "<<totalfine<<endl;

    if(totalfine==0){
        for(int i=0;i<3;i++){
            date_of_issue[i]=0;
        }
    }
}

void issue_return::checkavail(){
    if(date_of_issue[0]==0){
        cout<<"The Book is Available! \n";
    }
    else{
        cout<<"Book Unavailable! \n";
    }
}

int main(){

    issue_return b1[2];
    for(int i=0;i<2;i++){
        b1[i].setdata();
        b1[i].totalfine();
        b1[i].checkavail();
    }
    return 0;

}