#include<iostream>
using namespace std;

int main()
{

    int row,column,sum=0;
    cout<<"Enter row :";
    cin>>row;
    cout<<"Enter column : ";
    cin>>column;

    int arr[row][column];
    cout<<"Enter elements : ";
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            cin>>arr[i][j];
     cout<<"Array is : \n";
     for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
                cout<<arr[i][j]<<" ";
             cout<<endl;
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
                if(i==0||i==row-1||j==0||j==column-1)
                    sum+=arr[i][j];
        }

       cout<<"Summation of boundary elements is : "<<sum<<endl;

}
