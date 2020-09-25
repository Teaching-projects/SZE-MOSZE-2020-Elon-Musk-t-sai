#include "player.hpp"
#include <stdlib.h>

int main(int argc, char *argv[])
{

	Player player1(atoi(argv[2]), atoi(argv[3]), std::string(argv[1]));
	Player player2(atoi(argv[5]), atoi(argv[6]), std::string(argv[4]));

	std::cout << player1.getName() << " HP: " << player1.getHealth() << " DMG: " << player1.getDamage() << std::endl;
	std::cout << player2.getName() << " HP: " << player2.getHealth() << " DMG: " << player2.getDamage() << std::endl;
	while (player1.getHealth() != 0 && player2.getHealth() != 0)
	{
		std::cout << player1.getName() << " -> " << player2.getName() << std::endl;
		player2.receivedDamage(player1);
		std::cout << player2.getName() << " Received damage: " << player1.getDamage() << " Health remaining: " << player2.getHealth() << std::endl;
		if (player2.getHealth() == 0)
		{
			std::cout << player2.getName() << " lost all Healthpoint." << std::endl;
			break;
		}
		std::cout << player2.getName() << " -> " << player1.getName() << std::endl;
		player1.receivedDamage(player2);
		std::cout << player1.getName() << " Received damage: " << player2.getDamage() << " Health remaining: " << player1.getHealth() << std::endl;

		if (player1.getHealth() == 0)
		{
			std::cout << player1.getName() << " lost all Healthpoint." << std::endl;
			break;
		}
	}

	return 0;
}