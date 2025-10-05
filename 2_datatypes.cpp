#include <iostream>

using namespace std;

// Initilize function to demonstrate void datatype
void example();

// ******************************************************* Main ********************************************************
int main() {

    /*************************************************  Integer types *************************************************/
    int a;        // Standard integer, 4 bytes
    short b;      // Shorter integer, 2 bytes
    long c;       // Larger integer, at least 4 bytes, but depends on the system
    long long d;  // Even larger integer, at least 8 bytes, but depends on the system

    // 'signed' modifier: default, can hold positive and negative values.
    // 'unsigned' modifier: only positive values, but higher max.
    // For example, an unsigned long long has a range from 0 -> 18,446,744,073,709,551,615
    // But a signed long long has a range from −9,223,372,036,854,775,808 -> 9,223,372,036,854,775,807

    /************************************************  Character types ************************************************/
    char e;     // Stores one character, 1 byte
    wchar_t f;  // This is for character sets that contain more than 256 characters, like Japanese, 4 bytes
    char16_t g; // This is for UTF-16 encoding, 16 bits
    char32_t h; // This is for UTF-32 encoding, 32 bits

    // 'signed' and 'unsigned' modifier can be applied to chars. 
    // signed chars have a range from -128 -> 127
    // unsigned chars have a range from 0 -> 255, which is good if you are working with low numbers
    // (Like in 8-bit color channels)

    /*********************************************  Floating point types **********************************************/
    float i;        // Single precision -> 6-7 digits, 4 bytes,
    double j;       // Double precision -> 15-16 digits, 8 bytes
    long double k;  // Extended precision, 15-19 digits, 8 bytes

    /*************************************************  Boolean type **************************************************/
    bool l;  // Can hold a 1 or a 0 (1 is True, and 0 is False)

    /***************************************************  Void type ***************************************************/
    // Call the void function
    example();

    // Another important thing: the const keyword will make it impossible for the value of the datatype to be changed.
    // As an example, you might want to do this with physical constants, like G or PI. C++ convention with constants
    // is to capitalize each constant datatype. As an example:
    const double PI = 3.141592653589792328;

    return 0;

}

/************************************************  Void type continued ************************************************/
void example() {
    // Example code (can't return a value)
    cout << "This is a function that doesn't return a value";
}