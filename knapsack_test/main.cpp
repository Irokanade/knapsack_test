//
//  main.cpp
//  knapsack_test
//
//  Created by Michael Leong on 03/04/2022.
//

#include <iostream>
using namespace std;

int64_t MyMax(int64_t a, int64_t b);

int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << "Hello, World!\n";
    
    int64_t noOfTypes;
    int64_t maxWeight; //maximum weight bob can stand
    
    cin >> noOfTypes;
    cin >> maxWeight;
    
    int64_t itemArray[noOfTypes][3];
    
    for(int64_t i = 0; i < noOfTypes; i++) {
        cin >> itemArray[i][0]; //item weight
        cin >> itemArray[i][1]; //item value
        cin >> itemArray[i][2]; //item amount
    }
    
    //print itemArray
    /*for(int64_t i = 0; i < noOfTypes; i++) {
        cout << itemArray[i][0] << ' '; //item weight
        cout << itemArray[i][1] << ' '; //item value
        cout << itemArray[i][2] << '\n'; //item amount
    }*/
    
    //dynamic programming approach
    int64_t table[noOfTypes+1][maxWeight+1];
    
    //init first row to zero
    for(int64_t i = 0; i <= maxWeight; i++) {
        table[0][i] = 0;
    }
    
    //init first column to zero
    for(int64_t i = 0; i <= noOfTypes; i++) {
        table[i][0] = 0;
    }
    
    for(int64_t i = 1; i <= noOfTypes; i++) {
        for(int64_t j = 1; j <= maxWeight; j++) {
            if(j-itemArray[i-1][0] >= 0) {
                table[i][j] = MyMax(table[i-1][j], table[i-1][j-itemArray[i-1][0]]+itemArray[i-1][1]);
            } else {
                //cout << "else";
                table[i][j] = table[i-1][j];
            }
        }
    }
    
    for(int64_t i = 0; i <= noOfTypes; i++) {
        for(int64_t j = 0; j <= maxWeight; j++) {
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
    
    cout << "max value: " << table[noOfTypes][maxWeight] << '\n';
    
    //print which items
    int64_t remainWeight = maxWeight;
    for(int64_t i = noOfTypes; i > 0; i--) {
        if(table[i][remainWeight] != table[i-1][remainWeight]) {
            cout << "item " << i << '\n';
            remainWeight -= itemArray[i-1][0];
        }
    }
    
    return 0;
}

int64_t MyMax(int64_t a, int64_t b) {
    if(a > b) {
        return a;
    }
    
    return b;
}
