#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
using namespace std;


int readFileToArray(const string &filename, double price_arr[ROWS], int maxSize) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file!\n";
        return 0;
    }

    int count = 0;

    for (int i = 1; i <= 15; ++i) {
        if (file >> price_arr[i]) {
            // Successfully read a number
            count++;
        }
    }
    file.close();
    return count;
}

