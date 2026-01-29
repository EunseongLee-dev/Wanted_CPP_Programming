#pragma once

enum class VariableType
{
	Int,
	Float,
	Enum,
	String,
	Unknown
};

class Variable
{
public:
	int GetIntValue();
	float GetFloatValue();

private:
	char* name = nullptr;
	VariableType type = VariableType::Unknown;
	void* data = nullptr;
};

class Player
{
public:
	Player();
	Player(int id, int score, float attack);
	~Player();

	// 직렬화 (파일에)
	void Serialize(const char* path);

	// 역직렬화 (파일에서)
	void Deserialize(const char* path);

private:
	int score = 0;
	int id = 0;
	float attack = 0.0f;
};