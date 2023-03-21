#include<iostream>
#include<set>
#define queries 3
using namespace std;

class querySearch{
    set <string> set1;
    string dummyQ;

    public:

    querySearch(){
        for (int i = 0; i < queries; i++){
            cout<<"Enter Query "<<i+1<<" : ";
            cin>>dummyQ;
            set1.insert(dummyQ);
        }
    }

    void display();
    void search();
};

void querySearch::display(){
    set<string>::iterator it = set1.begin();

    cout<<"Existing Queries: "<<endl;
    while(it!=set1.end()){
        cout<<"Query String: "<<*it<<endl;
        it++;
    }
    cout<<endl;
}

void querySearch::search(){
    set<string>::iterator it = set1.begin();
    string searchQ;
    int counter=0;

    cout<<"Enter Query to be Searched: ";
    cin>>searchQ;

    auto position = set1.find(searchQ);
    
    for(auto it = position ; it!=set1.end() ; it++){
        // cout<<"String Found: "<<*it<<endl;
        counter++;
    }
    cout<<"String Found: "<<searchQ<<", "<<counter<<" times."<<endl;
}

int main(){

    querySearch q1;
    q1.display();
    q1.search();

    return 0;
}