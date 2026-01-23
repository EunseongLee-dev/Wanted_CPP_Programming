#pragma once // -> 중복 include 방지 구문(컴파일러 구문)

// 클래스
class Player
{
	// 접근 한정자 / 접근 제한자
	// 클래스 내부의 속성을 어디까지 노출시킬지 결정
	// public / protected / private
	// 공개	  / 상속 계층  / 본인만
public:

	//생성자
	// 파라미터를 받지 않는 생성자 = 기본 생성자
	//Player() = default;
	//~Player() = default;
	Player();
	Player(const char* inName);
	~Player();


	// Setter(세터)
	// 공개 함수(메소드) -> 메시지
	inline void SetX(const int inX)
	{
		x = inX;
	}

	inline void SetY(const int inY)
	{
		x = inY;
	}

	inline void SetSpeed(const int inSpeed)
	{
		x = inSpeed;
	}

	// Getter(게터)
	int GetX() const
	{
		return x;
	}

	// 클래스 조작 함수(외부)
	/*void Move(int x, int y)
	{
		SetX(x);
		SetY(y);
	}*/

	// 클래스 내부 선언
	void Move(int inX, int inY);

private:
	int x = 0;
	int y = 0;
	int speed = 0;

	// 이름 값(문자열)
	char* name = nullptr; // char name[10] = {};
};