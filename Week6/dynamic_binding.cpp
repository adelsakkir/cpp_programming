#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal speaks." << endl; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Dog barks." << endl; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Cat meows." << endl; }
};

void makeAnimalSpeak(Animal* animal) {
    animal->speak();  // Polymorphic behavior
}

int main() {
    Dog d;
    Cat c;
    makeAnimalSpeak(&d);  // Dog barks.
    makeAnimalSpeak(&c);  // Cat meows.
    return 0;
}
