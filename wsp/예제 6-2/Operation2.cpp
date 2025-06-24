/*
	Operation2.cpp
	프로그램 설명: 단순 출력 프로그램2
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	// GetCurrentProcess 함수: 현재 실행되고 있는 프로세스(GetCurrentProcess 함수를 호출한 프로세스)의 "핸들"을 얻을 때 사용되는 함수 (반환값: HANDLE)
	// SetPriorityClass 함수: 첫 번째 인자로 전달된 핸들이 가리키는 프로세스의 우선순위를 두 번째 인자로 전달된 우선순위 값으로 변경

	while (1)
	{
		for (DWORD i = 0; i < 10000; ++i)
		{
			for (DWORD i = 0; i < 10000; ++i); // Busy Waiting!
		}

		_fputts(_T("Operation2.exe \n"), stdout);
	}

	return 0;
}
