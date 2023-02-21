#include<iostream>
using namespace std;

class node{
    int data;
    node *next;

    public:

    node(){
        data = 0;
        next = NULL;
    }

    node(int dummyData){
        data = dummyData;
        next = NULL;
    }

    void traverse();
    void append_node(node *newNode);
    void append_after(int data, node *newNode);
    node* delete_node(int val);
};

void node::traverse(){
    node *tp = this;
    while (tp != NULL){
        cout<<"Node Data: "<< tp-> data <<endl;
        tp=tp->next;
    }
}

void node::append_node(node *newNode){
    node *tp = this;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp -> next = newNode;
}

void node::append_after(int afterData, node *newNode){
    node *tp = this;
    
    while(tp -> data != afterData && tp -> next != NULL){
        tp = tp -> next;
    }
    //update behind ptr first then behind one
    newNode -> next = tp -> next;
    tp -> next = newNode;
}

node* node::delete_node(int dataToBeDeleted){
    node *tp = this;
    node *prev = this;
    
    while(tp -> data != dataToBeDeleted){
        prev = tp;
        tp = tp -> next;
    }

    if(tp==this){
        node *newFirst = tp -> next;
        delete tp;
        return newFirst;
    }
    else{
        prev -> next = tp -> next;
        delete tp;
        return this;
    }
}

int main(){
    
    node *first = new node(10);

    node *newnode = new node(20);
    first -> append_node(newnode);

    node *newnode2 = new node(40);
    first -> append_node(newnode2);

    node *newnode3 = new node(25);
    first -> append_after(20, newnode3);

    node *newFirst = first -> delete_node(10);
    if(newFirst != first)
        first = newFirst;

    first -> traverse();

    return 0;
}