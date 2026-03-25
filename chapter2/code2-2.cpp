// 배열에서 최댓값을 찾아 반환하는 함수
int findMaxValue(int a[], int len)
{
	int maxVal = a[0];
	for (int i = 1; i < len; i++)
		if (maxVal < a[i])
			maxVal = a[i];
	return maxVal;
}
#include <cstdio>
void main()
{
	int arr[10] = { 3, 24, 82, 12, 34, 7, 53, 17, 26, 51 };
	int maxVal = findMaxValue(arr, 10);
	printf("배열의 최댓값 = %d\n", maxVal);
}
