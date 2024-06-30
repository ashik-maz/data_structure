//array merging and spliting

#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=100;

void displayArray(int arr[],int size)
{
    cout<<"Array elements:";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insert(int arr[],int &size,int element)
{
    if(size>MAX_SIZE)
    {
        cout<<"Array is full.Can nat insert."<<endl;
    }
    else{
        arr[size++]=element;
    }
}

void mergeArrays(int arr1[],int &size1,int arr2[],int size2)
{
    cout<<"First:";
    displayArray(arr1,size1);
    cout<<"Second:";
    displayArray(arr2,size2);
    for(int i=0;i<size2;i++)
    {
        insert(arr1,size1,arr2[i]);
    }
    cout<<"Merge:";
    displayArray(arr1,size1);
}

void splitArray(int arr1[],int size1,int index)
{
    cout<<"Main:";
    displayArray(arr1,size1);
    if(index<0 && index>MAX_SIZE)
    {
        cout<<"Invalid index."<<endl;
        return ;
    }
    cout<<"First part:";
    displayArray(arr1,index);

    int arr2[MAX_SIZE],size2=0;
    for(int i=index;i<size1;i++)
    {
        insert(arr2,size2,arr1[i]);
    }

    cout<<"Second part:";
    displayArray(arr2,size2);

}


int main()
{
   int arr1[MAX_SIZE] ,arr2[MAX_SIZE];
   int size1=0,size2=0;
   int choice,element,index;
   while(true)
   {
       cout<<"Menu: \n 1.Merge \n 2.split \n 3.exit \n enter choice: \n";
       cin>>choice;
       switch(choice)
       {
       case 1:
           cout<<"Enter elements for first array(enter -1 to stop):";
           while(true)
           {
               cin>>element;
               if(element==-1)
               {
                break;
               }
               insert(arr1,size1,element);
           }
          cout<<"Enter elements for second  array(enter -1 to stop):";
           while(true)
           {
               cin>>element;
               if(element==-1)
               {
                break;
               }
               insert(arr2,size2,element);
           }
           mergeArrays(arr1,size1,arr2,size2);
           break;
       case 2:
           cout<<"Enter the index to split the array:";
           cin>>index;
           splitArray(arr1,size1,index);
           break;
       case 3:
          return 0;
       default:
           cout<<"Invalid choice.Please enter again."<<endl;
       }
   }


    return 0;
}