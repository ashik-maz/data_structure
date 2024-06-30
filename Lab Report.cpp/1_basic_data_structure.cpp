#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void displayArray(int arr[], int size) {
    cout << "Array elements:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void insertTail(int arr[], int& size, int element) {
    if (size < MAX_SIZE) {
        arr[size++] = element;
        cout << "Element inserted at the tail successfully." << endl;
    } else {
        cout << "Array is full. Cannot insert more elements." << endl;
    }
}

void insertPosition(int arr[], int& size, int element, int position) {
    if (size < MAX_SIZE && position >= 0 && position <= size) {
        for (int i = size; i > position; --i) {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        size++;
        cout << "Element inserted at position " << position << " successfully." << endl;
    } else {
        cout << "Invalid position or array is full. Cannot insert element." << endl;
    }
}

void deleteData(int arr[], int& size, int element) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element " << element << " deleted successfully." << endl;
    } else {
        cout << "Element not found in the array. Cannot delete." << endl;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    while (true) {
        displayArray(arr,size);
        cout << "Menu:\n1. Insert at tail\n2. Insert at specific position\n3. Delete specific data\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert at tail: ";
                cin >> element;
                insertTail(arr, size, element);
                displayArray(arr, size);
                break;
            case 2:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert: ";
                cin >> position;
                insertPosition(arr, size, element, position);
                displayArray(arr, size);
                break;
            case 3:
                cout << "Enter element to delete: ";
                cin >> element;
                deleteData(arr, size, element);
                displayArray(arr, size);
                break;
            case 4:
                system("CLS");
                displayArray(arr,size);
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
        system("CLS");
    }

    return 0;
}
