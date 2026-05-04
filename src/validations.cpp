#include "globals.h"

int getValidInt(){
    int value;
    while (!(cin >> value) || value < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid non-negative number: ";
    }
    return value;
}

float getValidFloat(){
    float value;
    while (!(cin >> value) || value < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a non-negative number: ";
    }
    return value;
}