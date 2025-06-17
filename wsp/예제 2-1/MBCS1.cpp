/*
* MBCS1.cpp
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "ABC한글";
	int size = sizeof(str);
	int len = strlen(str);

	printf("배열의 크기: %d \n", size);
	printf("문자열 길이: %d \n", len);

	return 0;
}

/*
* 해설
* 
* ABC(3바이트) + 한글(4바이트) + NULL 문자(1바이트) = 8바이트
* MBSC 기반임을 확인할 수 있다.
*/
