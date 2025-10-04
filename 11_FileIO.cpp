#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ********************************************* Struct for demonstration **********************************************
struct Student {
    string name;
    int age;
    double gpa;
};

// *************************************************** Main program ****************************************************
int main() {
    cout << "=== File Input/Output Demonstration ===\n" << endl;

    // Writing to a file
    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;  // Throws an error just for fun
        return 1;
    }

    Student s1 = {"Jackson", 20, 3.75};
    Student s2 = {"John", 21, 3.90};
    Student s3 = {"Demetrius DeMarcus Bartholemew James III Junior", 19, 3.60};

    outFile << s1.name << " " << s1.age << " " << s1.gpa << endl;
    outFile << s2.name << " " << s2.age << " " << s2.gpa << endl;
    outFile << s3.name << " " << s3.age << " " << s3.gpa << endl;

    outFile.close();
    cout << "Data written to students.txt" << endl;

    // Reading from a file
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nReading data from students.txt:" << endl;
    string name;
    int age;
    double gpa;

    while (inFile >> name >> age >> gpa) {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }

    inFile.close();

    return 0;
}
