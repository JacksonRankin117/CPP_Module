#include <iostream> 
#include <string>  // Must include the string header to use the string data type

using namespace std;

// ******************************************************* Main ********************************************************
int main() {
    string name;

    cout << "Hi, What is your name?" << endl;
    getline(cin, name);  // Can also do cin >> name, but that stops after it detects a space

    cout << "Hi, " << name << "!";
    return 0;
}