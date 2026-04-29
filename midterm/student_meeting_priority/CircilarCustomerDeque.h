#pragma once
#include "Customer.h"
#include "CircularCustomerQueue.h"
#define MAX_QUEUE_SIZE 100
#include <cstdio>
#include <cstdlib>

class CircularCustomerDeque : public CircularCustomerQueue
{
public:
	CircularCustomerDeque() : CircularCustomerQueue() {			// 부모 클래스의 생성자 호출
	}
	void addRear(const Customer& customer) {
		enqueue(customer); // 부모 클래스의 enqueue 함수 사용
	}
	Customer& deleteFront() {
		return dequeue(); // 부모 클래스의 dequeue 함수 사용
	}
	Customer& getFront() {
		return peek(); // 부모 클래스의 peek 함수 사용
	}
	void addFront(const Customer& customer) {
		if (isFull()) return; // Queue is full
		front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		data[front] = customer;
	}
	Customer& deleteRear() {
		if (isEmpty()) error("Queue is empty"); // Queue is empty
		rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return data[rear];
	}
	Customer& getRear() {
		if (isEmpty()) error("Queue is empty"); // Queue is empty
		int rearIndex = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return data[rearIndex];
	}
	void display() {
		if (isEmpty()) {
			printf("Deque is empty\n");
			return;
		}
		printf("Deque contents: ");
		int index = front;
		while (index != rear) {
			printf("%s ", data[index].getName());
			index = (index + 1) % MAX_QUEUE_SIZE;
		}
		printf("\n");
	}
};
