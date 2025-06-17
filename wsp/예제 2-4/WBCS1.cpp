/*
* WBCS1.cpp
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	wchar_t str[] = L"ABC"; // 유니코드 기반으로 문자열 선언
	int size = sizeof(str);
	int len = wcslen(str); // WBCS 기반의 문자열 조작 함수

	printf("배열의 크기: %d \n", size);
	printf("문자열 길이: %d \n", len);

	return 0;
}
