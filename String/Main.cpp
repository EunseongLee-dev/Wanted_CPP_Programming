#include<iostream>

// 클래스 내부에서 문자열 다루기
class Player
{
	// public / protected / private
	// -> 접근 한정자 / 접근 제한자
	// 접근 가능한 범위를 설정
public:
	// 생성자
	// 객체를 생성할 때 호출되는 특별한 함수
	// 반환형이 없고, 클래스 이름과 동일
	Player(const char* inName)
	{
		// 문자열 복사
		// name = inName; = 불가능

		// 1. 저장 공간 확보
		// -> 확보할 공간의 크기를 알아야 함
		size_t length = strlen(inName) + 1; // 문자열 길이 계산 // +1 이유는 strlen은 nullptr 문자를 제외하고 구해줌 즉 nullptr 문자 공간도 필요
		name = new char[length];

		// 2. 문자열 복사
		//memcpy() == strcpy() 동일
		strcpy_s(name, length, inName); // _s <- strcpy 세이프 버전(권장) // strcpy_s(복사될 곳, 복사될 곳 크기, 복사할 대상)
	}

	// 소멸자
	// 객체가 해제될 때 실행
	~Player()
	{
		// if(name != nullptr)
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

private:
	// 문자열을 저장할 변수
	char* name = nullptr;

};

int main()
{
	// 문자열
	// 문자열은 불변성을 가짐
	const char* teststring = "Ronnie";
	std::cout << teststring << "\n";

	// 문자 배열
	char buffer[7] = { 'R', 'o', 'n', 'n', 'i', 'e', '\0'};
	std::cout << buffer << "\n";

	// 객체 기반으로 문자열 사용
	Player player("RonnieJ");
	

	std::cin.get();
}