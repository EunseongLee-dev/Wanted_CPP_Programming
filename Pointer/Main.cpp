#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

//방법1
void DeletePointer(void** ptr)
{
	if (*ptr != nullptr)
	{
		delete *ptr;
		*ptr = nullptr;
	}
}
//방법2
void DeletePointer(void*& ptr)
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	

	// todo: 메모리 릭.
	int* intpointer = new int;
	delete intpointer;

	// 동적 할당
	char* buffer = new char[10];


	// 포인터는 주소를 저장하는 변수.
	/*void* pointer = nullptr;*/
	void* pointer = new int;
	DeletePointer(pointer);
	/*delete pointer;
	pointer = nullptr;*/

	if (pointer != nullptr)
	{
		std::cout << "pointer is not null\n";
	}
	else
	{
		std::cout << "pointer is null\n";
	}

	// 자동종료 방지
	std::cin.get();
}