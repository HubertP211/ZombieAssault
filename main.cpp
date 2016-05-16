#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "player.h"
#include "enemy.h"
#include "game.h"



using namespace std;

int main()
{
	
	sf::RenderWindow okno (sf::VideoMode(1024, 768, 32), "Gra");
	
	game main_game;
	bool level = false;
	bool menu = false;
	bool exit = false;
	bool shop = true;

	int level_count = 4;

	main_game.enemy_ammount = 0;

	player main_player;

	main_player.money = 100000;

	main_player.deagle_choosen = true;
	main_player.uzi_choosen = false;

	main_player.uzi_bought = false;
	main_player.ak_bought = false;
	main_player.usas_bought = false;

	main_player.weapon.setOrigin(0, 25);

	main_player.ammo_deagle_static = 8;
	main_player.magazine_deagle = 99; 

	
	main_player.ammo_uzi_static = 32;
	main_player.magazine_uzi = 0; 

	main_player.ammo_ak_static = 30;
	main_player.magazine_ak = 0; 

	main_player.ammo_usas_static = 10;
	main_player.magazine_usas = 0; 

	main_player.life_player = 100;

	main_player.ammo_deagle_dynamic = main_player.ammo_deagle_static;
	main_player.ammo_uzi_dynamic = main_player.ammo_uzi_static;

	

	while(exit == false)
	{
		if(menu == true)
		{
			main_game.runMenu(exit, menu, level, okno);
		}

		if(level == true)
		{
			if(level_count == 5)
			{
				main_game.runGame_boss_one(exit, menu, level, shop, okno, main_game.enemy_ammount, main_player);
			}
			if(level_count == 10)
			{
				main_game.runGame_boss_two(exit, menu, level, shop, okno, main_game.enemy_ammount, main_player);
			}
			else
			{
				main_game.runGame(exit, menu, level, shop, okno, main_game.enemy_ammount, main_player);
			}
		}

		if(shop==true)
		{
			main_game.runShop(level, shop, main_player, okno);
			level_count = level_count + 1;
		}

	}

	
	

	
	
	


}