#include "Player.h"
#include <iostream>

// 기본값 설정, 자원 할당
Player::Player()
{

}

Player::Player(const char* inName)
{
	// 동적 할당 및 문자열 복사
	size_t length = strlen(inName) + 1;
	name = new char[length];
	
	// 복사 처리
	strcpy_s(name, length, inName);
}


// 자원 해제
Player::~Player()
{
	// null 체크
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}

// 클래스 외부 정의
// :: 범위 지정 연산자
void Player::Move(int inX, int inY)
{
	x = inX;
	y = inY;
}

//// 클래스 조작 함수(내부)
//void Move(Player& player, int x, int y)
//{
//	player.SetX(x);
//	player.SetY(y);
//}