// 11장-AdjMatGraph.cpp : 그래프 클래스 테스트 프로그램
#include "AdjMatGraph.h"			// 그래프 클래스 포함

void main()
{
	AdjMatGraph g;		// 새로운 그래프 객체 생성

	for (int i = 0; i < 4; i++)
		g.insertVertex('A' + i);		// 정점 삽입: 'A', 'B', ...

	g.insertEdge(0, 1);		// 간선 삽입
	g.insertEdge(0, 3);		// 간선 삽입
	g.insertEdge(1, 2);		// 간선 삽입
	g.insertEdge(1, 3);		// 간선 삽입
	g.insertEdge(2, 3);		// 간선 삽입
	printf("인접 행렬로 표현한 그래프\n");
	g.display();			// 그래프 출력 => 화면(stdout)으로 출력

	g.store("graph.txt");		// 그래프 g를 파일에 저장

	g.reset();					// 그래프 g를 초기화
	g.load("graph.txt");		// 파일에서 그래프 정보를 읽어 g 설정
	printf("인접 행렬로 표현한 그래프 (파일:graph.txt)\n");
	g.display();		// 그래프 출력


	/*
		AdjMatGraph g1;
		g1.Load( "graph.txt" );
		printf("인접 행렬로 표현한 그래프 (파일:graph.txt)\n");
		g1.display();
	*/
}
