// 10장-HoffmanCode.cpp: 허프만 코드 프로그램
#include "MinHeap.h"	// 최소 힙 사용
// 허프만 코드 생성 함수
void MakeTree( int freq[], int n ) {

	MinHeap	heap;
	for(int i=0;i<n;i++) 
		heap.insert( freq[i] );			// 모든 노드 삽입

	for(int i=1;i<n;i++){
		HeapNode& e1 = heap.remove();	// 최소 노드 삭제
		HeapNode& e2 = heap.remove();	// 다음 최소 노드 삭제

		heap.insert( e1.getKey() + e2.getKey() );	// 합한 노드 추가
		printf( " (%d+%d)\n", e1.getKey(), e2.getKey() );
	}
}

int main()
{
//	char label[] = { 'A', 'B', 'C', 'D', 'E' };
	int  freq[] = { 15, 12, 8, 6, 4 };		// A, B, C, D, E 문자 사용 빈도
	MakeTree( freq, 5 );
}

