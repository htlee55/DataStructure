#ifndef CAR_H
#define CAR_H
// Visual Studio에서는 #pragma once를 사용하여 중복 include 문제를 해결

class Car {
protected:
    int speed;
    char name[40];

public:
    int gear;

    Car();
    Car(int s, const char* n, int g);

    void changeGear(int g = 1);
    virtual void speedUp();        // 자식 클래스에서 다르게 동작하도록 재정의할 수 있게 하기 위함, override 사용
    void speedDown();
    void stop();
    bool isStopped();

    virtual void display();
};

#endif
