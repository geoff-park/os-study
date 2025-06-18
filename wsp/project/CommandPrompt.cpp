/*
* CommandPrompt.cpp
* 프로그램 설명: 명령 프롬프트의 골격
*/
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>
#include <windows.h>

#define STR_LEN 256
#define CMD_TOKEN_NUM 10

TCHAR ERROR_CMD[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다. \n");

int CmdProcessing(void);
TCHAR* StrLower(TCHAR*);

int main(int argc, TCHAR* argv[])
{
	// 한글 입력을 가능케 하기 위해
	_tsetlocale(LC_ALL, _T("Korean"));

	DWORD isExit;
	while (1)
	{
		isExit = CmdProcessing();
		if (isExit == TRUE)
		{
			_fputts(_T("명령어 처리를 종료합니다. \n"), stdout);
			break;
		}
	}

	return 0;
}

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

/* **************************************************
함수: int CmdProcessing(void)
기능: 명령어를 입력받아서 해당 명령어에 지정되어 있는 기능을 수행한다.
		exit가 입력되면 TRUE를 반환하고 이는 프로그램의 종료로 이어진다.
************************************************** */
int CmdProcessing(void)
{
	_fputts(_T("Best command prompt>> "), stdout);
	_fgetts(cmdString, STR_LEN, stdin);

	TCHAR* token = _tcstok(cmdString, seps);	// 문자열 cmdString에서 seps(구분자) 기준으로 첫 번째 토큰을 추출
	int tokenNum = 0;							// 토큰을 저장할 배열의 인덱스를 위한 변수 초기화

	// 더 이상 토큰이 없을 때까지 반복
	while (token != NULL)
	{
		_tcscpy(cmdTokenList[tokenNum++], StrLower(token));
		// 현재 토큰을 소문자로 변환한 후, cmdTokenList 배열에 복사하고 인덱스를 증가시킴

		token = _tcstok(NULL, seps); // 다음 토큰을 얻기 위해 NULL을 넘겨 계속 분리 진행
	}

	if (!_tcscmp(cmdTokenList[0], _T("exit"))) // 동일하면
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("추가 되는 명령어 1")))
	{

	}
	else if (!_tcscmp(cmdTokenList[0], _T("추가 되는 명령어 2")))
	{

	}
	else
	{
		_tprintf(ERROR_CMD, cmdTokenList[0]);
	}

	return 0;
}

/* **************************************************
함수: TCHAR* StrLower(TCHAR* pStr)
기능: 문자열 내에 존재하는 모든 대문자를 소문자로 변경한다.
		변경된 문자열의 포인터를 반환한다.
************************************************** */
TCHAR* StrLower(TCHAR* pStr)
{
	TCHAR* ret = pStr; // 나중에 원래 시작 위치를 반환하기 위해 입력 포인터를 백업

	while (*pStr) // 문자열 끝(NULL 문자)까지 반복
	{
		if (_istupper(*pStr)) // 현재 문자가 대문자인지 확인
			*pStr = _totlower(*pStr); // 대문자인 경우, 소문자로 변환하여 저장
		pStr++; // 다음 문자로 이동
	}

	return ret; // 원래 문자열의 시작 포인터를 반환
}
