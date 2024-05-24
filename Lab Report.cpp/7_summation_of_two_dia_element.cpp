#include <iostream>
using namespace std;

int main() {
    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;

    // Create a 2D array
    int arr[row][column];

    // Read elements into the array
    cout << "Enter elements into the array:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cin >> arr[i][j];
        }
    }

    // Display the array
    cout << "Array is:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Initialize variables for diagonal summation
    int diagSum1 = 0, diagSum2 = 0;

    // Calculate the summation of the main diagonal and anti-diagonal elements
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (i == j) {
                diagSum1 += arr[i][j]; // Main diagonal element
            }
            if (i + j == column - 1) {
                diagSum2 += arr[i][j]; // Anti-diagonal element
            }
        }
    }

    // Display the summation of diagonal elements
    cout << "Summation of the main diagonal elements is: " << diagSum1 << endl;
    cout << "Summation of the anti-diagonal elements is: " << diagSum2 << endl;

    return 0;
}
