#include <iostream>

class Entity
{
public:
	// 정답
	// int GetX() cosnt {return x;}
	
	// friend 사용 권장 안함, 흐름 및 엔진에서 해석가능을 위함
	// class의 멤버 함수가 아닌 외부에 선언된 함수임
	/*friend void ShowEntity(Entity& entity);*/

	void ShowEntity(Entity& entity)
	{
		std::cout << entity.x << ", " << entity.y << "\n";
	}

	// 접근 한정자/제한자 (Visivility)
private:
	int x = 0;
	int y = 0;
};

// Entity 정보를 출력하는 함수
//void ShowEntity(Entity& entity)
//{
//	std::cout << entity.x << ", " << entity.y << "\n";
//}


int main()
{
	Entity entity;
	entity.ShowEntity(entity);
}