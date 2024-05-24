//5. Array merging and splitting
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

void displayArray(int arr[], int size) {
    cout << "Array elements:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void insert(int arr[], int &size, int element) {
    if (size < MAX_SIZE) {
        arr[size++] = element;
    } else {
        cout << "Array is full. Cannot insert more elements." << endl;
    }
}

void mergeArrays(int arr1[], int arr2[], int &size1, int size2) {
    system("cls");
    cout<<"First ";
    displayArray(arr1, size1);
    cout<<"Second ";
    displayArray(arr2, size2);
    for (int i = 0; i < size2; ++i) {
        insert(arr1, size1, arr2[i]);
    }
    cout<<"Merge ";
    displayArray(arr1, size1);
}

void splitArray(int arr1[], int size1, int index) {
    system("cls");
    cout<<"Main ";
    displayArray(arr1, size1);

    if (index < 0 || index >= size1) {
        cout << "Invalid index." << endl;
        return;
    }
    cout << "First part ";
    displayArray(arr1, index);
    
    int arr2[MAX_SIZE];
    int size2 = 0;
    for (int i = index; i < size1; ++i) {
        insert(arr2, size2, arr1[i]);
    }
    cout << "Second part ";
    displayArray(arr2, size2);
}

int main() {
    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];
    int size1 = 0;
    int size2 = 0;
    int choice, element, index;

    while (true) {
        cout << "Menu:\n1. Merge Array\n2. Split Array\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter elements for the first array (enter -1 to stop):" << endl;
                while (true) {
                    cin >> element;
                    if (element == -1) break;
                    insert(arr1, size1, element);
                }
                cout << "Enter elements for the second array (enter -1 to stop):" << endl;
                while (true) {
                    cin >> element;
                    if (element == -1) break;
                    insert(arr2, size2, element);
                }
                mergeArrays(arr1, arr2, size1, size2);
                break;
            case 2:
                cout << "Enter the index to split the array: ";
                cin >> index;
                splitArray(arr1, size1, index);
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    }

    return 0;
}
