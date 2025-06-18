/*
* MBCS_WBCS1.cpp
*/

// UNICODE, _UNICODE 정의는 헤더파일 선언 이전에 등장해야 한다.
#define UNICODE
#define _UNICODE

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int wmain(void)
{
	TCHAR str[] = _T("1234567"); // TCHAR -> wchar_t, _T("1234567") -> L"1234567"
	int size = sizeof(str);
	printf("string length : %d\n", size);
	return 0;
}
