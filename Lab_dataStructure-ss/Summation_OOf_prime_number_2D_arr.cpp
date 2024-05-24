#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n==0 || n==1)
        return false;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

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
                if(isPrime(arr[i][j]))
                    sum+=arr[i][j];
        }

       cout<<"Summation of prime elements is : "<<sum<<endl;

}

