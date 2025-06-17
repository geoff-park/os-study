#include <stdio.h>
#include <string.h>

int main(void)
{
	wchar_t str[] = L"ABC";
	int size = sizeof(str);
	int len = strlen(str); // compile error: strlen 함수는 SBCS 기반 문자열을 처리하기 위한 함수이다.

	printf("배열의 크기: %d \n", size);
	printf("문자열 길이: %d \n", len);

	return 0;
}
