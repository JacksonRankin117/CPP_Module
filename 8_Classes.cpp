#include <iostream>
#include <string>
using namespace std;

// ************************************************* Class definition **************************************************
class Person {
  private:
    string name;
    int age;

  public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    // Member function to display info
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Member function to set age
    void setAge(int a) {
        if (a >= 0) age = a;
    }

    // Member function to get age
    int getAge() {
        return age;
    }
};

// ******************************************************* Main ********************************************************
int main() {
    cout << "=== Class Introduction Demonstration ===\n" << endl;

    // Creating objects
    Person person1("Jackson", 20);
    Person person2("Luna", 21);

    // Accessing member functions
    person1.displayInfo();
    person2.displayInfo();

    // Modify age using setter
    person1.setAge(21);
    cout << "\nAfter updating age:" << endl;
    person1.displayInfo();

    // Access age using getter
    cout << "Person1 is " << person1.getAge() << " years old." << endl;

    return 0;
}
