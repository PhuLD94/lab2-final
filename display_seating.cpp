#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
using namespace std;




void displaySeating(char seats[ROWS][COLS])
{
    cout << setw(26) << "Seats\n";
    cout << setw(8) << " ";
    for(int c = 1; c <= COLS; c++)
    {
        cout << (c % 10);
    }
    cout << endl;
    for (int r = 1; r <= ROWS; r++)
    {
        cout << "Row" << setw(3) << r << "  ";
        for(int c = 1; c <= COLS; c++)
        {
            cout << seats[r][c];
        }
        cout << endl;
    }
    
}
