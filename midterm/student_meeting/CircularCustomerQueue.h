#pragma once
#include "Customer.h"
#define MAX_QUEUE_SIZE 100
#include <cstdio>
#include <cstdlib>

inline void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

class CircularCustomerQueue
{
	private:
	Customer data[MAX_QUEUE_SIZE];
	int front;
	int rear;
public:	
	CircularCustomerQueue() : front(0), rear(0) {
	}
	~CircularCustomerQueue() { }	
	bool isEmpty(){ return front == rear;}
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(const Customer& customer) {
		if (isFull()) return; // Queue is full
		data[rear] = customer;
		rear = (rear + 1) % MAX_QUEUE_SIZE;
	}
	Customer& dequeue() {
		if (isEmpty()) error("Queue is empty"); // Queue is empty
		else {
			Customer& customer = data[front];
			front = (front + 1) % MAX_QUEUE_SIZE;
			return customer;
		}
	}
	int size() const {
		if (rear >= front) {
			return rear - front;
		} else {
			return MAX_QUEUE_SIZE - (front - rear);
		}
	}	
};
