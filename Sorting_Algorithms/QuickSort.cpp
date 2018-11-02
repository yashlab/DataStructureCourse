#include<iostream>
using namespace std;

void swaap(int* x, int* y) // function for swapping two numbers
{
    int temp = *x;
    *x=*y;
    *y=temp;

}
int part(int ar[], int low, int high)
{
    // Function to implement the partition algorithm
    int pivot = ar[high];
    int i=low-1;

    for (int j=low;j<=high-1;j++)
    {
        if(ar[j]<pivot)
        {
            i++;
            swaap(&ar[i],&ar[j]);

        }
    }
    swaap(&ar[i+1],&ar[high]);
    return (i+1); // return the point of pivot
}

void Quick(int ar[],int low, int high)
{
    if(low<high)
    {
        int pi = part(ar,low,high);

        Quick(ar,low,pi-1);
        Quick(ar,pi+1,high);
    }
}


int main()
{
    int ar[]={15,18,203,22,40,29,45,865,421,11};
    Quick(ar,0,9);
    for(int i=0;i<10;i++)
        cout<<ar[i]<<endl;
    return 0;

}
