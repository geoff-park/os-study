/*
	KerObjShare.cpp
	프로그램 설명: 커널 오브젝트 공유 예제

	** 커널 오브젝트는 Windows 운영체제에 종속적이다!
		1) 커널 오브젝트는 프로세스에 종속적인 것이 아니라, 운영체제에 종속적인 관계 -> 커널 오브젝트의 소멸시점은 운영체제에 의해서 결정된다.
		2) 커널 오브젝트는 프로세스에 종속적인 것이 아니라, 운영체제에 종속적인 관계 -> 커널 오브젝트는 여러 프로세스에 의해서 접근 가능하다. (함수 호출을 통한 간접 접근)
		cf) 핸들(핸들 테이블)은 운영체제에 종속적이지 않고 프로세스에 종속적

	* 이 예제는 "커널 오브젝트는 여러 프로세스에 의해 접근 가능함"을 보이는 예제다.
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;

	// ** 구조체 PROCESS_INFORMATION의 정의

	//typedef struct _PROCESS_INFORMATION
	//{
	//	HANDLE hProcess; // 프로세스의 핸들
	//	HANDLE hThread; // 쓰레드 핸들
	//	DWORD dwProcessId; // 프로세스의 ID
	//	DWORD dwThreadId; // 쓰레드 ID
	//} PROCESS_INFORMATION;

	si.cb = sizeof(si);

	TCHAR command[] = _T("Operation2.exe");

	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		0, NULL, NULL, &si, &pi
	);

	DWORD timing = 0;

	while (1)
	{
		for (DWORD i = 0; i < 10000; ++i)
			for (DWORD i = 0; i < 10000; ++i); // Busy Waiting!

		_fputts(_T("Parent \n"), stdout);

		timing += 1;
		if (timing == 2)
			SetPriorityClass(pi.hProcess, NORMAL_PRIORITY_CLASS); // pi.hProcess : 프로세스 핸들 // cf. Operation2.cpp 에서는 GetCurrentProcess 함수를 사용해 핸들 정보를 얻었다.

		// 해설
		// Operation2.cpp 는 실행과 동시에 자신의 우선순위를 높이도록 구현되어 있다.
		// => KerObjShare.cpp 에서 SetPriorityClass 함수 호출을 통해 Operation2.exe 의 우선순위를 NORMAL_PRIORITY_CLASS 로 변경하고 있다.
		
		// 다시 말해, 두 개의 프로세스가 하나의 커널 오브젝트에 순서대로 접근(공유)하였다.
		// 한번은 우선순위를 높이기 위해, 한번은 우선순위를 되돌리기 위해
		// ** 커널 오브젝트 공유
	}

	return 0;
}

// 결론: 커널 오브젝트는 프로세스에 종속적인 것이 아니라 운영체제에 종속적인 관계 -> 여러 프로세스에 의해서 접근이(공유가) 가능하다!
