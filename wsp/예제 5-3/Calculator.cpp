#define _CRT_SECURE_NO_WARNINGS

/*
	Calculator.cpp
	프로그램 설명
		1. 사칙연산 프로그램
		2. 개선되어야 할 예제
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

enum{DIV=1, MUL, ADD, MIN, ELSE, EXIT};

DWORD ShowMenu();
void Divide(double, double);
void Multiple(double, double);
void Add(double, double);
void Min(double, double);

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si); // 구조체 변수의 크기

	TCHAR command[] = _T("calc.exe"); // 실행파일 이름 (배열)
	SetCurrentDirectory(_T("C:\\WINDOWS\\system32")); // calc.exe가 존재하는 디렉터리로 현재 디렉터리 위치를 변경

	DWORD sel;
	double num1, num2;

	while (1)
	{
		sel = ShowMenu();

		if (sel == EXIT) return 0;

		if (sel != ELSE)
		{
			_fputts(_T("Input Num1 Num2: "), stdout);
			_tscanf(_T("%lf %lf"), &num1, &num2);
		}

		switch (sel)
		{
		case DIV:
			Divide(num1, num2);
			break;
		case MUL:
			Multiple(num1, num2);
			break;
		case ADD:
			Add(num1, num2);
			break;
		case MIN:
			Min(num1, num2);
			break;
		case ELSE:
			ZeroMemory(&pi, sizeof(pi)); // 구조체 변수 pi를 0으로 초기화

			/* ZeroMemory 함수 */
			/*
			VOID ZeroMemory(
				PVOID Destination, // 초기화할 메모리 블록의 포인터
				SIZE_T Length // 초기화할 메모리 블록의 크기
			*/

			CreateProcess(
				NULL, command, NULL, NULL,
				TRUE, 0, NULL, NULL, &si, &pi
			);
			break;
		}
	}

	return 0;
}

DWORD ShowMenu()
{
	DWORD sel;

	_fputts(_T("-----Menu----- \n"), stdout);
	_fputts(_T("num 1: Divide \n"), stdout);
	_fputts(_T("num 2: Multiple \n"), stdout);
	_fputts(_T("num 3: Add \n"), stdout);
	_fputts(_T("num 4: Minus \n"), stdout);
	_fputts(_T("num 5: Any other operations. \n"), stdout);
	_fputts(_T("num 6: Exit \n"), stdout);
	_fputts(_T("SELECTION >>"), stdout);

	_tscanf(_T("%d"), &sel);

	return sel;
}

void Divide(double a, double b)
{
	_tprintf(_T("%f/%f=%f \n\n"), a, b, a / b);
}

void Multiple(double a, double b)
{
	_tprintf(_T("%f*%f=%f \n\n"), a, b, a * b);
}

void Add(double a, double b)
{
	_tprintf(_T("%f+%f=%f \n\n"), a, b, a + b);
}

void Min(double a, double b)
{
	_tprintf(_T("%f-%f=%f \n\n"), a, b, a - b);
}
