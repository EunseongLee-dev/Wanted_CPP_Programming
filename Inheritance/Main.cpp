#include <iostream>

// 클래스
class Entity
{
public:
	Entity()
	{
		std::cout << "Entity() called\n";
	}
	~Entity()
	{
		std::cout << "~Entity() called\n";
	}

protected:
	float x = 0.0f;
	float y = 0.0f;
};

// 다음에 상속할 부모 클래스 타입 지정
class Player : public Entity
{
public:
	Player()
	{
		std::cout << "Player() called\n";
	}
	~Player()
	{
		std::cout << "~Player() called\n";
	}

private:
	char* name = nullptr;
};

int main()
{
	Player player;


	std::cin.get();
}