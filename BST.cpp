// Binary Search Tree

#include<iostream>
using namespace std;

struct node{
int data;
node *lchild,*rchild;
}*root=NULL;


void ins()
{
    cout<<"Enter the element";
    node *temp = new(node);
    cin>>temp->data;
    temp->lchild=NULL;
    temp->rchild=NULL;

    if(root==NULL)
    {
        root=temp;
        return;
    }

    node *parent,*current;
    current=root;
    parent=NULL;


    while(1){
        parent=current;
        if(temp->data <= current->data)
        {
            current=current->lchild;
            if(current==NULL)
            {
                parent->lchild =temp;
                break;
            }
        }

        else
        {
            current=current->rchild;
            if(current==NULL)
            {
                parent->rchild=temp;
                break;
            }
        }

    }
}

void preorder(node *temp)
{
    if(temp==NULL)
        return;
    preorder(temp->lchild);
    cout<<temp->data<<"  ";
    preorder(temp->rchild);
}
int main()
{
    for(int i=0;i<11;i++)
        ins();
    preorder(root);
    return 0;


}
