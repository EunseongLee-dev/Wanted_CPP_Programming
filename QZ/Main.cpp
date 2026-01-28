#include <iostream>

class Account
{
public:
	Account(int _id, char* name)
	{
		id = _id;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	~Account()
	{
		delete name;
		name = nullptr;
	}


	char* Getname()
	{
		return name;
	}

	int Getlance()
	{
		return balance;
	}

	int Getid()
	{
		return id;
	}

	void Add(int x)
	{
		balance += x;
	}

	void Sub(int x)
	{
		balance -= x;
	}
private:
	int id;
	char* name;
	int balance = 0;

};

class Bank
{
public:
	void CreateAccount(int id, char* name)
	{
		for (int ix = 0; ix < 100; ++ix)
		{
			if (account[ix] == nullptr)
			{
				account[ix] = new Account(id, name);
				std::cout << name << " 의 계좌 개설 완료\n";
				return;
			}
			
			std::cout << "잔여 계좌 개설 공간 부족\n";
			return;
			
		}
	}
	void Deposit(int id, int x)
	{
		if (x < 0)
		{
			std::cout << "0원 이하는 입금할 수 없습니다.\n";
			return;
		}
		
		for (int ix = 0; ix < 100; ++ix)
		{
			if (account[ix]->Getid() == id)
			{
				account[ix]->Add(x);
				std::cout << account[ix]->Getname() << " 계좌 로 " << x << "원 입금완료.\n";
				return;
			}
		}
		std::cout << "계좌번호가 존재하지 않습니다.\n";
	}
	void Withdraw(int id, int x)
	{

		for (int ix = 0; ix < 100; ++ix)
		{
			if (account[ix]->Getid() == id)
			{
				if (account[ix]->Getlance() < x)
				{
					std::cout << "잔액 부족\n";
					return;
				}
				else
				{
					account[ix]->Sub(x);
					std::cout << account[ix]->Getname() << "계좌 에서 " << x << "원 출금완료\n";
					return;
				}
			}
		}
	}
	void Inquire()
	{
		for (int i = 0; i < 100; ++i)
		{
			if (!account[i])
			{
				continue;
			}
			else
			{
				std::cout
					<< "이름: " << account[i]->Getname() << "\n"
					<< "계좌번호: " << account[i]->Getid() << "\n"
					<< "잔액: " << account[i]->Getlance() << "\n\n";

			}
		}
	}

private:
	Account* account[100] = {};
};

int main()
{
	Bank su;

	while (true)
	{
		int menu;
		char end;
		std::cout << "메뉴\n"
			<< "----------------------\n"
			<< "1. 계좌 개설\n"
			<< "2. 입금\n"
			<< "3. 출금\n"
			<< "4. 전체 고객 잔액 조회\n"
			<< "5. 종료\n";
		std::cin >> menu;

		if (menu == 1)
		{
			int id;
			char name[50] = {};
			std::cout << "계좌 번호 입력: ";
			std::cin >> id;
			std::cout << "이름 입력: ";
			std::cin >> name;
			su.CreateAccount(id, name);
		}
		else if (menu == 2)
		{
			int id;
			int money;
			std::cout << "입금 할 계좌번호 입력: ";
			std::cin >> id;
			std::cout << "입금 할 금액: ";
			std::cin >> money;
			su.Deposit(id, money);
		}
		else if (menu == 3)
		{
			int id;
			int money;
			std::cout << "출금 할 계좌번호 입력: ";
			std::cin >> id;
			std::cout << "출금 할 금액: ";
			std::cin >> money;
			su.Withdraw(id, money);
		}
		else if (menu == 4)
		{
			su.Inquire();
		}
		else if (menu == 5)
		{
			break;
		}
	}
	
	std::cin.get();

}