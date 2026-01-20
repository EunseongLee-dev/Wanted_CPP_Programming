#include <iostream>

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