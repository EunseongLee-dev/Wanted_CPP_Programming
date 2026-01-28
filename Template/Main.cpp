#include <iostream>

//  두변수의 값을 서로 교환하는 함수
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//void Swap(float& a, float& b)
//{
//	float temp = a;
//	a = b;
//	b = temp;
//}

int main()
{
	int a = 10;
	int b = 20;
	Swap<int>(a, b);

	float floatA = 10.0f;
	float floatB = 20.0f;
	Swap<float>(floatA, floatB);



	std::cin.get();
}