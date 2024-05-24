#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;  
struct Student {
    int roll;
    string name;
    int marks;
};

void inputData(Student students[], int& size) {
    if (size >= MAX_STUDENTS) {
        cout << "Maximum student limit reached." << endl;
        return;
    }

    cout << "Enter Roll: "; cin >> students[size].roll;
    cout << "Enter Name: "; cin >> students[size].name;
    cout << "Enter Marks: "; cin >> students[size].marks;

    size++;
}

void sortResult(Student students[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (students[j].marks > students[i].marks) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printResult(const Student students[], int size) {
    cout << "Roll\tName\t\tMarks\n";
    for (int i = 0; i < size; ++i) {
        cout << students[i].roll << "\t" << students[i].name << "\t\t" << students[i].marks << endl;
    }
}

int main() {
    int size = 0;
    Student students[MAX_STUDENTS];
    int choice;

    while (true) {
        printResult(students, size);
        cout << "1. Insert\n2. Print Result\n3. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                inputData(students, size);
                break;
            case 2:
                sortResult(students, size);
                printResult(students, size);
                break;
            case 3:
                system("CLS");
                printResult(students, size);
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
        system("CLS");
    }
}
