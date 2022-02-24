#include "Game.h"

int main() {
	srand(time(NULL));
	int win = 0, count = 0;
	//cout << "Tests passeds: " << tests() << "/2" << endl; (не доделан)
	Warrior player_1;
	Human player_2;
	while (win != 1) {
		std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n";
		std::cout << "-------------------------Player #1-----------------------\n";
		player_1.print_character_info();
		std::cout << "=========================Round #" << count << "=========================\n";
		player_2.print_character_info();
		std::cout << "-------------------------Player #2------------------------\n";
		std::cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n";
		if (player_1.getHealth() > 0 && win == 0 && player_2.getHealth() > 0) { player_2.attack(&player_1); }
		if (player_1.getHealth() <= 0 || player_2.getHealth() <= 0) { win = 1; };
		if (player_2.getHealth() > 0 && win == 0 && player_1.getHealth() > 0) { player_1.attack(&player_2); }
		if (player_1.getHealth() <= 0 || player_2.getHealth() <= 0) { win = 1; };
		count++;
	};
	std::cout << "\n\nFinal results!\n\n";
	std::cout << "-------------------------Player #1-----------------------\n";
	player_1.print_character_info();
	std::cout << "============================================================\n";
	player_2.print_character_info();
	std::cout << "-------------------------Player #2------------------------\n";

	std::cout << "\n============================================================\n";
	std::cout << "=========================Healing============================\n";
	std::cout << "=========================Winner=============================\n\n";
	if (player_1.getHealth() > 0) {
		player_1.healing();
		player_1.print_character_info();
	}
	else {
		player_2.healing();
		player_2.print_character_info();
	}
	system("pause");
	return 0;
}
