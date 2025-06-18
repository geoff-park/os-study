/*
* WBCS2.cpp
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	int len = wcslen(str);

	// wprintf 함수: printf 함수의 유니코드 버전
	wprintf(L"Array Size : %d \n", size);	// 문자열도 유니코드 방식으로 선언
	wprintf(L"String Length : %d \n", len); // 문자열도 유니코드 방식으로 선언

	return 0;
}
