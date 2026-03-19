#include <iostream>
using namespace std;

void input(void* ptr, int n);
void display(void* ptr, int n);

void input(void* ptr, int n) {

    struct student {
        int studentID;
        string name;
        string course;
        float gpa;
    };

    student* s = (student*)ptr;

    for(int i = 0; i < n; i++) {

        cout << "\nStudent " << i + 1 << endl;

        bool unique;
        do {
            unique = true;
            cout << "Enter Student ID: ";
            cin >> s[i].studentID;

            for(int j = 0; j < i; j++) {
                if(s[i].studentID == s[j].studentID) {
                    cout << "ID already exists! Enter a different ID.\n";
                    unique = false;
                    break;
                }
            }
        } while(!unique);

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, s[i].name);

        cout << "Enter Course: ";
        getline(cin, s[i].course);

        do {
            cout << "Enter GPA (0-100): ";
            cin >> s[i].gpa;

            if(s[i].gpa < 0 || s[i].gpa > 100) {
                cout << "Invalid GPA. Try again.\n";
            }

        } while(s[i].gpa < 0 || s[i].gpa > 100);
    }
}

string getStanding(float gpa) {
    if(gpa >= 90) return "Excellent";
    else if(gpa >= 80) return "Very Good";
    else if(gpa >= 70) return "Good";
    else if(gpa >= 60) return "Passing";
    else return "Failed";
}

void display(void* ptr, int n) {

    struct student {
        int studentID;
        string name;
        string course;
        float gpa;
    };

    student* s = (student*)ptr;

    cout << "\n\n===== STUDENT RECORDS =====\n";
    cout << "ID\tName\t\tCourse\t\tGPA\tStanding\n";

    for(int i = 0; i < n; i++) {
        cout << s[i].studentID << "\t"
             << s[i].name << "\t\t"
             << s[i].course << "\t\t"
             << s[i].gpa << "\t"
             << getStanding(s[i].gpa) << endl;
    }
}

int main() {

    char choice;

    do {
        int n;

        cout << "Enter number of students: ";
        cin >> n;

        struct student {
            int studentID;
            string name;
            string course;
            float gpa;
        };

        student obj[n];

        input(obj, n);
        display(obj, n);

        cout << "\nDo you want to run again? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
