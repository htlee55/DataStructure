#include "Car.h"

int main() {

    Car cars[3] = {
        Car(0, "Avante", 1),
        Car(10, "Sonata", 2),
        Car(20, "Grandeur", 3)
    };

    for (int i = 0; i < 3; i++) {
        cars[i].display();
    }

    return 0;
}
