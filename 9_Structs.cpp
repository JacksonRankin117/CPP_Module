#include <iostream>
#include <string>
using namespace std;

// --- Simple struct ---
struct Point {
    double x;
    double y;
};

// --- Struct with functions ---
struct Rectangle {
    double width;
    double height;

    double area() {            // member function allowed in structs
        return width * height;
    }

    double perimeter() {
        return 2 * (width + height);
    }
};

// --- Class for comparison ---
class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() {
        return 3.14159 * radius * radius;
    }

    double perimeter() {
        return 2 * 3.14159 * radius;
    }
};

int main() {
    cout << "=== Structs and Classes Demonstration ===\n" << endl;

    // --- Using a simple struct ---
    Point p1;
    p1.x = 3.0;
    p1.y = 4.0;
    cout << "Point coordinates: (" << p1.x << ", " << p1.y << ")" << endl;

    // --- Struct with member functions ---
    Rectangle rect;
    rect.width = 5.0;
    rect.height = 10.0;
    cout << "Rectangle area: " << rect.area() << endl;
    cout << "Rectangle perimeter: " << rect.perimeter() << endl;

    // --- Class usage ---
    Circle circ(7.0);
    cout << "Circle area: " << circ.area() << endl;
    cout << "Circle perimeter: " << circ.perimeter() << endl;

    // --- Key differences ---
    cout << "\nKey Differences Between Struct and Class in C++:" << endl;
    cout << "1. Default access specifier: struct = public, class = private" << endl;
    cout << "2. Structs are usually for plain data, classes for encapsulation and OOP" << endl;
    cout << "3. Structs can have member functions, constructors, etc., same as classes" << endl;

    return 0;
}
