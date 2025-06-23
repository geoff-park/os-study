/*
	CreateProcess.cpp
	프로그램 설명: 덧셈 프로세스를 생성
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LEN MAX_PATH+1 // MAX_PATH: Windows에서 허용하는 완전경로의 최대 길이

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	// STARTUPINFO 구조체 변수를 선언과 동시에 0으로 초기화
	// 이 변수는 CreateProcess 함수의 9번째 인자로 들어오는 요소
	// -> ** 생성하는 프로세스의 속성을 지정하는 용도로 사용된다.

	PROCESS_INFORMATION pi; // 새로 생성되는 프로세스 관련 정보를 얻기 위해 사용

	// Line 22-28: 생성하고자 하는 프로세스의 속성을 지정
	si.cb = sizeof(si); // 구조체 변수의 크기
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; // 설정된 멤버의 정보
	// STARTF_USEPOSITION: dwX, dwY 값 참조 -> 생성하는 프로세스 윈도우 위치를 결정할 때 사용
	// STARTF_USESIZE: dwXSize, dwYSize 값 참조 -> 생성하는 프로세스 윈도우 크기를 결정할 때 사용

	si.dwX = 100; // 프로세스 윈도우의 x 좌표
	si.dwY = 200; // 프로세스 윈도우의 y 좌표
	si.dwXSize = 300; // 프로세스 윈도우의 가로 길이
	si.dwYSize = 200; // 프로세스 윈도우의 세로 길이
	si.lpTitle = (wchar_t*)_T("I am a boy!"); // 형 변환: const wchar_t* -> wchar_t* // 콘솔 윈도우의 타이틀 바 제목

	/* 프로세스 생성 2단계: 현재 디렉터리의 설정 */
	/*
		일반적으로 프로세스가 생성되면 프로세스의 현재 디렉터리(Current Directory)는 프로세스의 실행파일이 존재하는 디렉터리로 설정된다.
	*/

	TCHAR command[] = _T("AdderProcess.exe 10 20");
	TCHAR cDir[DIR_LEN];
	BOOL state;

	// ** GetCurrentDirectory **
	// DWORD GetCurrentDirectory (
	//		DWORD nBufferLength, // 현재 디렉터리 정보가 저장될 메모리 버퍼의 크기 (문자열 길이 정보)
	//		LPSTR lpBuffer // 현재 디렉터리 정보가 저장될 메모리 버퍼의 포인터
	// );

	GetCurrentDirectory(DIR_LEN, cDir); // 현재 디렉터리 확인
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	SetCurrentDirectory(_T("C:\\WinSystem"));
	// 현재 디렉터리를 C 드라이브 아래에 있는 WinSystem이라는 디렉터리로 변경

	GetCurrentDirectory(DIR_LEN, cDir); // 현재 디렉터리 확인
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);


	/* 프로세스 생성 3단계: Create Process 함수의 호출 */


	state = CreateProcess( // 프로세스 생성
		NULL, // 실행파일의 이름
		command, // main 함수에 전달될 문자열 // 전달인자의 문자열은 변수 형태여야 한다.
		NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE, // 새롭게 생성하는 프로세스를 위한 콘솔 윈도우가 독립적으로 생성된다.
		NULL, NULL, &si, &pi
	); // CreateProcess

	// CreateProcess 함수에 실행파일 이름을 전달하는 방법은 2가지가 있다.
	//		1) 함수의 첫 번째 전달인자 -> 현재 디렉터리를 기준으로 실행파일을 찾는다.
	//		2) 함수의 두 번째 전달인자 -> 표준 검색경로 순서대로 실행파일을 찾게 된다.
	//			* 실행 중인 프로세스의 실행파일이 존재하는 디렉터리
	//			=> * 실행 중인 프로세스의 현재 디렉터리 (Current Directory)
	//			=> * Windows의 시스템 디렉터리 (System Directory)
	//			=> * Windows의 디렉터리 (Windows Directory)
	//			=> * 환경변수 PATH에 의해 지정되어 있는 디렉터리

	if (state != 0)
	{
		_fputts(_T("Creation OK!\n"), stdout);
	}
	else
	{
		_fputts(_T("Creation Error!\n"), stdout);
	}

	return 0;
}
