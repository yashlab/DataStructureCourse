#include<iostream>
using namespace std;

#define MAX 10
int a[MAX];
int f=-1,r=-1;

void enqueue()
{
    if(r==MAX-1)
    {
        cout<<"Overflow";
        return;
    }

    cout<<"enter element";
    int data;
    cin>>data;

    if(f==-1)
    {
        f++;r++;
        a[r]=data;
    }
    else
    {
        a[++r]=data;
    }
}

void dequeue()
{
    if(f==-1 || f>r)
    {
        cout<<"Nothing to delete\n";
        return;
    }
    f++;
    if(f>r)
    {
        f=-1;
        r=-1;
    }
}
