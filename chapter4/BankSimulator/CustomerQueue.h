#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	100

class CustomerQueue
{
	int		front;
	int		rear;
	Customer data[MAX_QUEUE_SIZE];
public:
	CustomerQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(Customer& val) {
		if (isFull() == false) {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	Customer& dequeue() {			// 큐에서 고객을 꺼내는 함수, 큐가 비어있으면 에러 메시지를 출력하고 의미 없는 값을 반환,Customer& 타입의 참조를 반환,Customer 객체를 반환하는 것이 아니라 Customer 객체에 대한 참조를 반환,이렇게 하면 큐에서 꺼낸 고객 객체를 직접 수정할 수 있음,누가	 이 함수를 호출할 때 반환된 참조를 사용하여 고객 객체의 속성을 변경할 수 있음,예를 들어, 고객의 대기 시간을 계산하여 고객 객체의 tWait 속성에 저장할 수 있음
		if (isEmpty()) {
			error("공백 상태 에러");
			return data[0];		// 의미 없음
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};

