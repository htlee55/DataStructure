#include <iostream>
#include "Car.h"
#include "SportsCar.h"

using namespace std;

int main() {

    cout << "===== Car =====" << endl;
    Car c(0, "MyCar", 1);
    c.speedUp();
    c.speedUp();
    c.display();

    cout << endl;

    cout << "===== SportsCar =====" << endl;
    SportsCar sp(0, "Ferrari", 1);
    sp.speedUp();
    sp.display();

    sp.setTurbo(true);
    sp.speedUp();
    sp.speedUp();
    sp.display();

    cout << endl;

    return 0;
}
