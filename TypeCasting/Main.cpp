#include <iostream>

void PrintString(char* string)
{
	std::cout << string << "\n";
}

class A 
{
public:
	virtual void Test(){}
};
class B : public A
{
};

int main()
{
	// const_cast
	// 잘 안쓰임
	const char* name = "ronnie";
	PrintString(const_cast<char*>(name));

	// stati_cast
	int number = 10;
	float floatNumber = static_cast<float>(number);
	// 잘 알아보고 사용
	A* a = new A();
	B* b = static_cast<B*>(a);
	if (b)
	{
		std::cout << "b is not null\n";
	}

	// reinterpret_cast
	// 상속이 안되어 있어도 가능
	// 위험
	B* b2 = reinterpret_cast<B*>(a);
	if (b2)
	{
		std::cout << "b2 is not null\n";
	}
	// dynamic_cast
	// 적어도 1개 이상의 virtual 함수가 한개는 존재해야함
	B* b3 = dynamic_cast<B*>(a);
	if (b3)
	{
		std::cout << "b3 is not null\n";
	}

	// typeid
	const type_info& aInfo = typeid(a);
	const type_info& binfo = typeid(b);

	// 주소값 비교
	if (a == b)
	{
		std::cout << "same\n";
	}
	

	delete a;
	std::cin.get();
}