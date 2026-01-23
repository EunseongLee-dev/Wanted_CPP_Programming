#include <iostream>
#include "Player.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 인스턴스 / 객체
	// 스택
	Player player1;
	player1.SetSpeed(3);
	player1.Move(5, 2);

	// 힙
	Player* player2 = new Player("Ronnie");
	player2->Move(3, 1); // = (*player2).Move(3, 1); / 두 코드는 같은 의미
	delete player2;
	player2 = nullptr;


	std::cin.get();
}