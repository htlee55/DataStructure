#include "Car.h"			// 자동차 클래스 헤더파일 포함
// 스포츠카 클래스 (자식 클래스) : 자동차 클래스에 터보 기능 추가
class SportsCar : public Car
{
public:
	bool bTurbo;		// 터보 장치 사용 여부
	SportsCar(int s, char* n, int g) : Car(s, n, g), bTurbo(true) {}
	void setTurbo(bool bTur) { bTurbo = bTur; }
	void speedUp() {		// 터보가 On이 되어 있으면 가속이 빨리됨
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};
