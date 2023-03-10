// SpeedProgrammingProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "Problems.h"
using namespace std;

void run_Ugly_Numbers() {
    for (int i = 1; i <= 150; i++) {
        cout << i << " ugly number dp: " << UglyNumbersDynamicProgramming(i) << endl;
        cout << i << " ugly number basic: " << UglyNumbersBasic(i) << endl;
    }
}

void run_SubsetSum() {
    vector<int> arr = { 1,2,3,4,5 };
    cout << "arr = { 1,2,3,4,5 }, sum = 9"<<endl;

    if (isSubsetSum(arr, 9) == true)
        cout << "yes";
    else
        cout << "no";
    cout << endl;
}


void run_NthFibonacci() {
    long long n;
    cout << "Enter the value of N.\n n=";
    cin >> n;

    cout<<"Fibonacci term is: "<<nthFibonacci(n)<<endl;
}

int main()
{
    char c = 'y';
    do {
        system("cls");
        int n;
        cout << "Problem to run:" << endl;
        cout << "1. Ugly Numbers" << endl;
        cout << "2. Subset Sum" << endl;
        cout << "3. Nth Fibonacci Number" << endl;
        cin >> n;
        switch (n) {
        case 1:         //////////// 1. Ugly Numbers ///////////
            run_Ugly_Numbers();
            break;
        case 2:         //////////// 2. Subset Sum   ///////////
            run_SubsetSum();
            break;
        case 3:         //////////// 3. Fibonacci    ///////////
            run_NthFibonacci();
            break;
        default:        //////////// Default         ///////////
            cout << "Try again..."<<endl;
        }
        cout << "Running again... y/n?"<<endl;
        cin >> c;
    } while (c == 'y' || c == 'Y');
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
