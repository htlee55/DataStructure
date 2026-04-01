#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include "Car.h"

class SportsCar : public Car {
private:
    bool bTurbo;

public:
    SportsCar();
    SportsCar(int s, const char* n, int g, bool turbo = false);

    void setTurbo(bool turbo);
    void speedUp() override;
    void display() override;
};

#endif
