/*
* GetLastError.cpp
*/
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(void)
{
	HANDLE hFile =
		CreateFile( // Windows system 함수: 파일을 개방하는 함수 -> 존재하지 않는 파일을 열도록 설정 -> error code = 2 [ERROR_FILE_NOT_FOUND]
			_T("ABC.DAT"), GENERIC_READ, FILE_SHARE_READ,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
			NULL);
	
	// CreateFile 함수는 함수 호출이 실패할 경우 INVALID_HANDLE_VALUE를 반환한다.
	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("error code: %d \n"), GetLastError());
		return 0;
	}

	return 0;
}
