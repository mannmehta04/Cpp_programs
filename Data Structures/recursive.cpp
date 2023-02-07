#include<iostream>
using namespace std;

int fact(int n){
    int ans;
    if(n>1)
        return (n*fact(n-1));
    if(n==1)
        return 1;
    else
        return 0;
}

int main(){

    int ans, n;
    cout<<endl;
    cout<<"Enter number: ";
    cin>>n;

    ans=fact(n);

    cout<<endl;
    cout<<"Answer: "<<ans;

    return 0;
}