/*
* PolymorphicType1.cpp
*/
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

// 이 함수는 순전히 WIN32만을 기반으로 한다.
UINT CalDistance(UINT a, UINT b)
{
	return a - b;
}

int _tmain(void)
{
	INT val1 = 10;
	INT val2 = 20;

	_tprintf(_T("Position %d, %d \n"), (UINT)&val1, (UINT)&val2);
	_tprintf(
		_T("distance : %d \n"),
			CalDistance((UINT)&val1, (UINT)&val2)
	);

	return 0;
}
