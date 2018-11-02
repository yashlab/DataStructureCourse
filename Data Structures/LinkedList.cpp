//Linked List

#include<iostream>
#include<conio.h>
using namespace std;
int count =0;
struct node{
int data;
node* next;
}*p=NULL;

void insbeg()
{
    node* temp= new node;
    cout<<"Enter data to be inserted\n";
    cin>> temp->data;

    if(p==NULL)
    {
        p=temp;
        temp->next= NULL;

    }
    else
    {
        temp->next=p;
        p=temp;
    }
    cout<<"Inserted at beginning\n";
    count++;
}

void ins_pos()
{
    int cnt;
    int i,pos;
    cout<<"Enter the position on which the data is to be the inserted\n";
    cin>>pos;

    if(p==NULL)
        cnt=0;
    else
        cnt=1;


    node *q=p;
    while(q->next!=NULL)
    {
        q=q->next;
        cnt++;
    }

    if(cnt<pos)
    {
        cout<<"The position doesn't exist.\n";
        return;
    }

    q=p;

    for(i=1;i<pos-1;i++)
        q=q->next;

    node*r;
    r=q->next;

    node *temp = new node;
    cout<<"Enter element to be inserted\n";
    cin>> temp->data;

    q->next=temp;
    temp->next=r;

    cout<<"Inserted Successfully";


}
void ins_end()
{
    node* temp= new node;
    cout<<"Enter data to be inserted\n";
    cin>> temp->data;

    if(p==NULL)
    {
        p=temp;
        temp->next=NULL;
        return;
    }
    node* q = p;

    while(q->next!=NULL)
        q=q->next;

    q->next =temp;
    temp->next=NULL;
    count++;
}

void del_beg()
{
    if(p==NULL)
        cout<<"Nothing to delete";

    node *temp=p;
    if(temp->next==NULL)
    {
        p=NULL;
        delete(temp);
    }

    else
    {
        p=p->next;
        delete temp;
    }

}
void del_pos(int pos)
{

    if(pos>count)
    {
        cout<<" Invalid position";
        return;
    }

    if(p==NULL)
    {
        cout<<"Nothing to Delete";
        return;
    }

    else if(pos==1)
    {
        node *temp = p;
        p=p->next;
        delete temp;
    }

    else if (pos==count)
    {
        node* q=p;
        while(q->next->next!=NULL)
        {
            q=q->next;
        }
        node *temp =q->next;
        q->next=NULL;
        delete temp;

    }
}


void del_end()
{
    if(p==NULL)
    {
        cout<<"Nothing to delete\n";
        return;
    }

    node* q=p;

    if(q->next==NULL)
    {
        q=p;
        p=NULL;
        delete(q);
        return;
    }
    while(q->next->next!=NULL)
    {
        q=q->next;
    }

    node* temp=q->next;
    q->next=NULL;
    delete(temp);

}

void trav()
{
    node *q= p;
    while(q->next!=NULL)
    {
        cout<<q->data<<"\t";
        q=q->next;
    }
    cout<<q->data;
}

void rev()
{
    node *pr, *next, *curr;
    pr=NULL;
    curr=p;

    while(next!=NULL)
    {
        next=p->next;
        curr->next=prev;
        prev=curr;

    }


}
int main()
{
    cout<<"\t\t *********Welcome to the World of Linked Lists*********\n";
    cout<<"We have the following options:\n";
    cout<<"1: Insert at Beginning \t2: Insert at a position \t3: Insert at end\n";
    cout<<"4: Delete at Beginning \t5: Delete at a position \t6: Delete at end\n";
    cout<<"7: Display the linked list\t8: Reverse print the linked list\n";
    cout<<"Press 0 to exit\n";
    int num=1;

    cout<<"Enter the number corresponding to the operation of choice\n";
    do
    {
        cin>>num;
        switch(num)
        {
            case 1:
                ins_beg();
                break;
            case 2:
                ins_pos();
                break;
            case 3:
                ins_end();
                break;
            case 4:
                del_beg();
                break;
            case 5:
                del_pos();
                break;
            case 6:
                del_end();
                break;
            case 7:
                trav();
                break;
            case 8:
                rev_print();
                break;
        }
        cout<<"Please enter your next operation";

    }while(num!=0);

    return 0;

}
