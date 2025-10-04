#include <iostream>
#include <string>

using namespace std;

// *********************************************** Function Declarations ***********************************************
int add(int a, int b);                    // Returns the sum
double add(double a, double b);           // overloaded version
void greet(string name);                  // prints greeting
void swapValues(int &x, int &y);          // pass by reference
int factorial(int n);                     // recursive function


// ******************************************************* Main ********************************************************
int main() {
    cout << "=== Function Demonstration ===\n" << endl;

    // --- Using a function with return value ---
    int x = 5, y = 7;
    cout << "add(int, int): " << add(x, y) << endl;

    double dx = 3.14, dy = 2.71;
    cout << "add(double, double): " << add(dx, dy) << endl;

    // --- Void function ---
    greet("Jackson");

    // --- Pass by reference ---
    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap:  x = " << x << ", y = " << y << endl;

    // --- Recursive function ---
    int n;
    cout << "\nEnter a number for factorial: ";
    cin >> n;
    cout << "factorial(" << n << ") = " << factorial(n) << endl;

    return 0;
}

// ************************************************ Function Definitions ***********************************************
// Simple function with return
int add(int a, int b) {
    return a + b;
}

// Overloaded function (same name, but different variable types.)
double add(double a, double b) {
    return a + b;
}

// Void function (no return value)
void greet(string name) {
    cout << "\nHello, " << name << "! Welcome to the program." << endl;
}

// Pass by reference. This means that variables in another function are modified to be different.
void swapValues(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Recursive function (factorial definition)
int factorial(int n) {
    if (n <= 1) return 1;   // base case
    return n * factorial(n - 1); // recursive case
}
