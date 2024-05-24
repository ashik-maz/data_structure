#include<iostream>
using namespace std;

struct node
{
    int data;
    node *add;
};

 node *p,*q,*r,*trv;

 int main()
 {

     p=new(node);
     q=new (node);
     r=new(node);

     cout<<"Enter value of node 1  : ";
     cin>>p->data;
     p->add=q;
     cout<<"Enter value of node 2  : ";
     cin>>q->data;
     q->add=r;
     cout<<"Enter value of node 3  : ";
     cin>>r->data;
     r->add=NULL;

     trv=p;

     cout<<"\nLinked list data are : ";
     while(trv!=NULL)
     {
         cout<<trv->data<<"  ";
         trv=trv->add;
     }

 }
