/*
* PolymorphicType2.cpp
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

// UINT_PTR: Polymorphic 자료형 -> 64비트 환경에서는 64비트로, 32비트 환경에서는 32비트로 선언
UINT_PTR CalDistance(UINT_PTR a, UINT_PTR b)
{
	return a - b;
}

int _tmain(void)
{
	INT32 val1 = 10;
	INT32 val2 = 20;

	_tprintf(
		_T("distance : %d \n"),
		CalDistance((UINT_PTR)&val1, (UINT_PTR)&val2)
	);

	return 0;
}
