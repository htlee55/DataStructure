// 04장-BankSimulator.cpp: 은행 시뮬레이션 프로그램
#include <ctime>	// 시간 관련 라이브러리
#include <cstdlib>	// 난수 생성 라이브러리
#include "BankSimulator.h"
int main()
{
	srand((unsigned int)time(NULL));		// 난수 생성 시드 설정
	BankSimulator sim;						// 시뮬레이터 객체 생성
	sim.readSimulationParameters();			// 시뮬레이션 파라미터 설정
	sim.run();								// 시뮬레이션 시작
	sim.printStat();						// 시뮬레이션 결과 출력
	return 0;
}
