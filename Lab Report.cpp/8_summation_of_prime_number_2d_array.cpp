#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;

    int arr[row][column];

    cout << "Enter elements into the array:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << "Array is:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int primeSum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (isPrime(arr[i][j])) {
                primeSum += arr[i][j];
            }
        }
    }

    cout << "Summation of all prime numbers in the array is: " << primeSum << endl;

    return 0;
}