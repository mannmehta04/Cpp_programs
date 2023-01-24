// Write a program to find roots of quadratic equation ax2 + bx + c. Raise exception and handle if roots are Complex.
// If less than 0, complex
// d = b2 - 4ac

#include<iostream>
using namespace std;

class roots{
    int a, b, c, d;

    public:
    roots(){
        cout<<"\nEnter Values for a: ";
        cin>>a;
        cout<<"\nEnter Values for b: ";
        cin>>b;
        cout<<"\nEnter Values for c:";
        cin>>c;
    }

    void findroot(){
        cout<<"\tThe Equation is as Follows: \n";
        cout<<" \t \t ax^2 + bx + c\n";

        d = (b*b) - (4 * a * c);
        try{
            if (d<0){
                throw d;
            }
            cout<<"Roots are not Complex.";
        }
        catch (int d){
            cout<<"Exception Caught...";
        }
    }
      
};

int main(){
    roots r1;
    r1.findroot();
}