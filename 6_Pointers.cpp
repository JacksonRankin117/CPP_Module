#include <iostream>

using namespace std;

// --- Function Declarations ---
void increment(int *ptr);     // function using pointer
void printArray(int *arr, int size); // function with pointer to array

// ******************************************************* Main ********************************************************
int main() {
    cout << "=== Pointer Demonstration ===\n" << endl;

    // --- Basic pointer usage ---
    int a = 10;
    int *p = &a; // pointer to int

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Pointer p (holds address of a): " << p << endl;
    cout << "Value pointed to by p (*p): " << *p << endl;

    // --- Modifying value using pointer ---
    *p = 20; // changes a through pointer
    cout << "New value of a after *p = 20: " << a << endl;

    // --- Passing pointer to function ---
    increment(&a);
    cout << "Value of a after increment function: " << a << endl;

    // --- Pointer and arrays ---
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "\nArray values using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << *(arr + i) << " "; // Int array arr decays into pointer
    }
    cout << endl;

    cout << "\nPrinting array with function:" << endl;
    printArray(arr, 5);

    // --- Dynamic memory allocation ---
    int *dynArr = new int[3]; // allocate array of size 3
    dynArr[0] = 100;
    dynArr[1] = 200;
    dynArr[2] = 300;

    cout << "\nDynamically allocated array:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << dynArr[i] << " ";
    }
    cout << endl;

    delete[] dynArr; // free memory

    return 0;
}

// --- Function Definitions ---
void increment(int *ptr) {
    (*ptr)++; // dereference pointer and increment value
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
