#include<iostream>
#define MAX 3
using namespace std;

class sort{

    int a[MAX],i;

    public:

    sort(){
        cout<<"Enter upto "<<MAX<<" Elements: \n";
	    for(i=0;i<MAX;i++)
		    cin>>a[i];
    }

    void bubble_sort();
    void insertion_sort();
    void display();
};

void sort::bubble_sort(){
	int i,j,temp;
    bool flag;

	for(i=0;i<MAX-1;i++)				//First loop for passes
	{
        flag = 0;
		for(j=0;j<MAX-i-1;j++)			//Second loop for comparision
		{
			if(a[j]>a[j+1])				//test need to compare
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
                flag=1;
			}
		}

        if(flag == 0){
            break;
        }
	}
}

void sort::insertion_sort(){
    int i, j, temp;

    for(i=1;i<MAX;i++)				//First loop for passes
	{
		temp =a[i];

		for(j=i-1;j>=0 && a[j]>temp;j--)			//Second loop for comparision
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}

void sort::display(){
    printf("\n Array Data: \n");
	for(i=0;i<MAX;i++)
        cout<<"Array ["<<i+1<<"] = "<<a[i]<<endl;
}

int main(){

    sort set1;

	set1.bubble_sort();
    // set1.insertion_sort();
    set1.display();

    return 0;
}