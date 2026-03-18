#include <iostream>
#include <iomanip>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    float gpa;
};

// Function to determine academic standing
string getStanding(float gpa) {
    if (gpa >= 90) return "Excellent";
    else if (gpa >= 80) return "Very Good";
    else if (gpa >= 70) return "Good";
    else if (gpa >= 60) return "Passing";
    else return "Failed";
}

// Function to check if ID already exists
bool isDuplicate(student s[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (s[i].studentID == id) {
            return true;
        }
    }
    return false;
}

int main() {
    char choice;

    do {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        student s[n];

        for (int i = 0; i < n; i++) {
            cout << "\nStudent " << i + 1 << endl;

            // Validate unique ID
            int id;
            do {
                cout << "Enter Student ID: ";
                cin >> id;

                if (isDuplicate(s, i, id)) {
                    cout << "ID already exists! Enter a different ID.\n";
                } else {
                    break;
                }
            } while (true);

            s[i].studentID = id;

            cin.ignore(); // clear buffer

            cout << "Enter Name: ";
            getline(cin, s[i].name);

            cout << "Enter Course: ";
            getline(cin, s[i].course);

            cout << "Enter GPA (0-100): ";
            cin >> s[i].gpa;
        }

        // Display table
        cout << "\n\n===== STUDENT RECORDS =====\n";
        cout << left << setw(12) << "ID"
             << setw(20) << "Name"
             << setw(15) << "Course"
             << setw(10) << "GPA"
             << setw(15) << "Standing" << endl;

        for (int i = 0; i < n; i++) {
            cout << left << setw(12) << s[i].studentID
                 << setw(20) << s[i].name
                 << setw(15) << s[i].course
                 << setw(10) << s[i].gpa
                 << setw(15) << getStanding(s[i].gpa) << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
