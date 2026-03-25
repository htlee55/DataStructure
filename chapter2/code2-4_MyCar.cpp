#include "SportsCar.h"
int main()
{
	char carName[40] = "내차";			// 차 이름 문자열

	SportsCar myCar(0, carName, 4);		// SportsCar형 객체 생성
	printf("튜닝 이전 차\n");			
	myCar.display();
	myCar.whereAmI();

	myCar.changeGear(10);
	myCar.speedUp();
	printf("튜닝 이후 차\n");
	myCar.display();
	myCar.whereAmI();

	return 0;
}
