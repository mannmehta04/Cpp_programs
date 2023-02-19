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

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return (fib(n-2)+fib(n-1));
    }
}

int main(){

    int fa, fi, n;
    cout<<endl;
    cout<<"Enter number: ";
    cin>>n;

    fa = fact(n);

    cout<<endl;
    cout<<"Factorial: "<<fa<<endl;
    cout<<"Fibonacci: "<<endl;

    for(int i=0;i<n;i++){
        cout<<fib(i)<<endl;
    }

    return 0;
}