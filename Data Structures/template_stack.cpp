#include<iostream>
#define high 3
using namespace std;

int top=-1, i;
template <class t>
class t_stack{

    t stk[5];

    public:

    void push(){
        t n;
        cout<<"Enter Number to be pushed \t";
        cin>>n;
        push(n);
    }

    void push(t n){
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
};

int main(){
    t_stack<int> s1;
    t_stack<char> s2;
    t_stack<float> s3;
    int input, n;

    while(1){
        cout<<"~~~ Template Stack Implementation ~~~ \n";
        cout<<"1. Display \n";
        cout<<"2. Push \n";
        cout<<"3. Pop \n";
        cout<<"4. Exit \n";
        cout<<"Enter User Input: \t";
        cin>>input;
        cout<<"\n";

        if(input==1){
            s1.display();
        }
        else if(input==2){
            if(top==high-1){
                cout<<"Stack Overflow";
                exit(0);
            }
            else{
                s1.push();

                cout<<"Element Successfully Pushed. \n";
            }
        }
        else if(input==3){
            if(top==-1){
                cout<<"Stack Underflow";
                exit(0);
            }
            else{
                s1.pop();

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