#include<iostream>
#define high 3
using namespace std;

int stk[high];
int top=-1, i;

void push(int n){
    if(top==high-1){
        cout<<"Stack Overflow";
        exit(0);
    }
    else{
        top++;
        stk[top]=n;
    }
}

void pop(){
    if(top==-1){
        cout<<"Stack Underflow";
        exit(0);
    }
    else{
        stk[top]=0;
        top--;
    }
}

void display(){
    for(int i=high-1;i>=0;i--){
        cout<<stk[i]<<"\n";
    }
    cout<<endl;
}

int main(){
    int input, n;

    while(1){
        cout<<"~~~ Basic Stack Implementation ~~~ \n";
        cout<<"1. Display \n";
        cout<<"2. Push \n";
        cout<<"3. Pop \n";
        cout<<"4. Exit \n";
        cout<<"\nEnter User Input: \t";
        cin>>input;
        cout<<"\n";

        if(input==1){
            display();
        }
        else if(input==2){
            if(top==high-1){
                cout<<"Stack Overflow";
                exit(0);
            }
            else{
                cout<<"Enter Number to be pushed \t";
                cin>>n;

                push(n);

                cout<<"Element Successfully Pushed. \n";
            }
        }
        else if(input==3){
            if(top==-1){
                cout<<"Stack Underflow";
                exit(0);
            }
            else{
                pop();

                cout<<"Element Successfully Popped. \n";
            }
        }
        else if(input==4){
            break;
        }
        else{
            cout<<"Invalid Input \n";
            continue;
        }
    }

    // push(10);
    // display();
    // pop();
    // display();
}