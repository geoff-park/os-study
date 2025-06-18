/*
* WinString.cpp
*/
#include <stdio.h>
#include <windows.h>

int wmain(int argc, wchar_t* argv[])
{
	// LPSTR = char*
	LPSTR str1 = "SBCS Style String 1"; // MBCS 기반 문자열 선언
	// LPWSTR = wchar_t*
	LPWSTR str2 = L"WBCS Style String 1"; // 유니코드 기반 문자열 선언

	CHAR arr1[] = "SBCS Style String 2";
	WCHAR arr2[] = L"WBCS Style String 2";

	LPCSTR cStr1 = arr1; // LPCSTR = const char*
	LPCWSTR cStr2 = arr2; // LPCWSTR = const wchar_t*

	printf("%s\n", str1);
	printf("%s\n", arr1);

	wprintf(L"%s\n", str2);
	wprintf(L"%s\n", arr2);

	return 0;
}
