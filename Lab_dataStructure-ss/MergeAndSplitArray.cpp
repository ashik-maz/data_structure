#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int arr1Size, int arr2[], int arr2Size, int mergedArray[])
{
    for(int i = 0; i < arr1Size; i++)
    {
        mergedArray[i] = arr1[i];
    }
    for(int i = 0; i < arr2Size; i++)
    {
        mergedArray[i + arr1Size] = arr2[i];
    }
}

void splitArray(int arr[], int arrSize, int firstArray[], int secondArray[], int splitIndex)
{
    for(int i = 0; i < splitIndex; i++)
    {
        firstArray[i] = arr[i];
    }
    for(int i = 0; i < arrSize - splitIndex; i++)
    {
        secondArray[i] = arr[splitIndex + i];
    }
}

void printArray(int arr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int choice;
    cout << "What do you want to do? \n1. Merge two arrays\n2. Split an array" << endl;
    cin >> choice;

    if(choice == 1)
    {
        int arr1Size, arr2Size;
        cout << "Enter size of the first array: ";
        cin >> arr1Size;
        int arr1[arr1Size];

        cout << "Enter size of the second array: ";
        cin >> arr2Size;
        int arr2[arr2Size];

        cout << "Enter elements of the first array: ";
        for(int i = 0; i < arr1Size; i++)
        {
            cin >> arr1[i];
        }

        cout << "Enter elements of the second array: ";
        for(int i = 0; i < arr2Size; i++)
        {
            cin >> arr2[i];
        }

        int mergedArray[arr1Size + arr2Size];
        mergeArrays(arr1, arr1Size, arr2, arr2Size, mergedArray);

        cout << "First Array: ";
        printArray(arr1, arr1Size);

        cout << "Second Array: ";
        printArray(arr2, arr2Size);

        cout << "Merged Array: ";
        printArray(mergedArray, arr1Size + arr2Size);
    }
    else if(choice == 2)
    {
        int arrSize, splitIndex;
        cout << "Enter size of the array: ";
        cin >> arrSize;
        int arr[arrSize];

        cout << "Enter elements of the array: ";
        for(int i = 0; i < arrSize; i++)
        {
            cin >> arr[i];
        }

        cout << "Array: ";
        printArray(arr, arrSize);

        cout << "Enter split index: ";
        cin >> splitIndex;

        int firstArray[splitIndex];
        int secondArray[arrSize - splitIndex];
        splitArray(arr, arrSize, firstArray, secondArray, splitIndex);

        cout << "First Array: ";
        printArray(firstArray, splitIndex);

        cout << "Second Array: ";
        printArray(secondArray, arrSize - splitIndex);
    }
}
