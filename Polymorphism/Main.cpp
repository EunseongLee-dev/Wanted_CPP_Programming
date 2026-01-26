#include <iostream>

// 매크로 안에서 어떤 항목 앞에 #을 붙이면
// 무지성(무조건)으로 문자열로 변환함
#define NAME(x) #x

#define PURE = 0

// 순수 가상 함수를 가지는 클래스
// 인터페이스
// 순수 가상 함수만 가져야 함
class NameInterface
{
public:
	// 순수 가상 함수(Pure)
	/*virtual const char* GetName() const = 0;*/
	virtual const char* GetName() const PURE;
};

// 다형성
class Entity : public NameInterface
{
public:
	/*const char* GetName() const { return "Entity"; }*/
	virtual const char* GetName() const override
	{
		return NAME(Entity); 
	}
};

class Player : public NameInterface
{
public:
	Player(const char* name)
	{
		// 내부의 name 설정
		// 크기
		size_t length = strlen(name) + 1;
		
		// 할당
		this->name = new char[length];

		// 문자열 복사
		strcpy_s(this->name, length, name);
	}

	~Player()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	virtual const char* GetName() const override { return name; }

private:
	char* name = nullptr;
};

int main()
{
	Entity* entities[250] = {};

	Entity* entity = new Entity();
	std::cout << entity->GetName() << "\n";
	
	entities[0] = entity;

	Player* player = new Player("asb");
	//Entity* player = new Player("seong");
	std::cout << player->GetName() << "\n";

	/*entities[1] = player;*/


	delete entity;
	delete player;

	std::cin.get();
}