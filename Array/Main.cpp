#include <iostream>

// 배열을 함수에 전달
void PrintArray(int* array, int length)
{

	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix] << "\n";
	}
}

int main()
{
	// 배열 선언
	//int array[10] = {};
	int array[10];
	memset(array, 0, sizeof(int) * 10);

	array[0] = 1;
	array[3] = 10;
	array[9] = 100;
	
	// Out-Of-Index(Range)
	// array[10] = 1000; = 컴파일러가 막아줌.

	// 배열의 이름은 주소(포인터) = 배열의 첫 번째 요소의 주소
	int* arraypointer = array;

	// 동일한 의미 = 배열은 포인터
	arraypointer[1] = 20;
	*(arraypointer + 1) = 20;
	
	// 배열원소 순회
	// range-based loop
	/*for (const int& item : array)
	{
		std::cout << item << "\n";
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << array[i] << "\n";
	}*/

	PrintArray(array, 10);



	// 배열 동적 할당
	int* dynamicArray = new int[10];
	/*memset(dynamicArray, 1, sizeof(int) * 10);*/
	for (int x = 0; x < 10; ++x)
	{
		dynamicArray[x] = x + 1;
	}

	// 해제
	delete[] dynamicArray;

	std::cin.get();
}