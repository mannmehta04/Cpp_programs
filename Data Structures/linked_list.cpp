
// not fully completed yet.

#include<iostream>
using namespace std;

class l_list{
    int data;
    l_list *next;

    public:

    l_list(){
        data = 0;
        next = NULL;
    }

    l_list(int dummyData){
        data = dummyData;
        next = NULL;
    }

    void traverse();
    void append_node(l_list *node);
    void append_between(int data, l_list *node);
};

void l_list::traverse(){
    l_list *tp = this;
    while (tp != NULL){
        cout<<"Node Data: "<<tp->data<<endl;
        tp=tp->next;
    }
}

void l_list::append_node(l_list *node){
    l_list *tp = this;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=node;
}

void l_list::append_between(int data, l_list *node){
    l_list *tp = this;
    
    while(tp->data!=data){
        tp=tp->next;
    }
    //update behind ptr first then behind one

}

int main(){
    
    l_list *first = new l_list(10);

    l_list *newnode = new l_list(20);
    first -> append_node(newnode);

    newnode = new l_list(30);
    first -> append_node(newnode);

    newnode = new l_list(40);
    first -> append_node(newnode);

    first -> traverse();

    return 0;
}