/*
	CloseHandlePorb1.cpp
	프로그램 설명: CloseHandle 함수 이해 1
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);

	TCHAR command[] = _T("KernerlObjProb2.exe");
	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		0, NULL, NULL, &si, &pi
	); // A 프로세스는 실행과정에서 B 프로세스를 생성

	// 그리고 나서 B 프로세스의 핸들을 이용해서 CloseHandle 함수를 호출한다.
	// CloseHandle 함수의 정확한 해석: "핸들을 반환한다!"
	CloseHandle(pi.hProcess);

	// 실행 결과를 보면, 프로세스 A는 종료되지만 프로세스 B는 종료되지 않는다.
	// 즉, CloseHandle 함수는 단순히 핸들을 반환하는 역할만을 할 뿐, 프로세스를 종료시키지는 않는다.

	return 0;
}
