
#include<iostream>
using namespace std;

int SumDiagonals(int*sq_mat,int len)
{
    int sum=0;
    for(int i=0;i<len;i++)
    {
        sum+=*((sq_mat+i*len)+i)+*((sq_mat+len*i)+(len-1-i));
    }
    if(len%2==1)
        sum-=*((sq_mat+len*(len/2))+len/2);
    return sum;
}

int main()
{

    int size;
    cout<<"Enter order of square matrix :";
    cin>>size;

    int Sq_mat[size][size];
    cout<<"Enter elements : ";
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            cin>>Sq_mat[i][j];
     cout<<"Square matrix is : \n";
     for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
                cout<<Sq_mat[i][j]<<" ";
             cout<<endl;
        }

    cout<<"Summation of diagonals elements is : "<<SumDiagonals((int*)Sq_mat,size)<<endl;

}
