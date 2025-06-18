/*
* ErrorStateChange.cpp
*/
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(void)
{
	HANDLE hFile =
		CreateFile(
			_T("ABC.DAT"), GENERIC_READ, FILE_SHARE_READ,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
			NULL);
	
	_tprintf(_T("error code: %d\n"), GetLastError()); // 오류 확인

	hFile =
		CreateFile(
			_T("ABC2.DAT"), GENERIC_WRITE, FILE_SHARE_READ,
			NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL,
			NULL);

	_tprintf(_T("error code: %d\n"), GetLastError()); // 오류 확인

	return 0;
}

// 오류 확인은 오류가 발생한 직후에 바로 한다.
// Windows 시스템 함수가 호출될 때마다 GetLastError 함수가 반환하는 에러코드는 갱신된다.
