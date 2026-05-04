#include "globals.h"

int getValidInt(){
    int value;
    while (!(cin >> value) || value <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number: ";
    }
    return value;
}