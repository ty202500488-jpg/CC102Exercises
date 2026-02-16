#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[100][100];   // safe max size
        double average[100];

        // Input scores
        for(int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " scores:\n";

            double sum = 0;

            for(int j = 0; j < quizzes; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / quizzes;
        }

        // Display table
        cout << "\nStudent\t";

        for(int j = 0; j < quizzes; j++) {
            cout << "Q" << j + 1 << "\t";
        }
        cout << "Average\n";

        for(int i = 0; i < students; i++) {
            cout << i + 1 << "\t";

            for(int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "\t";
            }

            cout << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "\nRun program again? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
