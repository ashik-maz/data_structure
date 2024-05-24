#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

 node *head,*newnode,*temp;

 int main()
 {

     int choice;

    do{
            newnode=new(node);
             cout<<"Enter value of node  : ";
             cin>>newnode->data;

            if(head==NULL)
            {
                head=temp=newnode;
               newnode->next=NULL;
            }
            else
            {
                temp->next=newnode;
                newnode->next=NULL;
                temp=newnode;
            }
            cout<<"Do you want to add more node : ";
            cin>>choice;

        }while(choice==1);

     node *trv=head;

     cout<<"\nLinked list data are : ";
     while(trv!=NULL)
     {
         cout<<trv->data<<"  ";
         trv=trv->next;
     }

 }

