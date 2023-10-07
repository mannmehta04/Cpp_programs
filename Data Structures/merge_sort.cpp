#include<iostream>
#define MAX 6
using namespace std;

class mergeSort{

    // int data[MAX] = { 22, 24, 6, 8, 12, 14 };
    int data[MAX];

    public:

    mergeSort(){
        cout<<"Enter Data to be sorted:\n";
        for(int i=0;i<MAX;i++){
            cin>>data[i];
        }
    }

    void display();
    void mergesort(int a[], int beg, int end);
    void merge(int a[], int beg, int mid, int end);
};

void mergeSort::display(){
    cout<<"\nCurrent Data"<<endl;
    for(int i = 0; i < MAX; i++){
        cout<<data[i]<<endl;
    }
}

void mergeSort::mergesort(int data[], int beg, int end){
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergesort(data, beg, mid);
        mergesort(data, mid + 1, end);
        merge(data, beg, mid, end);
    }
}

void mergeSort::merge(int a[], int beg, int mid, int end){
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2];

    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];
    
    i = 0; /* initial index of ﬁrst sub-array */
    j = 0; /* initial index of second sub-array */
    k = beg; /* initial index of merged sub-array */
    while (i < n1 && j < n2){
        if(LeftArray[i] <= RightArray[j]){
            a[k] = LeftArray[i];
            i++;
        }

        else{
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    
    while (j<n2){
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

int main(){
    
    mergeSort m1;
    // m1.mergesort();
    // m1.merge();
    // m1.display();

    return 0;
}









/*    i = 0;  initial index of ﬁrst sub-array *
    j = 0; /* initial index of second sub-array /
    k = beg; /* initial index of merged sub-array *
    
    while (i < n1 && j < n2){
        if(LeftArray[i] <= RightArray[j]){
            data[k] = LeftArray[i];
            i++;
        }
        else{
            data[k] = RightArray[j];
            j++;
        }
        k++;
    }
    
    while (i<n1){
        data[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j<n2){
        data[k] = RightArray[j];
        j++;
        k++;
    }
    */