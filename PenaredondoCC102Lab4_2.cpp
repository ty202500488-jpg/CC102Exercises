#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        double sales[5][4] = {0};
        int salesperson, product;
        double amount;
        char more;

        // Input loop
        do {
            cout << "\nEnter Salesperson (1-4): ";
            cin >> salesperson;

            cout << "Enter Product (1-5): ";
            cin >> product;

            cout << "Enter Amount: ";
            cin >> amount;

            // Validate range
            if(salesperson >= 1 && salesperson <= 4 &&
               product >= 1 && product <= 5) {

                sales[product-1][salesperson-1] += amount;

            } else {
                cout << "Invalid input!\n";
            }

            cout << "Add another entry? (y/n): ";
            cin >> more;

        } while(more == 'y' || more == 'Y');

        // Display table
        cout << "\nProduct\t";

        for(int sp = 0; sp < 4; sp++)
            cout << "SP" << sp+1 << "\t";

        cout << "Total\n";

        double grandTotal = 0;

        for(int i = 0; i < 5; i++) {
            double rowTotal = 0;

            cout << i+1 << "\t";

            for(int j = 0; j < 4; j++) {
                cout << fixed << setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        // Column totals
        cout << "Total\t";
        for(int j = 0; j < 4; j++) {
            double columnTotal = 0;
            for(int i = 0; i < 5; i++) {
                columnTotal += sales[i][j];
            }
            cout << columnTotal << "\t";
        }

        cout << grandTotal << endl;

        cout << "\nRun program again? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
