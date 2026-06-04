// MinHeap.h: 최소 힙 클래스
#include "HeapNode.h"
#define MAX_ELEMENT	200

class MinHeap
{
	HeapNode node[MAX_ELEMENT];		// 요소의 배열
	int		 size;					// 힙의 현재 요소의 개수
public:
	MinHeap( ) : size(0) { }
	bool isEmpty()	{ return size == 0; }
	bool isFull()	{ return size == MAX_ELEMENT-1; }

	HeapNode&	getParent(int i){ return node[i/2]; }
	HeapNode&	getLeft(int i)	{ return node[i*2]; }
	HeapNode&	getRight(int i)	{ return node[i*2+1];}

	// 삽입 함수
	void insert( int key ) {
		if( isFull() ) return;

		int i = ++size;			

		while( i!=1							
			&& key<getParent(i).getKey()) {		// MaxHeap 대비 부등호 방향 반대
			node[i] = getParent(i);			
			i /= 2;							
		}
		node[i].setKey( key );				
	}

	// 삭제 함수
	HeapNode remove() { 
		if( isEmpty() ) return NULL;

		HeapNode root = node[1];		
		HeapNode last = node[size--];	

		int parent	= 1;				
		int	child	= 2;				

		while( child <= size ){			
		  if( child < size
		   && getLeft(parent).getKey() > getRight(parent).getKey())	// MaxHeap 대비 부등호 방향 반대
			  child++;

		  if( last.getKey() <= node[child].getKey() ) break;	// MaxHeap 대비 부등호 방향 반대

		  node[parent] = node[child];
		  parent = child;
		  child *= 2;
		}
		node[parent] = last;
		return root;
	} 
};
