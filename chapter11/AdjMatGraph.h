// AdjMatGraph.h : 인접 행렬을 이용한 그래프 클래스
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
//#include <string.h>
#define MAX_VTXS	256					// 표현 가능한 최대 정점의 개수

class AdjMatGraph
{
protected:
	int		size;						// 정점의 개수
	char	vertices[MAX_VTXS];			// 정점의 이름
	int		adj[MAX_VTXS][MAX_VTXS];	// 인접 행렬

public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int	 getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }

	// 그래프 초기화 => 공백 상태의 그래프
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}

	// 정점 삽입 연산
	void insertVertex(char name) {
		if (!isFull()) vertices[size++] = name;
		else printf("Error: 그래프 정점의 개수 초과\n");
	}

	// 간선 삽입 연산: 무방향 그래프의 경우임. (방향, 가중치 그래프에서는 수정)
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);		// 방향 그래프에서는 삭제됨(<u,v>만 존재)
	}

	// 그래프 정보를 출력함 (화면이나 파일에 출력)
	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);						// 정점의 개수 출력
		for (int i = 0; i < size; i++) {					// 각 행의 정보 출력
			fprintf(fp, "%c  ", getVertex(i));			// 정점의 이름 출력
			for (int j = 0; j < size; j++)				// 간선 정보 출력
				fprintf(fp, " %3d", getEdge(i, j));
			fprintf(fp, "\n");
		}
	}

	// 파일 입력 함수
	void load(const char* filename) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n;
			fscanf(fp, "%d", &n);				// 정점의 전체 개수, n, 읽어오기, 한 줄에 하나씩 저장되어 있다고 가정
			for (int i = 0; i < n; i++) {
				char	str[80];
				fscanf(fp, "%s", str);			// 정점의 이름, str[0]에 저장, 한 줄에 하나씩 저장되어 있다고 가정
				insertVertex(str[0]);			// 정점 삽입, 정점의 이름이 str[0]에 저장되어 있다고 가정
				for (int j = 0; j < n; j++) {	// 간선 정보 읽어오기, 한 줄에 하나씩 저장되어 있다고 가정
					int		val;
					fscanf(fp, "%d", &val);		// 간선 정보, val, 읽어오기
					if (val != 0)				// 간선이 있으면
						insertEdge(i, j);		// 간선 삽입
				}
			}
			fclose(fp);
		}
	}
	// 파일 저장 함수
	void store(const char* filename) {
		FILE* fp = fopen(filename, "w");
		if (fp != NULL) {
			display(fp);				// 그래프 정보를 파일에 출력
			fclose(fp);					// 파일 닫기
		}
	}

};





