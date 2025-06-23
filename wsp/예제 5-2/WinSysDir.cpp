/*
	WinSysDir.cpp
	프로그램 설명: System Directory와 Windows Directory 확인
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LEN MAX_PATH+1

int _tmain(int argc, TCHAR** argv)
{
	TCHAR sysDir[DIR_LEN];
	TCHAR winDir[DIR_LEN];

	// System Directory
	GetSystemDirectory(sysDir, DIR_LEN);

	// Windows Directory
	GetWindowsDirectory(winDir, DIR_LEN);

	_tprintf(_T("System Dir: %s \n"), sysDir); // C:\Windows\system32
	_tprintf(_T("Windows Dir: %s \n"), winDir); // C:\Windows

	return 0;
}
