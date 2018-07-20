/*Copyright 2018 Borna Pekarić

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

Originally written in Orwell Dev-C++ 5.11*/

#include <iostream>
#include <cstdlib> //For RNG.
#include <ctime> //For RNG's seed.
using namespace std;

int duel(int);

int main()
{
	int enemy, enemy_choice, playing, enemy_chance, duel_result;
	srand(time(0));
	cout << "Rock-Paper-Scissors Tournament\n\nLicensed under Apache License, version 2.0.\n\nCopyright 2018 Borna Pekaric\n\n";
	system("pause");
	system("cls");
	cout << "You are participating in your county's rock-paper-scissors tournament and you\n";
	cout << "have made it to the quarterfinals. You are only three victories away from\n";
	cout << "winning the prize money of 1000 dollars. Pray to Lady Luck that you won't lose\n";
	cout << "now, now that you're this close to victory.\n\n";
	system("pause");
	system("cls");
	playing = 1;
	while (playing == 1) //This loop enables to player to start playing again without exiting and restarting the game itself.
	{
		duel_result = 0;
		enemy = 1;
		while (enemy < 4)
		{
			if (enemy == 1)
			{
				while (duel_result == 0)
				{
					enemy_chance = rand() % 100 + 1;
					{ //Has 75% chance to pick Rock, 22% chance to pick Paper and 3% chance to pick Scissors.
						if (enemy_chance <= 75)
						{
							enemy_choice = 1;
						}
						if (enemy_chance > 75 && enemy_chance <= 97)
						{
							enemy_choice = 2;
						}
						if (enemy_chance > 97)
						{
							enemy_choice = 3;
						}
					}
					duel_result = duel(enemy_choice);
				}
				if (duel_result == 1)
				{
					cout << "\nYou lost the quarterfinals. Defeated, you go home. Game over.\n\n";
					system("pause");
					cout << "\n";
					enemy = 4;
				}
				if (duel_result == 2)
				{
					cout << "\nYou win the quarterfinals and proceed to semifinals.\n\n";
				}
			}
			duel_result = 0;
			if (enemy == 2)
			{
				while (duel_result == 0)
				{
					enemy_chance = rand() % 100 + 1;
					{ //Has 8% chance to pick Rock, 40% chance to pick Paper and 52% chance to pick Scissors.
						if (enemy_chance > 92)
						{
							enemy_choice = 1;
						}
						if (enemy_chance > 52 && enemy_chance <= 92)
						{
							enemy_choice = 2;
						}
						if (enemy_chance <= 52)
						{
							enemy_choice = 3;
						}
					duel_result = duel(enemy_choice);
					}
				}
				if (duel_result == 1)
				{
					cout << "\nYou lost the semifinals. You got very close, but got defeated. Game over.\n\n";
					system("pause");
					cout << "\n";
					enemy = 4;
				}
				if (duel_result == 2)
				{
					cout << "\nYou win the quarterfinals and proceed to finals.\n\n";
				}
			}
			duel_result = 0;
			if (enemy == 3)
			{
				while (duel_result == 0)
				{
					enemy_chance = rand() % 100 + 1;
					{ //Has 33% chance to pick Rock, 34% chance to pick Paper and 33% chance to pick Scissors.
						if (enemy_chance <= 33)
						{
							enemy_choice = 1;
						}
						if (enemy_chance > 33 && enemy_chance <= 67)
						{
							enemy_choice = 2;
						}
						if (enemy_chance > 67)
						{
							enemy_choice = 3;
						}
					duel_result = duel(enemy_choice);
					}
				}
				if (duel_result == 1)
				{
					cout << "\nSadly, you lose the finals. You lost after getting this close. Game over.\n\n";
					system("pause");
					cout << "\n";
					enemy = 4;
				}
				if (duel_result == 2)
				{
					cout << "\nCongratulations, you won the tournament. After facing off against a dozen of" << endl;
					cout << "opponents, the prize is yours. You win.\n\n";
				}
			}
			enemy = enemy + 1;
		}
		{ //The purpose of the entire "while (playing == 1)" loop depends on this block of code.
			cout << "Would you like to play again or exit the game? 1 to play again, 2 to exit. ";
			cin >> playing;
			cout << "\n";
			while (playing < 1 || playing > 2)
			{
				cout << "\nWrong number. Enter 1 to play again or 2 to exit. ";
				cin >> playing;
			}
		}
	}
	return 0;
}

duel(int enemys_choice)
{
	int player_choice;
	cout << "Make a choice. 1 for Rock, 2 for Paper, 3 for Scissors. ";
	cin >> player_choice;
	while (player_choice < 1 || player_choice > 3)
	{
		cout << "\nWrong choice. Choose again. 1 for Rock, 2 for Paper, 3 for Scissors. ";
		cin >> player_choice;
	}
	if ((player_choice == 1 && enemys_choice == 1) || (player_choice == 2 && enemys_choice == 2) || (player_choice == 3 && enemys_choice == 3))
	{
		cout << "\nIt's a tie. You have to duel this enemy again.\n\n";
		return 0;
	}
	if ((player_choice == 1 && enemys_choice == 2) || (player_choice == 2 && enemys_choice == 3) || (player_choice == 3 && enemys_choice == 1))
	{
		return 1;
	}
	if ((player_choice == 2 && enemys_choice == 1) || (player_choice == 3 && enemys_choice == 2) || (player_choice == 1 && enemys_choice == 3))
	{
		return 2;
	}
}
