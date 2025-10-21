#include <iostream>
#include <iomanip>
#include "main.h"
using namespace std;

bool readPositiveNumber(double &x){
    while (1){
        if (cin>>x )
        if (x>0)
            return true;
            else {
                cout<<"Error: The number must be positive. Please re-enter: ";
            }
    }
}


bool inputRowPrice(double price_arr[ROWS]){
    cout <<"Enter the prices for "<< ROWS <<" rows: "<< endl;
    for (int i=1; i<=ROWS; i++){
        cout <<"Price for row "<< (i) <<": $";
        if (!readPositiveNumber(price_arr[i])){
            return false;
        }
    }
    return true;
}