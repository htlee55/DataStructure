#include "CircularCustomerDeque.h"
#include "Customer.h"
#include <cstdio>
using namespace std;

int main(void) {
	CircularCustomerDeque male, female;
	int id = 1;
	char name[20];
	char gender;
	char priority;
	printf("덱을 이용한 우선배정 미팅 주선 프로그램\n");
	while (true) {
		printf("학생의 이름을 입력하세요: ");
		scanf_s("%s", name, (unsigned)_countof(name));
		printf("성별을 입력하세요 (m:남학생,f:여학생): ");
		scanf_s(" %c", &gender, 1);
		printf("우선 주선을 희망하시나요? (y:희망,n:일반): ");
		scanf_s(" %c", &priority, 1);
		Customer student(id, gender, name, priority);
		if (gender == 'm' || gender == 'M') {
			if (priority == 'y' || priority == 'Y') {
				male.addFront(student); // 우선 주선 희망 남학생은 앞에 추가
				printf("우선 주선 희망 남학생 %s이(가) 대기열 앞쪽에 추가되었습니다.\n", name);
			}
			else {
				male.addRear(student); // 일반 남학생은 뒤에 추가
				printf("일반 남학생 %s이(가) 대기열에 추가되었습니다.\n", name);
			}
		}
		else if (gender == 'f' || gender == 'F') {
			if (priority == 'y' || priority == 'Y') {
				female.addFront(student); // 우선 주선 희망 여학생은 앞에 추가
				printf("우선 주선 희망 여학생 %s이(가) 대기열 앞쪽에 추가되었습니다.\n", name);
			}
			else {
				female.addFront(student); // 일반 여학생은 뒤에 추가
				printf("일반 여학생 %s이(가) 대기열에 추가되었습니다.\n", name);
			}
		}
		else {
			printf("잘못된 성별 입력입니다. 남학생은 'm', 여학생은 'f'로 입력해주세요.\n");
			continue; // 잘못된 입력이므로 다음 루프로 넘어감
		}
		id++; // 다음 학생의 ID 증가

		// 남학생 큐와 여학생 큐에 모두 학생이 있을 때 미팅 주선	
		if (!male.isEmpty() && !female.isEmpty()) {
			Customer man = male.dequeue();
			Customer woman = female.dequeue();
			printf("커플이 탄생하였습니다: 남학생 %s, 여학생 %s\n", man.getName(), woman.getName());
		}
		else {
			printf("아직 커플이 탄생하지 않았습니다. 대기열에서 기다려주세요.\n");
			printf("현재 대기열 상태: 남학생 %d명, 여학생 %d명\n", male.size(), female.size());
		}
		printf("계속진행하려면 아무 키나 누르세요...\n");
		getchar(); // 사용자 입력 대기
	}
	return 0;
}
