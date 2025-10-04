#include <iostream>
#include <string>

using namespace std;

// ******************************************************* Main ********************************************************
int main() {
    cout << "=== Control Flow Demonstration ===" << endl;

    // IF / ELSE IF / ELSE
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (number > 0) {
        cout << number << " is positive." << endl;
    } else if (number < 0) {
        cout << number << " is negative." << endl;
    } else {
        cout << "You entered zero." << endl;
    }

    // SWITCH STATEMENT
    char grade;
    cout << "\nEnter your grade (A, B, C, D, F): ";
    cin >> grade;

    switch (grade) {
        case 'A':
            cout << "Excellent work!" << endl;
            break;
        case 'B':
            cout << "Good job!" << endl;
            break;
        case 'C':
            cout << "Fair effort." << endl;
            break;
        case 'D':
            cout << "You passed, but try harder next time." << endl;
            break;
        case 'F':
            cout << "Failed. Better luck next time." << endl;
            break;
        default:
            cout << "Invalid grade." << endl;
            break;
    }

    // FOR LOOP with CONTINUE
    cout << "\nEven numbers from 1 to 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) continue; // skip odd numbers
        cout << i << " ";
    }
    cout << endl;

    // WHILE LOOP with BREAK
    int count = 0;
    cout << "\nCounting until 5 using while loop:" << endl;
    while (true) {
        count++;
        if (count > 5) break; // exit loop when count exceeds 5
        cout << count << " ";
    }
    cout << endl;

    // DO-WHILE LOOP
    string answer;
    do {
        cout << "\nDo you want to continue? (yes/no): ";
        cin >> answer;
    } while (answer == "yes");

    cout << "\nProgram finished. Goodbye!" << endl;

    return 0;
}
