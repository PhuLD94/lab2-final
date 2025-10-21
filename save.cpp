#include <iostream>
#include <fstream>
#include <string>
#include "main.h"

using namespace std;
#include <iomanip>
#include <sstream>



bool saveState(const char *filename, char seats[ROWS][COLS], double price_arr[ROWS], double totalSales) {
    ofstream out(filename, ios::out | ios::trunc); // reset file
    if (!out) {
        cout << "Can not open the file to write.\n";
        return false;
    }

    // Luu so do ghe: 15 dong, moi dong 30 ky tu
    for (int r = 1; r <= ROWS; ++r) {
        for (int c = 1; c <= COLS; ++c) {
            out << seats[r][c];
        }
        out << '\n';
    }

    // Luu gia tung hang
    // for (int r = 0; r < ROWS; ++r) {
    //     out << price_arr[r];
    //     if (r + 1 < ROWS) out << ' ';
    // }
    // out << '\n';

    // Luu totalSales
    // out << totalSales << '\n';

    return true;
}

//  bool loadState(const char *filename, char seats[ROWS][COLS], double price_arr[ROWS], double &totalSales) {
//     ifstream in(filename, ios::out | ios::trunc);
//     if (!in) {
//         cout << "Can not open the file to read.\n";
//         return false;
//     }

    

//     string line;

//     // Doc so do ghe
//     for (int r = 0; r < ROWS; ++r) {
//         if (!getline(in, line)) {
//             cout << "File khong dung dinh dang (thieu dong ghe).\n";
//             return false;
//         }
//         if ((int)line.size() < COLS) {
//             cout << "Dong ghe " << (r + 1) << " khong du " << COLS << " ky tu.\n";
//             return false;
//         }
//         for (int c = 0; c < COLS; ++c) {
//             char ch = line[c];
//             if (ch == '*') seats[r][c] = true;
//             else if (ch == '#') seats[r][c] = false;
//             else {
//                 cout << "Ky tu khong hop le trong so do ghe: '" << ch << "'\n";
//                 return false;
//             }
//         }
//     }

//     // Doc gia ve tung hang
//     for (int r = 0; r < ROWS; ++r) {
//         if (!(in >> price_arr[r])) {
//             cout << "File khong dung dinh dang (gia hang " << (r + 1) << ").\n";
//             return false;
//         }
//         if (price_arr[r] <= 0) {
//             cout << "Gia hang " << (r + 1) << " phai > 0.\n";
//             return false;
//         }
//     }

//     // Doc totalSales
//     if (!(in >> totalSales)) {
//         cout << "File khong dung dinh dang (totalSales).\n";
//         return false;
//     }

    
//     return true;
// }
    
