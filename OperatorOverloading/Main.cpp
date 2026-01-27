#include <iostream>

// 연산자 오버로딩
class Point
{
public:
	Point(int x = 0, int y = 0)
		: x(x), y(y)
	{
	}

	//// 덧셈
	//Point Add(const Point& other)
	//{
	//	return Point(x + other.x, y + other.y);
	//}

	friend Point Add(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}

	// 연산자 오버로딩 기본사용 법
	Point operator+(const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}

	// 연산자 오버로딩 비 맴버 함수 구현 법 
	friend Point operator+(const Point& left, const Point& right)
	{
		return Point(left.x + right.x, left.y + right.y);
	}

public:
	int x = 0;
	int y = 0;


};

//Point Add(const Point& left, const Point& right)
//{
//	return Point(left.x + right.x, left.y + right.y);
//}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	return os << "(" << point.x << "," << point.y << ")\n";
}

int main()
{
	Point p1(1, 1);
	Point p2(5, 5);

	Point p3 = p1 + p2;

	/*std::cout << "(" << p3.x << "," << p3.y<< ")" << "\n";*/
	std::cout << p3 << "\n";
	std::cout.operator<<(10).operator<<(20);



	//Point p3(p1.x + p2.x, p1.y + p2.y);
}