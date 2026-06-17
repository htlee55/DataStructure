// 11장-SrchAMGraph.cpp : 깊이 우선 탐색 테스트 프로그램
#include "SrchAMGraph.h"

void main()
{
	SrchAMGraph g;				// DFS 탐색기능이 있는 그래프 객체 행성
	g.load("graph.txt");		// 파일 "graph.txt"로부터 g를 설정함
	printf("인접 행렬로 표현한 그래프\n");
	g.display();				// 그래프를 화면에 출력

	printf("DFS ==> ");
	g.resetVisited();			// 모든 정점을 방문하지 않았다고 하고
	g.DFS(0);					// 0번째 정점(A)에서 깊이 우선 탐색 시작
	printf("\n");

	/*
	printf("BFS ==> ");
	g.resetVisited();
	g.BFS( 0 );
	printf("\n");
	*/
}
