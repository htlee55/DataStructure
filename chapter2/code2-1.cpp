#include <cstdio>		// C 헤더파일 <stdio.h>를 포함하는 것과 동일
#define MAX_SIZE 10
// 배열을 파라미터로 받는 함수
void sub(int x, int arr[])
{
	x = 10;
	arr[0] = 10;
}
// 주 함수
void main()
{
	int var;				// 정수 변수의 선언
	int list[MAX_SIZE];		// 정수 배열의 선언

	var = 0;				// 변수 var에 0 대입
	list[0] = 0;			// list 첫 번째 요소에 0 대입
	sub(var, list);			// 변수와 배열을 매개변수로 전달
	printf("var=%d, list[0]=%d\n", var, list[0]);
}
