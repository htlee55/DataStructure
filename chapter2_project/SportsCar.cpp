#include "SportsCar.h"
#include <iostream>
using namespace std;

SportsCar::SportsCar() : Car() {
    bTurbo = false;
}

SportsCar::SportsCar(int s, const char* n, int g, bool turbo)
    : Car(s, n, g) {
    bTurbo = turbo;
}

void SportsCar::setTurbo(bool turbo) {
    bTurbo = turbo;
}

void SportsCar::speedUp() {
    if (bTurbo)
        speed += 20;
    else
        speed += 5;
}

void SportsCar::display() {
    cout << "[" << name << "] "
         << "기어: " << gear
         << ", 속도: " << speed << " km/h"
         << ", 터보: " << (bTurbo ? "ON" : "OFF") << endl;
}
