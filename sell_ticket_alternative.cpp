#include <iostream>
#include <iomanip>
using namespace std;
const int ROWS = 15;
const int COLS = 30;

void sellTicket(char seats[ROWS][COLS], double price_arr[ROWS], double &totalSales) {
    int tickets; // số lượng vé muốn mua

    // Ask user to buy tickets
    do {
        cout << "\nHow many tickets do you want to buy? ";
        cin >> tickets;

        if (tickets < 1 || tickets > ROWS * COLS) {
            cout << "Invalid number of tickets. Total seats in the theater is "
                 << ROWS * COLS << endl;
        }
    } while (tickets < 1 || tickets > ROWS * COLS);


    // vòng lặp cho từng vé
    for (int i = 1; i <= tickets; i++) {
        int row, col;
        cout << "\nTicket #" << i << endl;
        cout << "Enter row number (1-15): ";
        cin >> row;
        cout << "Enter seat number (1-30): ";
        cin >> col;

        // check valid
        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            cout << "Invalid row or seat number. Try again.\n";
            i--; // cho nhập lại vé này
            continue;
        }

        // check seat has already been sold
        if (seats[row - 1][col - 1] == '#') {
            cout << "That seat has already been sold. Choose another.\n";
            i--; // cho nhập lại vé này
            continue;
        }

        // note sell seat and sum money
        seats[row - 1][col - 1] = '#';
        
        totalSales += price_arr[row - 1];

        cout << "Seat Row " << row << ", Seat " << col
             << " sold for $" << fixed << setprecision(2)
             << price_arr[row - 1] << endl;
    }

    // sum prices for this sales
    cout << "\nTotal sales: $" << fixed << setprecision(2)
         << totalSales << endl;
}
// Hàm main

  