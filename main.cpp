#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include "main.h"
using namespace std;

int main() {
    double price_arr[ROWS] = {0.0};
    double totalSales = 0.0;
    double totalTicketPrices = 0.0;
    char seats[ROWS][COLS];
    for (int i = 1; i <= ROWS; i++)
    for (int j = 1; j <= COLS; j++)
        seats[i][j] = '#';    

    int option = -1;
    int count = readFileToArray("inputfile.txt", price_arr, ROWS);
    if (count == 0) {
        cout << "Failed to read row prices from file.\n";
    }
    else if (count < ROWS) {
        cout << "Warning: Only " << count << " prices were read from the file. Remaining rows set to $0.0\n";
    } else {
        cout << "Row prices loaded from file successfully.\n";
    }
    while (option != 0) {
        cout << "\nMenu Options:\n";
        cout << "1. Input Row Prices\n";
        cout << "2. Purchase Ticket\n";
        cout << "3. Display Total Sales\n";
        cout << "0. Exit\n";

        while (true) {
            cout << "Please select an option (0-4): ";
            if (!(cin >> option)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 0 and 4.\n";
                continue;
            }
            if (option < 0 || option > 4) {
                cout << "Please enter a number between 0 and 4.\n";
                continue;
            }
            break;
        }

        if (option == 1) {
            cout << "Press 1 to manually input row prices, 2 to load from file, or 3 to return to menu: ";
            int price_option;
            cin >> price_option;
            do{
                cout << "Invalid option, please try again.\n";
                cout << "Press 1 to manually input row prices, 2 to load from file, or 3 to return to menu: ";
                cin >> price_option;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (cin.fail() || price_option < 1 || price_option > 3);

            if (price_option == 1) {
                updatePrice(price_arr, "inputfile.txt");
                cout << "Row prices updated.\n";
            }
            else if (price_option == 2) {
                cout << "What file name would you like to load from? (default: inputfile.txt): ";
                string filename;
                cin >> filename;
                int count = readFileToArray(filename, price_arr, ROWS);
                if (count == 0) {
                    cout << "Failed to read row prices from file.\n";
                }
                else if (count < ROWS) {
                    cout << "Warning: Only " << count << " prices were read from the file. Remaining rows set to $0.0\n";
                } else {
                    cout << "Row prices loaded from file successfully.\n";
                }
            }
            else if (price_option == 3){
                continue;
            }
            displaySeating(seats);
        }

        else if (option == 2) {
            int row, col;
            int purchase_type;
            cout << "Enter 1 for single ticket purchase, 2 for multiple tickets purchase or 3 to return to menu: ";
            cin >> purchase_type;
            do{
                cout << "Invalid option, please try again.\n";
                cout << "Enter 1 for single ticket purchase, 2 for multiple tickets purchase or 3 to return to menu: ";
                cin >> purchase_type;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (cin.fail() || purchase_type < 1 || purchase_type > 3);
            if (purchase_type==1){
                cout << "Enter the row (1-" << ROWS << "): "; cin >> row;
                cout << "Enter the seat (1-" << COLS << "): "; cin >> col;
                if (sellTicket(seats, price_arr, row, col, totalSales, totalTicketPrices)) {
                    saveState("seating_chart.txt", seats, price_arr, totalSales);
                } 
                else {
                    cout << "Ticket purchase failed.\n";
                }
                cout << "Ticket purchased successfully.\n";
                cout << "Total price: $" << fixed << setprecision(2) << totalTicketPrices << "\n";
                totalTicketPrices = 0.0;
            }
            else if(purchase_type==2){
                int n;
                cout << "Enter number of tickets to purchase: ";
                cin >> n;
                for (int i=0; i<n; i++){
                    cout << "Ticket " << (i+1) << ":\n";
                    cout << "Enter the row (1-" << ROWS << "): "; cin >> row;
                    cout << "Enter the seat (1-" << COLS << "): "; cin >> col;
                    if (sellTicket(seats, price_arr, row, col, totalSales, totalTicketPrices)) {
                        saveState("seating_chart.txt", seats, price_arr, totalSales);
                    } else {
                        cout << "Ticket purchase failed.\n";
                    }
                }
                cout << "Ticket purchased successfully.\n";
                cout << "Total price for " << n << " tickets: $" << fixed << setprecision(2) << totalTicketPrices << "\n";
                totalTicketPrices = 0.0;  
            }
            else if (purchase_type==3){
                continue;
            }
            displaySeating(seats);
        } 
        
        else if (option == 3) {
            showStatistics(seats, price_arr, totalSales);
        } 

        else if (option == 0) {
            cout << "Good bye!\n";
        }
    }

    return 0;
}