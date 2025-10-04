#include <iostream> // must include the iostream header for input/output to/from the console

// Not the best practive with large files, but shortens std::cout so I don't have to type std:: every time I want to use something in the standard namespace
using namespace std;

int main() {
    // cout will output data to the console. endl will remove the buffer so it displays immediately
    cout << "Hello, world!" << endl;
    return 0;
}