//3_Print lowest and highest element of a user input array
#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

void displayArray(int arr[], int size) {
    cout << "Array elements:";
    for (int i = 0; i < size; ++i) {
        cout << " " << arr[i];
    }
    cout<<endl;
    if(size>0){
        cout << endl;
        int max=arr[0];
        int min=arr[0];
        for(int i=0;i<size;i++){
            if(arr[i]>max){
                max=arr[i];
            }
            if(arr[i]<min){
                min=arr[i];
            }
        }
        cout<<"Maximum Element= "<<max<<endl;
        cout<<"Minimum Elemnt= "<<min<<endl<<endl;
    }
    

}

void insert(int arr[], int& size, int element) {
    if (size < MAX_SIZE) {
        arr[size++] = element;
    } else {
        cout << "Array is full. Cannot insert more elements." << endl;
    }
}
void deleteData(int arr[], int& size, int element) {
    int index=-1;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            index=i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    } else {
        cout << "Element not found in the array. Cannot delete." << endl;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element;

    while (true) {
        displayArray(arr,size);
        cout << "Menu:\n1. Insert\n2. Delete specific data\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                insert(arr, size, element);
                system("CLS");
                break;
            case 2:
                cout << "Enter element to delete: ";
                cin >> element;
                deleteData(arr, size, element);
                system("CLS");
                break;
            case 3:  
                displayArray(arr,size);
                cout << "Exiting program." << endl;
                system("CLS");
                return 0;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
        
    }

    return 0;
}
