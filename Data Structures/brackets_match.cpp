#include<iostream>
#define high 10
using namespace std;

class bracket_checker{
    char stk[high];
    int top=-1;
    string str;

    public:

    bracket_checker(){
        cout<<"\n\t Parentheses / Bracket Order Checker.\nEnter set of Brackets:\t";
        cin>>str;
    }

    void check_string();
    void push(char str);
    void pop();
    char peep();

};

void bracket_checker::check_string(){
    int flag=0;
    for(int i=0;i<sizeof(str);i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            push(str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(peep()=='(' || peep()=='{' || peep()=='['){
                pop();
                if(top==-1){
                    cout<<"Bracket Paring Successfully Completed. No Errors found. ";
                }
            }
            else{
                char temp;
                temp=peep();
                cout<<"Invalid Extra Character found: "<<temp;
                exit(0);
            }
        }
    }
}

void bracket_checker::push(char s){
    if(top==high-1){
        cout<<"Stack Overflow";
        exit(0);
    }
    else{
        top++;
        stk[top]=s;
    }
}

void bracket_checker::pop(){
    if(top==-1){
        cout<<"Stack Underflow";
        exit(0);
    }
    else{
        stk[top]=0;
        top--;
    }
}

char bracket_checker::peep(){
    char temp;
    if(top==-1){
        cout<<"Stack Underflow";
        exit(0);
    }
    temp=stk[top];
    // cout<<(stk[top]);
    return temp;
}

int main(){

    bracket_checker b1;

    b1.check_string();
    // b1.push('(');
    // b1.peep();

    return 0;
}