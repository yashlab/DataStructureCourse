#include<iostream>
using namespace std;

void merge(int arr[],int l, int m, int r)
{
    int i,j,k;

    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1],R[n2];

    for(i=0;i<n1;i++)
        L[i]=arr[l+i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i=0;j=0;k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }

        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;

    }

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int ar[],int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;

        mergeSort(ar,l,m);
        mergeSort(ar,m+1,r);

        merge(ar,l,m,r);

    }
}

int main()
{
    int ar[]={15,18,203,22,40,29,45,865,421,11};
    mergeSort(ar,0,9);
    for(int i=0;i<10;i++)
        cout<<ar[i]<<endl;
    return 0;

}
