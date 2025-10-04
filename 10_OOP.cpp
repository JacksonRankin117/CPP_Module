#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Four pillars of OOP demonstrated here:

1. Encapsulation: data (name) and methods (speak) are wrapped in classes.
2. Inheritance: Dog and Cat inherit from Animal, reusing its code.
3. Polymorphism: virtual speak() allows us to call the right version for each object at runtime.
4. Abstraction: Animal provides a general interface without worrying about details of Dog or Cat.
*/

// ************************************************* Class Definitions *************************************************
// Demonstrates Encapsulation (data and methods are wrapped in a class)
// Also demonstrates Abstraction (general interface for all Animals)
class Animal {
  protected:
    string name; // Encapsulated data

  public:
    Animal(string n) : name(n) {} // Constructor

    // Virtual function for **Polymorphism** (allows derived classes to override)
    virtual void speak() {
        cout << name << " makes a sound." << endl;
    }

    // Virtual destructor ensures proper cleanup for derived objects
    virtual ~Animal() {
        cout << name << " is being destroyed." << endl;
    }
};

// Derived class 1
// Demos Inheritance (Dog inherits from Animal)
class Dog : public Animal {
  public:
    Dog(string n) : Animal(n) {}

    // Overrides base class method (**Polymorphism** in action)
    void speak() override {
        cout << name << " says: Woof!" << endl;
    }
};

// Derived class 2 
// Demos Inheritance and Polymorphism
class Cat : public Animal {
  public:
    Cat(string n) : Animal(n) {}

    void speak() override {
        cout << name << " says: Meow!" << endl;
    }
};

// *************************************************** Main program ****************************************************
int main() {
    cout << "=== Object-Oriented Programming Demonstration ===\n" << endl;

    // Using objects directly
    Dog dog1("Beka"); // Inherited constructor from Animal
    Cat cat1("Pepper");

    dog1.speak(); // Calls Dog::speak()
    cat1.speak();

    // Using pointers and polymorphism
    vector<Animal*> animals;
    animals.push_back(new Dog("Moon Obliterator"));
    animals.push_back(new Cat("Luna"));

    cout << "\nPolymorphic behavior with pointers:" << endl;
    for (Animal* a : animals) {
        a->speak(); // **Runtime Polymorphism**: calls the correct derived method
    }

    // Clean up dynamic memory
    for (Animal* a : animals) {
        delete a; // Properly calls derived class destructor
    }

    return 0;
}
