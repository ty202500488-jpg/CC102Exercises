#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimesInFile() {
    ifstream file("NUMS.TXT");
    int num, count = 0;

    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return -1;
    }

    while (file >> num) {
        if (isPrime(num)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    int result = countPrimesInFile();

    if (result != -1)
        cout << "Number of prime numbers: " << result << endl;

    return 0;
}
