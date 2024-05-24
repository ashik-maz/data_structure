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


    void printArray()
{
    cout<<"Array :";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void selectionSort()
{
    for(int i=0;i<size-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[minIndex]>arr[j])
            {
                minIndex=j;
            }
        }
        if(minIndex!=i)
        {
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }

    }

}

void Min_Max()
{
    cout<<"\nMinimum element is : "<<arr[0]<<endl;
    cout<<"Maximum element is : "<<arr[size-1]<<endl;
}

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

    int data;

      cout<<"Enter data :";
        do
        {
            cin>>data;
            if(data!=-1)
            darray.append(data);

        }while(data!=-1);

      system("CLS");
      darray.printArray();
      darray.selectionSort();
      darray.Min_Max();
}
