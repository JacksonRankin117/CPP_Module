#include <iostream>
#include <string>
#include <vector>
using namespace std;

// --- Base class ---
class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {} // Constructor

    virtual void speak() { // Virtual function for polymorphism
        cout << name << " makes a sound." << endl;
    }

    virtual ~Animal() { // Destructor
        cout << name << " is being destroyed." << endl;
    }
};

// --- Derived class 1 ---
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void speak() override { // Override base class method
        cout << name << " says: Woof!" << endl;
    }
};

// --- Derived class 2 ---
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void speak() override {
        cout << name << " says: Meow!" << endl;
    }
};

// --- Main program ---
int main() {
    cout << "=== Object-Oriented Programming Demonstration ===\n" << endl;

    // --- Using objects directly ---
    Dog dog1("Buddy");
    Cat cat1("Whiskers");

    dog1.speak();
    cat1.speak();

    // --- Using pointers and polymorphism ---
    vector<Animal*> animals;
    animals.push_back(new Dog("Rex"));
    animals.push_back(new Cat("Luna"));

    cout << "\nPolymorphic behavior with pointers:" << endl;
    for (Animal* a : animals) {
        a->speak(); // calls derived class method at runtime
    }

    // --- Clean up dynamic memory ---
    for (Animal* a : animals) {
        delete a; // calls destructor of derived class automatically
    }

    return 0;
}
