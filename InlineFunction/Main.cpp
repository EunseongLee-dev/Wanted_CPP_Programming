#include <iostream>

// 최적화 = 용량 / 속도
// 인라인 함수 -> 속도 때문.
// 매크로 = #define
// #define Square(x) ((x) * (x))

#define FORCEINLINE __forceinline

FORCEINLINE int Square(int x)
{
	return x * x;
}


int main()
{ 
	int number = Square(10);
}