#include<iostream>
#include<string.h>
#define high 10
using namespace std;

char stk[high];
char array[20];
int top=-1, actual, current;

class postfix{

    public:

    postfix(){

        string str;

        cout<<"Enter String: ";
        cin>>str;

        //conversion into char
        int i=0;
        do{
            array[i]=str[i];
            i++;
        }while(str[i]!='\0');

    }

    int check_operand(char exp[]){
        int n;
        for(int i=0; i<sizeof(array); i++){
            if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z'){
                n=1;
                current=i;
            }
            else if(exp[i]=='*' || exp[i]=='\\' ){
                n=2;
                current=i;
            }
            else if(exp[i]=='+' || exp[i]=='-' ){
                n=3;
                current=i;
            }
        }

        return n;
    }

    void convert(char exp[]){
        char temp_ch;

        if (check_operand(exp)==1){
            cout<<array[current];
        }
        else if (check_operand(exp)==2){
            if(stk[top]=='+' && stk[top]=='-')
                push(array[current]);
            else if(stk[top]=='*' && stk[top]=='\\'){
                temp_ch=pop(); //retrive higher precedence operator
                push(array[current]);
                cout<<temp_ch;
            }
        }
        else if (check_operand(exp)==3){
            if(stk[top]=='+' && stk[top]=='-')
                push(array[current]);
            else if(stk[top]=='*' && stk[top]=='\\'){
                temp_ch=pop(); //retrive higher precedence operator
                push(array[current]);
                cout<<temp_ch;
            }
        }
    }

    // void retrive_copy(char exp[]){
    //     char ch = stk[top];
    // }

    void push(char n){
        if(top==high-1){
            cout<<"Stack Overflow";
            exit(0);
        }
        else{
            top++;
            stk[top]=n;
        }
    }

    char pop(){
        char temp;

        if(top==-1){
            cout<<"Stack Underflow";
            exit(0);
        }
        else{
            temp=stk[top];
            stk[top]=0;
            top--;
        }
        
        return temp;
    }

    void display_stack(){
        for(int i=high-1;i>=0;i--){
            cout<<stk[i]<<"\n";
        }
        cout<<endl;
    }

    void display_expression(){
        cout<<"Your Expression is: ";
        for (int i = 0; i < sizeof(array); i++){
            cout<<array[i];
        }
    }
};

int main(){
    
    postfix p1;
    p1.display_expression();
    
    return 0;
}