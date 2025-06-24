/*
	Operation1.cpp
	프로그램 설명: 단순 출력 프로그램1
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);
	TCHAR command[] = _T("Operation2.exe");

	CreateProcess(
		NULL, command, NULL, NULL,
		TRUE, 0, NULL, NULL, &si, &pi
	);
	// CreateProcess 함수 호출 -> Operation2.exe 이름의 실행파일 실행

	while (1)
	{
		for (DWORD i = 0; i < 10000; ++i)
		{
			for (DWORD i = 0; i < 10000; ++i); // Busy Waiting!
		}

		// cf. 중첩 for 문이 아닌 Sleep 함수를 사용하면 => 프로세스는 Blocked 상태가 된다.

		_fputts(_T("Operation1.exe \n"), stdout);
	}

	return 0;

	// 결국 이 예제는 Operation2.exe를 실행시키고 나서, "Operation1.exe" 문자열을 계속 출력하게 된다.
}
