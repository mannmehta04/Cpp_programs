#include<iostream>
using namespace std;

class node{
    int data;
    node *next;
    node *prev;

    public:

    node(){
        data=0;
        next=NULL;
        prev=NULL;
    }

    node(int dummyData){
        data=dummyData;
        next=NULL;
        prev=NULL;
    }

    void push(node *newNode);
    void pop();
    void display();
};

void node::display(){
    node *tp = this;
    node *prev = this;
    node *first = this;

    // This commented part below is not complete and optional.
    // It is used to display data in Stack format.

        // while(tp != NULL){
        //     cout<<"Node Data: "<< tp-> data <<endl;
        //     prev = tp;
        //     tp=tp->next;
        // }
        // while(tp != first){
        //     tp=tp->prev;
        //     cout<<"Node Data: "<< tp-> data <<endl;
        //     // reverse=reverse->next;
        // }

    while (tp != NULL){
        cout<<"Node Data: "<< tp-> data <<endl;
        tp=tp->next;
    }
}

void node::push(node *newNode){
    node *tp = this;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp -> next = newNode;
}

void node::pop(){
    node *tp = this;

    while(tp->next != NULL){
        prev = tp;
        tp = tp -> next;
    }

    if(tp==this){
        cout<<"Stack Empty.";
        delete tp;
        exit(0);
    }
    else{
        delete tp;
        prev -> next = NULL;
    }
}

int main(){

    node *first = new node(10);
    int input, n;

    while(1){
        cout<<"\n~~~ Linked List Stack Implementation ~~~ \n";
        cout<<"1. Display \n";
        cout<<"2. Push \n";
        cout<<"3. Pop \n";
        cout<<"4. Exit \n";
        cout<<"Enter User Input: \t";
        cin>>input;
        cout<<"\n";

        if(input==1){
            first->display();
        }
        else if(input==2){
            int data;
            cout<<"Enter Element to be Added: ";
            cin>>data;
            node *newNode1 = new node(data);
            first->push(newNode1);
        }
        else if(input==3){
            first->pop();
        }
        else if(input==4){
            break;
        }
        else{
            cout<<"Invalid Input \n";
            continue;
        }
    }

    // node *first = new node(10);
    // node *newNode1 = new node(20);
    // node *newNode2 = new node(30);

    // first->push(newNode1);
    // first->push(newNode2);
    // first->pop();
    // first->pop();
    // first->pop();
    // first->display();
    
    return 0;
}
