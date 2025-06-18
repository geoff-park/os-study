/*
* WBCS3.cpp
*/
#include <stdio.h>

int main(int argc, char* argv[]) // char*: SBCS 기반으로 문자열을 전달받겠다!
{
	int i;
	for (i = 0; i < argc; ++i)
		fputws(argv[i], stdout); // 유니코드 기반 문자열 처리 함수

	return 0;
}

/*
* 해설
* 
* char* argv[] 이 부분을 wchar_t* argv[] 이렇게 바꾼다고 문제가 해결되지는 않는다.
* 왜냐하면 main이라는 이름의 함수는 프로그램 실행 시, 전달되는 문자열을 MBCS 기반으로 구성하기 때문이다.
* 
* 예: c:\> test.exe AAA BBB
* 
*	(1) main의 경우: "test.exe" "AAA" "BBB" (MBCS 기반으로 구성)
*	(2) wmain의 경우: L"test.exe" L"AAA" L"BBB" (유니코드 기반으로 구성)
*/
