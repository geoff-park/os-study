/*
	OperationStateParent.cpp
	프로그램 설명: 프로그램 실행 결과에 따른 반환값 확인
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	DWORD state;

	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;
	si.lpTitle = (wchar_t*) _T("return & exit");

	TCHAR command[] = _T("OperationStateChild.exe");

	CreateProcess(NULL, command,
		NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE,
		NULL, NULL,
		&si, &pi
		); // CreateProcess

	for (DWORD i = 0; i < 10000; ++i) // Child Process의 우선종료 위해
		for (DWORD i = 0; i < 10000; ++i);

	//WaitForSingleObject(pi.hProcess, INFINITE); // 자식 프로세스(인자로 전달된 핸들이 가리키는 프로세스)가 종료될때까지 기다리는 기능의 함수

	GetExitCodeProcess(pi.hProcess, &state); // 첫 번째 인자로 전달된 핸들이 가리키는 프로세스가 반환하는 종료코드를 얻기 위해 사용되는 함수 (실행 중이라면 STILL_ACTIVE 반환)
	if (state == STILL_ACTIVE)
		_tprintf(_T("STILL_ACTIVE \n\n"));
	else
		_tprintf(_T("state : %d \n\n"), state);
	// CloseHandle(pi.hProcess);
	return 0;
}
