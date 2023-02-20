// Credits: 22CP318
// This program is performed by 22CP318.

#include<bits/stdc++.h>
#include<vector>
using namespace std;

class vector1{
        vector<int> v;
public:
    void input(int n){
    int ele;
        for(int i=0;i<n;i++){
            cout<<"Enter Element "<<i+1<<" = ";
            cin>>ele;
            v.push_back(ele);
        }
    }
    void display(){
          int i = 0;
     for(const int &p : v){
           cout<<"vector["<<i<<"] = "<<p<<endl;
           i++;
        }
   //     for(int i = 0;i<v.size();i++){
     //       cout<<"Element "<<i+1<<" = "<<v[i]<<endl;
       // }
    }

    void sort_vector(){
        sort(v.begin(),v.end());
        int i = 0;
           for(const int &p : v){
                i++;
           cout<<"vector["<<i<<"] = "<<p<<endl;
        }
    //    int temp;
    //    int sizev = v.size();
    //    for(int i = 0;i<sizev;i++){
      //      for(int j = i+1;j<sizev;j++){
        //        if(v[i]>v[j]){
          //              temp = v[i];
            //            v[i] = v[j];
              //          v[j] = temp;
               // }
           // }
       // }
       // v.push_back(90);
        //cout<<"\nSorted Vector : \n\n";
         //for(int i = 0;i<v.size();i++){
          //  cout<<"Element "<<i+1<<" = "<<v[i]<<endl;
        //}

    }

    void delete_pos(int pos){
        vector<int>::iterator c;

    c = v.begin();
    c = c + (pos-1);
        v.erase(c);
        for(int i = 0;i<v.size();i++){
            cout<<"Element "<<i+1<<" = "<<v[i]<<endl;
        }
    }
     void insert_Pos(int pos,int ele){
        v.insert(v.begin()+(pos-1) , ele);
    }

};

int main(){
    int ch,n,pos;
    vector1 v;

do{
    cout<<"\n1 =} Press 1 for input \n2 =} Press 2 for Sort \n3 =} Press 3 for Print \n4 =} Press 4 for Delete \n5 =} Press 5 for Insert ele at any Position \n6 =} Press 6 for Exit \n\nEnter Choice : ";
     cin>>ch;
    cout<<endl;
     switch(ch){
    case 1:
        cout<<"How many Element You Want to append : ";
        cin>>n;
        v.input(n);
        break;
    case 2:
         v.sort_vector();
         break;
    case 3:
          v.display();
          break;
    case 4:
        cout<<"Enter Position You Want to delete : ";
        cin>>pos;
        v.delete_pos(pos);
        break;
    case 5:
        cout<<"Enter Position Where You want insert Element : ";
        cin>>pos;
        cout<<"Enter Element You Want to insert : ";
        cin>>n;
        v.insert_Pos(pos,n);
        break;
    case 6:
        exit(0);
        break;
    default:
        cout<<"\nInvalid Choice \n\n";
     }
     }while(1);
    return 0;
}