// Selection sort
#include<iostream>
using namespace std;
void swapping(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void selectionSort(int *array, int size){
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
      swap(array[i], array[imin]);
   }
}
int main(){
   int n;
   int arr[n];
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   cout << "Array before Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
   selectionSort(arr, n);
   cout << "Array after Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
}
