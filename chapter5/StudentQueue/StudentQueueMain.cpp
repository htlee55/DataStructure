// 05장-StudentQueueMain.cpp
#include "StudentQueue.h"
void main()
{
	StudentQueue que;
	que.enqueue( new Node(2015130007, "홍길동", "컴퓨터공학과") );
	que.enqueue( new Node(2015130100, "이순신", "기계공학과") );
	que.enqueue( new Node(2015130135, "황희", "법학과") );
	que.display();
	delete que.dequeue();
	que.display();
}
