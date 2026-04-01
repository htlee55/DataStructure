// ArrayStack.h : 배열을 이요한 int 스택 클래스
#include <cstdio>	// C 헤더파일 <stdio.h>을 포함하는 것과 동일
#include <cstdlib>  // C 헤더파일 <stdlib.h>을 포함하는 것과 동일

// 오류 처리 함수
inline void error(const char* message) {
	printf("%s\n", message);
	exit(1);
}

const int MAX_STACK_SIZE = 20;		// 스택의 최대 크기 설정
class ArrayStack
{
	int top;						// 요소의 개수
	int data[MAX_STACK_SIZE];		// 요소의 배열
public:
	ArrayStack();	// 스택 성성자
	~ArrayStack();																	// 스택 소멸자
	bool isEmpty();
	bool isFull();
	void push(int e);
	int pop();
	int peek();
	void display();
};
