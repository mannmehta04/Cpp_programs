// All Required Functionalities are added.

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

    void traverse();
    void append_node(node *newNode);
    void append_after(int afterData, node *newNode);
    node* delete_node(int dataToBeDeleted);
    void delete_after(int afterData);
};

void node::traverse(){
    node *tp = this;

    while(tp!=NULL){
        cout<<"Node Data: "<<tp->data<<endl;
        prev=tp;
        tp=tp->next;
    }
}

void node::append_node(node *newNode){
    node *tp = this;

    while(tp->next!=NULL){
        prev = tp;
        tp = tp->next;
    }

    // first assign previous node
    newNode->prev=tp->next;

    // then assaign next node
    tp->next = newNode;
}

void node::append_after(int afterData, node *newNode){
    node *tp=this;

    while(tp->data!=afterData){
        prev=tp;
        tp=tp->next;
    }

    // Update next pointer for new node
    newNode->next=tp->next;

    // Update prev pointer for new node
    newNode->prev=tp;

    // Update next pointer for the node before new node
    tp->next=newNode;
}

node* node::delete_node(int dataToBeDeleted){
    node *tp=this;

    while(tp->data!=dataToBeDeleted){
        prev=tp;
        tp=tp->next;
    }

    if(tp==this){
        node *newFirst = tp->next;
        newFirst->prev=this;
        delete tp;
        return newFirst;
    }
    else{
        // Update previous node by storing address of prev pointer of next node
        prev->next=tp->next->prev;

        // Update next pointer for previous node
        prev->next=tp->next;

        // Free memory
        delete tp;

        // return current traverse pointer
        return this;
    }
}

// extra functionality (delete_after), in progress
// void node::delete_after(int afterData){
//     node *tp=this;

//     while(tp->data!=afterData){
//         prev=tp;
//         tp=tp->next;
//     }

//     // Updating before node
//     tp -> next = tp -> next -> next;

//     // Updating after node
//     tp -> next -> next -> prev = tp;

//     // delete tp;
// }

int main(){
    
    node *first = new node(10);
    node *newNode1 = new node(20);
    node *newNode2 = new node(30);
    node *newNode3 = new node(25);

    first-> append_node(newNode1);
    first-> append_node(newNode2);
    first-> append_after(20, newNode3);

    node *newFirst = first -> delete_node(10);
    if(first!=newFirst)
        first=newFirst;

    // first -> delete_after(25);

    first-> traverse();

    return 0;
}