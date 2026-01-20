#include <iostream>
#include "Log.h"

//void Log(const char* message)
//{
//	std::cout << message << '\n';
//}

// F12 or Ctrl + -
// Ctrl + 방향키 좌우.
// Home + End + Shift. = 한줄 복사
// Art + shift + 방향키 아래 = 여러줄작성


int main()
{
	Log("Hello, World!");
	
	// 프로그램 바로 종료되지 않게, 의미없음.
	std::cin.get();
}	