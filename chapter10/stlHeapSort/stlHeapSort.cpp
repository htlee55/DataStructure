#include <queue>
#include <functional>
using namespace std;

// STL의 우선순위 큐를 이용한 내림차순 정렬, 최대힙 사용
void heapSortDec(int a[], int n) {
	priority_queue<int> maxHeap;
	for (int i = 0; i < n; i++)
		maxHeap.push(a[i]);
	// MaxHeap을 이용해 내림차순으로 정렬하기 위한 반복문
	for (int i = 0; i < n; i++)
	{
		a[i] = maxHeap.top();
		maxHeap.pop();
	}
}

// STL의 우선순위 큐를 이용한 오름차순 정렬. 최소힙 사용
void heapSortInc(int a[], int n) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < n; i++)
		minHeap.push(a[i]);
	// minHeap을 이용해 오름차순으로 정렬하기 위한 반복문
	for (int i = 0; i < n; i++)
	{
		a[i] = minHeap.top();
		minHeap.pop();
	}
}

#include <cstdlib>
// 주함수 
void main()
{
	int data[10];

	// 랜덤으로 데이터 생성
	for (int i = 0; i < 10; i++)
		data[i] = rand() % 100;
	// 정렬전 결과 출력
	printf("\n정렬전: ");
	for (int i = 0; i < 10; i++)
		printf("%3d", data[i]);

	// STL의 우선순위 큐를 이용한 내림차순 정렬
	heapSortDec(data, 10);

	// 내림차순 정렬 후 결과 출력
	printf("\n내림차순 정렬후: ");
	for (int i = 0; i < 10; i++)
		printf("%3d", data[i]);
	printf("\n");

	// STL의 우선순위 큐를 이용한 오름차순 정렬
	heapSortInc(data, 10);

	// 오름차순 정렬 후 결과 출력
	printf("\n오름차순 정렬후: ");
	for (int i = 0; i < 10; i++)
		printf("%3d", data[i]);
	printf("\n");
}
