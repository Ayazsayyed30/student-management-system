#include <iostream>
using namespace std;

struct Student {
    int id;
    char name[50];
    float marks;
};

Student s[100];
int countStudent = 0;

void addStudent() {
    cout << "\nEnter Student ID: ";
    cin >> s[countStudent].id;

    cout << "Enter Student Name: ";
    cin >> s[countStudent].name;

    cout << "Enter Marks: ";
    cin >> s[countStudent].marks;

    countStudent++;

    cout << "Student Added Successfully!\n";
}

void displayStudents() {
    if(countStudent == 0) {
        cout << "\nNo Students Found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";

    for(int i = 0; i < countStudent; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << s[i].id << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Marks: " << s[i].marks << endl;
    }
}

void searchStudent() {
    int id;
    int found = 0;

    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    for(int i = 0; i < countStudent; i++) {
        if(s[i].id == id) {
            cout << "\nStudent Found!\n";
            cout << "ID: " << s[i].id << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Marks: " << s[i].marks << endl;

            found = 1;
        }
    }

    if(found == 0) {
        cout << "Student Not Found.\n";
    }
}

void deleteStudent() {
    int id;
    int found = 0;

    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for(int i = 0; i < countStudent; i++) {
        if(s[i].id == id) {

            for(int j = i; j < countStudent - 1; j++) {
                s[j] = s[j + 1];
            }

            countStudent--;

            found = 1;

            cout << "Student Deleted Successfully!\n";
            break;
        }
    }

    if(found == 0) {
        cout << "Student Not Found.\n";
    }
}

int main() {

    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 0:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    } while(choice != 0);

    return 0;
}
