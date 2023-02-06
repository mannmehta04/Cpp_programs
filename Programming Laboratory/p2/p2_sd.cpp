#include<iostream>
#include<math.h>
#define TOTAL 6
using namespace std;

int main(){

    float xi[TOTAL], fi[TOTAL], std_dev, mean, varience, sum_xi, sum_fx , sum_fi, sum_var;

    //get xi
    for(int i=0; i<TOTAL;i++){
        cin>>xi[i];
    }

    //get fi
    for(int i=0; i<TOTAL;i++){
        cin>>fi[i];
    }

    //find n (sum_fi)
    for(int i=0; i<TOTAL;i++){
        sum_fi=sum_fi+fi[i];
    }

    //fin sum_fx
    for(int i=0; i<TOTAL;i++){
        sum_fx = sum_fx + (fi[i]*xi[i]);
    }

    //calc mean
    mean= sum_fx / sum_fi;

    //find varience
    for(int i=0; i<TOTAL;i++){
        sum_var = sum_var + (fi[i] * ((xi[i] - mean)*(xi[i] - mean)));
    }

    varience = sum_var / sum_fi;

    std_dev = sqrt(varience);

    cout<<endl<<mean<<endl;
    cout<<varience<<endl;
    cout<<std_dev<<endl;

    return 0;
}