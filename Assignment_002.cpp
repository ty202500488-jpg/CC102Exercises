#include <iostream>
using namespace std;

void analyzeMatrix(int *ptr, int students, int subjects) {

    cout << "\nGrade Matrix:\n";

    // Display the matrix
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << *(ptr + i * subjects + j) << "\t";
        }
        cout << endl;
    }

    cout << "\nAverage grade of each student:\n";

    // Compute average per student
    for (int i = 0; i < students; i++) {
        int sum = 0;

        for (int j = 0; j < subjects; j++) {
            sum += *(ptr + i * subjects + j);
        }

        double average = (double)sum / subjects;
        cout << "Student " << i + 1 << ": " << average << endl;
    }

    // Find highest grade
    int highest = *ptr;

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {

            int current = *(ptr + i * subjects + j);

            if (current > highest) {
                highest = current;
            }
        }
    }

    cout << "\nHighest grade in the matrix: " << highest << endl;
}

int main() {

    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[students][subjects];

    cout << "\nEnter the grades:\n";

    // Input grades
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }

    // Pass the 2D array as a pointer
    analyzeMatrix(&grades[0][0], students, subjects);

    return 0;
}
