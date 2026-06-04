// MaxHeap.h: 최대 힙 테스트 프로그램
#include "MaxHeap.h"	// 최대 힙 클래스 포함

// 주함수 
void main()
{
	MaxHeap	heap;

	// 삽입
	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(9);
	heap.insert(3);
	heap.insert(7);
	heap.display();

	// 삭제
	heap.remove();
	heap.display();
	heap.remove();
	heap.display();
	printf("\n");
}
