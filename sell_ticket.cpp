#include <iostream>
#include "main.h"

using namespace std;

static bool isValidSeat(int row, int col) {
    return row >= 1 && row <= ROWS && col >= 1 && col <= COLS;
}

bool sellTicket(char seats[ROWS][COLS],double price_arr[ROWS], int row, int col, double &totalSales, double &totalTicketPrices) {
    if (!isValidSeat(row, col)) {
        cout << "The position is invalid!\n";
        return false;
    }

    if (seats[row][col] == '*') {
        cout << "This seat has already been sold.\n";
        return false;
    }
    seats[row][col] = '*';
    totalSales += price_arr[row];
    totalTicketPrices += price_arr[row];
    cout << "Sold (Row " << row << ", Seat " << col << ") - Price: $" << price_arr[row] << "\n";
    return true;
}
