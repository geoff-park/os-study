/*
* MBCS2.cpp
*/
#include <stdio.h>

int main(void)
{
	char str[] = "한글입니다";
	int i;

	for (i = 0; i < 5; ++i)
	{
		fputc(str[i], stdout);
	}
	fputs("\n", stdout);

	for (i = 0; i < 10; ++i)
	{
		fputc(str[i], stdout);
	}
	fputs("\n", stdout);

	return 0;
}

/*
* 해설
* 
* 문자열의 길이는 5이지만, MBCS 방식은 한글 한 글자를 2바이트로 표현하므로 총 10바이트이다.
* 따라서 fputc 함수를 10번 호출해야 한다.
*/
