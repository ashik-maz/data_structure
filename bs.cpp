#include <iostream>
using namespace std;
int main()
{
    int n ; cin>> n;
    int arr[n];
    for(auto &i:arr) cin>>i;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (auto a : arr)
        cout << a << " ";
    return 0;
}