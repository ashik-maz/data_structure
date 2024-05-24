#include<iostream>
using namespace std;

class DynamicArray
{

private:
    int *arr;
    int capacity;
    int size;

public:
    DynamicArray(int initialCapacity=1)
    {
        capacity=initialCapacity;
        arr=new int[initialCapacity];
        size=0;
    }
    ~DynamicArray()
    {
        delete [] arr;
    }

    void append(int value)
    {
        if(size==capacity)
        {
            reSize(capacity+1);
        }
        arr[size++]=value;
    }

    void dataInsert(int index,int value)
    {
        if(index<0||index>size)
        {
            throw out_of_range("Index out of  range");
        }
        for(int i=size;i>index;i--)
            arr[i]=arr[i-1];
        arr[index]=value;
        size++;
    }

    void dataRemove(int index)
    {
        for(int i=index;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
    }

    void printArray()
{
    cout<<"Array :";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

   /* int &operator[](int index)
    {
        if(index<0||index>=size)
        {
            throw out_of_range("Index out of  range");
        }
        return arr[index];
    }
    int getSize()
    {
        return size;
    }*/

private:
    void reSize(int newCapacity)
    {
        int *newArr=new int [newCapacity];
        for(int i=0;i<size;i++)
        {
            newArr[i]=arr[i];
        }
        delete []arr;
        arr=newArr;
        capacity=newCapacity;
    }

};

int main()
{
    DynamicArray darray;
    bool loop=true;
    int choice,data,index;
    do
    {
        cout<<"\nWhat do you want : \n1.Add element\n2.Add element at specific index\n3.Delete element at specific index\n4.Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter data :";
            cin>>data;
            darray.append(data);
            system("CLS");
            darray.printArray();
            break;
         case 2:
            cout<<"Enter data :";
            cin>>data;
            cout<<"Enter index :";
            cin>>index;
            darray.dataInsert(index,data);
            system("CLS");
            darray.printArray();
            break;

          case 3:
            cout<<"Enter index :";
            cin>>index;
            darray.dataRemove(index);
            system("CLS");
            darray.printArray();
            break;
          case 4:
            loop=false;
            system("CLS");
            darray.printArray();
            break;
          default:
            cout<<"Invalid";
        }


    }while(loop);

   //darray.printArray();
}
