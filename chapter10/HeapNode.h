#pragma once
// HeapNode.h: 힙에 저장할 노드 클래스
#include <cstdio>
class HeapNode {
	int		key;		// key 값
public:
	HeapNode(int key = 0) : key(key) {}
	void setKey(int k) { key = k; }
	int	 getKey() { return key; }
	void display() { printf("\t%4d", key); }
};


