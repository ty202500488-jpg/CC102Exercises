#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
    // STEP 1: Write to original.txt
    fstream file;
    file.open("original.txt", ios::out);

    if(file.is_open()){
        file << "One\n";
        file << "Two\n";
        file << "Three\n";
        file << "Four\n";
        file << "Five\n";
        file << "Six\n";
        file.close();
    }
    else{
        cout << "Failed to create original.txt\n";
        return 1;
    }

    // STEP 2: Read from original.txt
    file.open("original.txt", ios::in);

    if(!file.is_open()){
        cout << "Failed to open original.txt\n";
        return 1;
    }

    string arr[6];
    int i = 0;

    while(getline(file, arr[i])){
        i++;
    }

    file.close();

    // STEP 3: Sort using algorithm
    sort(arr, arr + i);

    // STEP 4: Write to sorted.txt
    fstream sortedFile;
    sortedFile.open("sorted.txt", ios::out);

    if(sortedFile.is_open()){
        for(int j = 0; j < i; j++){
            sortedFile << arr[j] << endl;
        }
        sortedFile.close();
        cout << "Sorted successfully!\n";
    }
    else{
        cout << "Failed to create sorted.txt\n";
    }

    return 0;
}
