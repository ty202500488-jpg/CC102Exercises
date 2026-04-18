#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    // WRITE
    fstream Colors;

    Colors.open("colors.txt", ios::out);

    if(Colors.is_open()){
        Colors << "Red\n";
        Colors << "Orange\n";
        Colors << "Yellow\n";
        Colors << "Green\n";
        Colors << "Blue\n";
        Colors.close();
        cout << "Write Successfully!\n";
    }
    else {
        cout << "Failed to Open File.\n";
    }
    // READ + COPY

    fstream Copy;

    Colors.open("colors.txt", ios::in);
    Copy.open("color_copy.txt", ios::out);

    if(Colors.is_open() && Copy.is_open()){
        string line;

        while(getline(Colors, line)){
            cout << line << endl;
            Copy << line << endl;
        }
        Colors.close();
        Copy.close();
        cout << "File Copied Successfully!\n";
    }

    else{
        cout << "Failed to Copy.\n";
    }


    return 0;
}
