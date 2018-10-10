// Program for a Doubly Linked List
#include<iostream>
using namespace std;

struct node{
int data;
node* next;
node* prev;
}*p=NULL;

void ins_beg()
{
    node *temp = new(node);
    cout<<"Enter data to be inserted"<<endl;
    cin>> temp->data;

    if(p==NULL)
    {
        temp->prev=NULL;
        temp->next=NULL;
        p=temp;
    }

    else
    {
        temp->prev = NULL;
        temp->next = p;
        p->prev = temp;
        p=temp;
    }

    cout<<"Element added at the beginning\n";

}

void ins_end()
{
    node *temp = new node;
    cout<<"Enter element to be inserted\n";
    cin>> temp->data;

    node* q =p;

    while(q->next!=NULL)
        q=q->next;

    q -> next= temp;
    temp -> prev =q;
    temp->next=NULL;

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
    temp->prev=q;
    temp->next=r;

    cout<<"Inserted Successfully";

}

void del_beg()
{
    if(p==NULL)
    {
        cout<<"Nothing to delete";
        return;
    }

    if(p->next==NULL)
    {
        node *temp =p;
        p=NULL;
        delete(temp);
    }

    else
    {
        node*temp =p;
        p=p->next;
        p->prev=NULL;
        delete(temp);
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

void del_pos()
{
    if(p==NULL)
    {
        cout<<"Nothing to delete\n";
        return;
    }

    node* q=p;

    int pos,cnt=1;
    while(q->next!=NULL)
    {
        q=q->next;
        cnt++;
    }

    cout<<"Enter the position of object to be deleted";
    cin>>pos;

    if(pos>cnt)
    {
        cout<< "Enter a valid position";
        return;
    }

    if(pos==cnt)
    {
        ins_end();
        return;
    }

    q=p;
    for(int i=1; i<pos-1;i++)
        q=q->next;

    node *temp=q->next;
    temp->next->prev=q;
    q->next=temp->next;
    delete(temp);

}

void trav()
{
    node *q = p;
    if(q==NULL)
    {
        cout<<"Nothing to display";
        return;
    }
    while(q->next!=NULL)
    {
        cout<<q->data<<"\t";
        q=q->next;
    }
    cout<<q->data<<"\n";
}

void rev_print()
{
    node *q=p;
    while(q->next!=NULL)
    {
        q=q->next;
    }

    while(q->prev!=NULL)
    {
        cout<<q->data<<"\t";
        q=q->prev;
    }
    cout<<q->prev<<endl;


}

int main()
{
    cout<<"\t\t *********Welcome to the World of Doubly Linked List*********\n";
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
