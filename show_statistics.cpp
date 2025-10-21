#include <iostream>
#include <iomanip>
#include "main.h"

using namespace std;

void showStatistics(char seats[ROWS][COLS], double price_arr[ROWS], double totalSales) {
    int totalSold = 0;
    int totalAvailable = 0;

    cout << "\n=== Summary ===\n";
    for (int r = 1; r <= ROWS; ++r) {
        int sold = 0;
        for (int c = 1; c <= COLS; ++c) {
            if (seats[r][c] == '*') ++sold;
        }
        int avail = COLS - sold;
        totalSold += sold;
        totalAvailable += avail;
        cout << "Row " << r << ": available " << avail << "/" << COLS << " (Sold " << sold << ")\n";
    }

    cout <<fixed<<setprecision(2)<<endl;
    cout << "Total seats: " << (ROWS * COLS) << "\n";
    cout << "Total seat sold: " << totalSold << "\n";
    cout << "Total seat available: " << totalAvailable << "\n";
    cout << "Total sales: $" << totalSales << "\n";
}
