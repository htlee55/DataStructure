#pragma once
#include <cstdio>
/*#include <cstdlib>
#define MAX_STACK_SIZE	100

inline void error( const char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};
*/
class Node
{
	Node*	link;
	int		data;

public:
	Node(int val = 0) : data(val), link(NULL) {}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { printf(" <%2d>", data); }
	bool hasData(int val) { return data == val; }

	void insertNext(Node* n) {			// n이 NULL이 아니면 n을 link의 앞에 삽입
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	Node* removeNext() {				// link이 NULL이 아니면 link를 제거하고 제거된 link를 반환
		Node* removed = link;
		if (removed != NULL)
			link = removed->link;
		return removed;
	}
};

