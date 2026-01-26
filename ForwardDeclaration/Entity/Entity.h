#pragma once

// 전방 선언
class Vector;
class Entity
{
public:
	Entity() = default;
	Entity(int x, int y);
	// 복사 생성자
	Entity(const Entity& other);
	~Entity();

private:
	Vector* position = nullptr;
};
