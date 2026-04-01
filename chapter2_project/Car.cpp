#include "Car.h"
#include <iostream>
#include <cstring>
using namespace std;

Car::Car() {
    speed = 0;
    gear = 1;
    strcpy_s(name, "noname");
}

Car::Car(int s, const char* n, int g) {
    speed = s;
    gear = g;
    strcpy_s(name, n);
}

void Car::changeGear(int g) {
    gear = g;
}

void Car::speedUp() {
    speed += 5;
}

void Car::speedDown() {
    speed -= 5;
    if (speed < 0) speed = 0;
}

void Car::stop() {
    speed = 0;
}

bool Car::isStopped() {
    return speed == 0;
}

void Car::display() {
    cout << "[" << name << "] "
         << "기어: " << gear
         << ", 속도: " << speed << " km/h" << endl;
}
