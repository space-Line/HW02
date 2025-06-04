#include <iostream>
#include "string"
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "멍멍" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "야옹" << endl;
    }
};

class Cow : public Animal {
public:
    void makeSound() {
        cout << "음머" << endl;
    }
};

class Zoo {
private:
    Animal* animals[10];
    int count = 0;
public:
    void addAnimal(Animal* animal) {
        animals[count++] = animal;
    }

    void performActions() {
        for (int i = 0; i < 10; i++) {
            animals[i]->makeSound();
        }
    }

    ~Zoo() {
        for (int i = 0; i < 10; i++) {
            delete animals[i];
            animals[i] = nullptr;
        }
    }
};

Animal* createRandomAnimal() {
    int ran = rand() % 3;
    if (ran == 0) {
        return new Dog();
    }
    else if (ran == 1) {
        return new Cat();
    }
    else {
        return new Cow();
    }
}

int main() {
    Zoo zoo;

    for (int i = 0; i < 10; i++) {
        Animal* animal = createRandomAnimal();
        zoo.addAnimal(animal);
    }

    zoo.performActions();

    return 0;
}