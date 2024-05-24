#include <iostream>
using namespace std;

// Define a structure to represent a student
struct Student {
    string name;
    int rollNumber;
    int mathMarks;
    int physicsMarks;
    int chemistryMarks;
    int totalMarks;
};

// Function to compare two students based on total marks


// Function to perform selection sort on array of students based on total marks
void selectionSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].totalMarks > arr[maxIndex].totalMarks) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

int main() {
    // Create an array of 5 students
    Student students[5];

    // Input data for each student
    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for student " << i+1 << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Mathematics Marks: ";
        cin >> students[i].mathMarks;
        cout << "Physics Marks: ";
        cin >> students[i].physicsMarks;
        cout << "Chemistry Marks: ";
        cin >> students[i].chemistryMarks;

        // Calculate total marks for each student
        students[i].totalMarks = students[i].mathMarks + students[i].physicsMarks + students[i].chemistryMarks;

        cout << endl;
    }

    // Sort the students based on total marks using selection sort
    selectionSort(students, 5);

    // Output the sorted result sheet
    cout << "Result Sheet (Sorted by Total Marks):\n";
   // cout << "------------------------------------\n";
    cout << "Name\tRoll Number\tMathematics\tPhysics\tChemistry\tTotal Marks\n";
   // cout << "------------------------------------\n";
    for (int i = 0; i < 5; ++i) {
        cout << students[i].name << "\t" << students[i].rollNumber << "\t\t"
                  << students[i].mathMarks << "\t\t" << students[i].physicsMarks << "\t\t"
                  << students[i].chemistryMarks << "\t\t" << students[i].totalMarks << "\n";
    }
   // cout << "------------------------------------\n";

    return 0;
}
