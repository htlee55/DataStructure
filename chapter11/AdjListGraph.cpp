#include "AdjListGraph.h"

void main()
{
	AdjListGraph g;		// 새로운 그래프 객체 생성

	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i);		// 정점 삽입: 'A', 'B', ...

	g.insertEdge(0, 1);		// 간선 삽입
	g.insertEdge(0, 3);		// 간선 삽입
	g.insertEdge(1, 2);		// 간선 삽입
	g.insertEdge(1, 3);		// 간선 삽입
	g.insertEdge(2, 3);		// 간선 삽입
	printf("인접 행렬로 표현한 그래프\n");
	g.display();			// 그래프 출력 => 화면(stdout)으로 출력

}
