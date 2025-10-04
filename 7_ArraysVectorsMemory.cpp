#include <iostream>
#include <vector>
using namespace std;

// --- Function declarations ---
void printArray(int arr[], int size);
void printVector(const vector<int> &vec);

int main() {
    cout << "=== Arrays, Vectors, and Memory Demonstration ===\n" << endl;

    // --- Fixed-size array ---
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Fixed-size array:" << endl;
    printArray(arr, 5);

    // --- Vector (dynamic array) ---
    vector<int> vec = {1, 2, 3};
    cout << "\nInitial vector:" << endl;
    printVector(vec);

    // Adding elements dynamically
    vec.push_back(4);
    vec.push_back(5);
    cout << "Vector after push_back:" << endl;
    printVector(vec);

    // Removing last element
    vec.pop_back();
    cout << "Vector after pop_back:" << endl;
    printVector(vec);

    // Iterating with range-based for
    cout << "Vector elements (range-based for): ";
    for (int val : vec) cout << val << " ";
    cout << endl;

    // --- Dynamic memory allocation ---
    int n;
    cout << "\nEnter size of dynamic array: ";
    cin >> n;

    int *dynArr = new int[n]; // allocate dynamic array
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> dynArr[i];
    }

    cout << "Dynamic array contents: ";
    for (int i = 0; i < n; i++) cout << dynArr[i] << " ";
    cout << endl;

    delete[] dynArr; // free dynamic memory

    return 0;
}

// --- Function definitions ---
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void printVector(const vector<int> &vec) {
    for (int val : vec) cout << val << " ";
    cout << endl;
}
