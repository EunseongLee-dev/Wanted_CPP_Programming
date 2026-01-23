#include <iostream>

// 게임 물체(객체)
// Game-Obhect / Actor / Entity(개체)

class Entity
{
public:
	Entity()
	{
		std::cout << "Constructor called\n";
	}

	~Entity() = default;

	// 함수 끝에 const를 지정하면
	// 함수 본문에서 객체 내부의 값을 변경할 수 없음
	void ShowName() const
	{
		std::cout << "Entity.\n";
	}

	Entity* Getself()
	{
		// this는 자기 자신을 가리키는 "포인터"
		return this;
	}
};

int main()
{
	// 엔진 기술면접(참고)
	// 가능 or 불가능? = 그에따른 이유 = 함수내부에서 Entity에 대한 어떠한 조작도 없으면 함수 실행에는 문제가 없다.
	/*Entity* entity = nullptr;
	entity->ShowName();*/
	

	//const int count = 5;
	//Entity entities[count];

	//// Range-Based Loop (foreach)
	//for (const Entity& entity : entities)
	//{
	//	entity.ShowName();
	//}

	//const int counts = 5;
	//Entity* entitis[counts] = { }; // {} 기본값 세팅 null값
	//// memset(entitis, 0, sizeof(Entity*) * counts); / 과거 방식

	//for (int x = 0; x < counts; ++x)
	//{
	//	entitis[x] = new Entity();
	//}

	//for (Entity*& entiti : entitis)
	//{
	//	delete entiti;
	//	entiti = nullptr;
	//}


	Entity* entity = new Entity();
	std::cout << entity << "\n";
	std::cout << entity->Getself() << "\n";

	delete entity;

	std::cin.get();


}