#pragma once
// StudentStatck.h : 학생정보 스택 클래스
#include "Student.h"
#include "Utility.h"
#define MAX_STACK_SIZE	100		// 스택의 최대 크기 설정

class StudentStack {
	int top;						// 요소의 개수
	Student data[MAX_STACK_SIZE];	// 요소의 배열
public:
	StudentStack() { top = -1; }
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(Student e) {		// 맨 위에 항목 삽입
		if (isFull()) error("스택 포화 에러");
		data[++top] = e;
	}
	Student pop() {				// 맨 위의 요소를 삭제하고 반환
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}
	Student peek() {			// 삭제하지 않고 맨 위 요소 반환
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}
	void display() {			// 스택 내용을 화면에 출력
		printf("[전체 학생의 수 = %2d]\n", top + 1);
		for (int i = 0; i <= top; i++)
			data[i].display();
		printf("\n");
	}
};
