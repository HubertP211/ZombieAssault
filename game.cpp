#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "player.h"
#include "enemy_boss_one.h"
#include "enemy_boss_two.h"
#include <iostream>
#include <sstream>

using namespace std;





void game::runGame(bool &exit, bool &menu, bool &level, bool &shop, sf::RenderWindow &okno, int &enemy_ammount, player &main_player)
{




	using namespace std;


	srand(time(NULL));
	//sf::RenderWindow okno (sf::VideoMode(1024, 768, 32), "Gra");
	//okno.setVerticalSyncEnabled(true);
	//okno.setFramerateLimit(60);

	okno.setMouseCursorVisible(false);
	
	//player main_player;

	main_player.create_player();
	int x;
	
	enemy_ammount+= rand () % 30 + 1;
	x = enemy_ammount;


	int y = x;
	enemy * main_enemy = new enemy[x];

	for(int i = 0; i<x; i++)
	{
		main_enemy[i].create_enemy();
	}

	//player main_player;
	main_player.create_player();
	
	

	bullet bullet_player[100];

	
	

	


	sf::Clock clock;
    float accumulator = 0;
    float TIME_STEP = 0.01f;
	int frame = 0;

	while(level == true)
	{
		accumulator += clock.restart().asSeconds();
		//cout<<"bulletcount = "<<main_player.bullet_count<<endl;
		

		if(accumulator > TIME_STEP)
		{

			main_player.player_movement(frame, okno, bullet_player, menu, level);
			//main_enemy.enemy_movement(frame, okno, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y );
			main_player.player_shot(okno, bullet_player, main_player.bullet_count, main_enemy, x, frame, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y, y);
			main_player.player_vs_enemy(okno, main_enemy, x, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y, main_player.life_player);


			sf::Event zdarzenie;
			while(okno.pollEvent(zdarzenie))
			{
				if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				{
					okno.close();
				}
				
			}
			frame++;
			if(frame>140) frame = 0;
			accumulator -= TIME_STEP;
		}

		
		
		okno.clear(sf::Color(200, 200, 200));
		
		//okno.draw(bullet_player[main_player.bullet_count].bullet_sprite);

		main_player.player_draw_everything(okno, bullet_player, main_player.bullet_count, main_enemy, x, y, level, shop);
		okno.draw(main_player.player_sprite);
		okno.draw(main_player.aim);
		okno.draw(main_player.weapon);
		
		//okno.draw(main_player.view_sprite);
		okno.draw(main_player.interface_sprite);
		okno.draw(main_player.life_bar_sprite);
		okno.draw(main_player.text);
		okno.draw(main_player.text2);


		
		


		//main_player.player_shot(okno, bullet_player, main_player.bullet_count, main_enemy, x, frame, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y);
		
		


		//okno.draw(main_enemy.enemy_sprite);
		okno.display();



	}

}

void game::runGame_boss_one(bool &exit, bool &menu, bool &level, bool &shop, sf::RenderWindow &okno, int &enemy_ammount, player &main_player)
{




	using namespace std;


	srand(time(NULL));
	//sf::RenderWindow okno (sf::VideoMode(1024, 768, 32), "Gra");
	//okno.setVerticalSyncEnabled(true);
	//okno.setFramerateLimit(60);

	okno.setMouseCursorVisible(false);
	
	//player main_player;

	main_player.create_player();
	int x;
	
	//enemy_ammount+= rand () % 30 + 1;
	x = 1;


	int y = x;
	enemy_boss_one * main_enemy = new enemy_boss_one[x];

	for(int i = 0; i<x; i++)
	{
		main_enemy[i].create_enemy();
	}

	//player main_player;
	main_player.create_player();
	
	

	bullet bullet_player[100];

	
	

	


	sf::Clock clock;
    float accumulator = 0;
    float TIME_STEP = 0.01f;
	int frame = 0;

	while(level == true)
	{
		accumulator += clock.restart().asSeconds();
		//cout<<"bulletcount = "<<main_player.bullet_count<<endl;
		

		if(accumulator > TIME_STEP)
		{

			main_player.player_movement(frame, okno, bullet_player, menu, level);
			//main_enemy.enemy_movement(frame, okno, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y );
			main_player.player_shot(okno, bullet_player, main_player.bullet_count, main_enemy, x, frame, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y, y);
			main_player.player_vs_enemy(okno, main_enemy, x, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y, main_player.life_player);


			sf::Event zdarzenie;
			while(okno.pollEvent(zdarzenie))
			{
				if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				{
					okno.close();
				}
				
			}
			frame++;
			if(frame>140) frame = 0;
			accumulator -= TIME_STEP;
		}

		
		
		okno.clear(sf::Color(200, 200, 200));
		
		//okno.draw(bullet_player[main_player.bullet_count].bullet_sprite);

		main_player.player_draw_everything(okno, bullet_player, main_player.bullet_count, main_enemy, x, y, level, shop);
		okno.draw(main_player.player_sprite);
		okno.draw(main_player.aim);
		okno.draw(main_player.weapon);
		
		okno.draw(main_player.view_sprite);
		okno.draw(main_player.interface_sprite);
		okno.draw(main_player.life_bar_sprite);
		okno.draw(main_player.text);
		okno.draw(main_player.text2);


		
		


		//main_player.player_shot(okno, bullet_player, main_player.bullet_count, main_enemy, x, frame, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y);
		
		


		//okno.draw(main_enemy.enemy_sprite);
		okno.display();



	}

}



void game::runGame_boss_two(bool &exit, bool &menu, bool &level, bool &shop, sf::RenderWindow &okno, int &enemy_ammount, player &main_player)
{




	using namespace std;


	srand(time(NULL));
	//sf::RenderWindow okno (sf::VideoMode(1024, 768, 32), "Gra");
	//okno.setVerticalSyncEnabled(true);
	//okno.setFramerateLimit(60);

	okno.setMouseCursorVisible(false);
	
	//player main_player;

	main_player.create_player();
	int x;
	
	//enemy_ammount+= rand () % 30 + 1;
	x = 1;


	int y = x;
	enemy_boss_two * main_enemy = new enemy_boss_two[x];

	for(int i = 0; i<x; i++)
	{
		main_enemy[i].create_enemy();
	}

	//player main_player;
	main_player.create_player();
	
	

	bullet bullet_player[100];

	
	

	


	sf::Clock clock;
    float accumulator = 0;
    float TIME_STEP = 0.01f;
	int frame = 0;

	while(level == true)
	{
		accumulator += clock.restart().asSeconds();
		//cout<<"bulletcount = "<<main_player.bullet_count<<endl;
		

		if(accumulator > TIME_STEP)
		{

			main_player.player_movement(frame, okno, bullet_player, menu, level);
			//main_enemy.enemy_movement(frame, okno, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y );
			main_player.player_shot(okno, bullet_player, main_player.bullet_count, main_enemy, x, frame, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y, y);
			main_player.player_vs_enemy(okno, main_enemy, x, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y, main_player.life_player);


			sf::Event zdarzenie;
			while(okno.pollEvent(zdarzenie))
			{
				if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				{
					okno.close();
				}
				
			}
			frame++;
			if(frame>140) frame = 0;
			accumulator -= TIME_STEP;
		}

		
		
		okno.clear(sf::Color(200, 200, 200));
		
		//okno.draw(bullet_player[main_player.bullet_count].bullet_sprite);

		main_player.player_draw_everything(okno, bullet_player, main_player.bullet_count, main_enemy, x, y, level, shop);
		okno.draw(main_player.player_sprite);
		okno.draw(main_player.aim);
		okno.draw(main_player.weapon);
		
		//okno.draw(main_player.view_sprite);
		okno.draw(main_player.interface_sprite);
		okno.draw(main_player.life_bar_sprite);
		okno.draw(main_player.text);
		okno.draw(main_player.text2);


		
		


		//main_player.player_shot(okno, bullet_player, main_player.bullet_count, main_enemy, x, frame, main_player.player_sprite.getPosition().x, main_player.player_sprite.getPosition().y);
		
		


		//okno.draw(main_enemy.enemy_sprite);
		okno.display();



	}

}



void game::runMenu(bool &exit, bool &menu, bool &level, sf::RenderWindow &okno)
{
	start.loadFromFile("start.png");
	start_button.setTexture(start);
	start_button.setOrigin(150,50);

	end.loadFromFile("exit.png");
	end_button.setTexture(end);
	end_button.setOrigin(150, 50);

	start_button.setPosition(200, 700);
	end_button.setPosition(824, 700);

	background_texture.loadFromFile("background.png");
	background.setTexture(background_texture);

	background.setOrigin(512, 384);
	background.setPosition(512, 384);
	

	okno.setMouseCursorVisible(true);

	while(menu == true)
	{
		
		while(okno.pollEvent(menu_choose))
		{
			if(menu_choose.type == sf::Event::MouseButtonPressed && menu_choose.mouseButton.button == sf::Mouse::Left)
			{
				if(sf::Mouse::getPosition(okno).x <= start_button.getPosition().x + 150 && sf::Mouse::getPosition(okno).x >= start_button.getPosition().x - 150 && sf::Mouse::getPosition(okno).y <= start_button.getPosition().y + 50 && sf::Mouse::getPosition(okno).y >= start_button.getPosition().y - 50)
				{
					enemy_ammount = 1;
					level = true;
					menu = false;
				}
			}

			if(menu_choose.type == sf::Event::MouseButtonPressed && menu_choose.mouseButton.button == sf::Mouse::Left)
			{
				if(sf::Mouse::getPosition(okno).x <= end_button.getPosition().x + 150 && sf::Mouse::getPosition(okno).x >= end_button.getPosition().x - 150 && sf::Mouse::getPosition(okno).y <= end_button.getPosition().y + 50 && sf::Mouse::getPosition(okno).y >= end_button.getPosition().y - 50)
				{
					
					menu = false;
					exit = true;
				}
			}
		}

		okno.clear(sf::Color(200, 200, 200));
		okno.draw(background);
		okno.draw(start_button);
		okno.draw(end_button);
		okno.display();
	}
}


void game::runShop(bool &level, bool &shop, player &main_player, sf::RenderWindow &okno)
{
	deagle_button_texture.loadFromFile("deagle_button.png");
	uzi_button_texture.loadFromFile("uzi_button.png");
	ak_button_texture.loadFromFile("ak_button.png");
	usas_button_texture.loadFromFile("usas_button.png");

	uzi_button_false_texture.loadFromFile("uzi_button_false.png");
	ak_button_false_texture.loadFromFile("ak_button_false.png");
	usas_button_false_texture.loadFromFile("usas_button_false.png");

	buy_deagle_texture.loadFromFile("buy_deagle.png");
	buy_uzi_texture.loadFromFile("buy_deagle.png");
	buy_ak_texture.loadFromFile("buy_deagle.png");
	buy_usas_texture.loadFromFile("buy_deagle.png");

	buy_deagle_sprite.setTexture(buy_deagle_texture);
	buy_uzi_sprite.setTexture(buy_deagle_texture);
	buy_ak_sprite.setTexture(buy_deagle_texture);
	buy_usas_sprite.setTexture(buy_deagle_texture);

	next_wave_texture.loadFromFile("next_wave.png");

	next_wave_sprite.setTexture(next_wave_texture);

	next_wave_sprite.setOrigin(150, 50);
	next_wave_sprite.setPosition(860, 696);

	deagle_button_sprite.setOrigin(225, 75);
	deagle_button_sprite.setPosition(233, 91);

	uzi_button_sprite.setOrigin(225, 75);
	uzi_button_sprite.setPosition(233, 287);

	ak_button_sprite.setOrigin(225, 75);
	ak_button_sprite.setPosition(233, 481);

	usas_button_sprite.setOrigin(225, 75);
	usas_button_sprite.setPosition(233, 672);

	buy_deagle_sprite.setOrigin(66.5, 22);
	buy_uzi_sprite.setOrigin(66.5, 22);
	buy_ak_sprite.setOrigin(66.5, 22);
	buy_usas_sprite.setOrigin(66.5, 22);

	buy_deagle_sprite.setPosition(531.5, 39);
	buy_uzi_sprite.setPosition(531.5, 235);
	buy_ak_sprite.setPosition(531.5, 429);
	buy_usas_sprite.setPosition(531.5, 620);

	magazine_texture.loadFromFile("magazine_deagle.png");
	deagle_magazine_sprite.setTexture(magazine_texture);
	uzi_magazine_sprite.setTexture(magazine_texture);
	ak_magazine_sprite.setTexture(magazine_texture);
	usas_magazine_sprite.setTexture(magazine_texture);

	deagle_magazine_sprite.setOrigin(66.5, 22);
	uzi_magazine_sprite.setOrigin(66.5, 22);
	ak_magazine_sprite.setOrigin(66.5, 22);
	usas_magazine_sprite.setOrigin(66.5, 22);

	deagle_magazine_sprite.setPosition(531.5, 91);
	uzi_magazine_sprite.setPosition(531.5, 287);
	ak_magazine_sprite.setPosition(531.5, 481);
	usas_magazine_sprite.setPosition(531.5, 674);

	magazine_ammount.loadFromFile("magazine_ammount.png");
	deagle_magazine_ammount_sprite.setTexture(magazine_ammount);
	uzi_magazine_ammount_sprite.setTexture(magazine_ammount);
	ak_magazine_ammount_sprite.setTexture(magazine_ammount);
	usas_magazine_ammount_sprite.setTexture(magazine_ammount);

	deagle_magazine_ammount_sprite.setOrigin(66.5, 22);
	uzi_magazine_ammount_sprite.setOrigin(66.5, 22);
	ak_magazine_ammount_sprite.setOrigin(66.5, 22);
	usas_magazine_ammount_sprite.setOrigin(66.5, 22);

	deagle_magazine_ammount_sprite.setPosition(531.5, 143);
	uzi_magazine_ammount_sprite.setPosition(531.5, 339);
	ak_magazine_ammount_sprite.setPosition(531.5, 533);
	usas_magazine_ammount_sprite.setPosition(531.5, 724);

	life_ammount.setTexture(magazine_ammount);
	money_ammount.setTexture(magazine_ammount);

	life_ammount.setOrigin(66.5, 22);
	money_ammount.setOrigin(66.5, 22);

	life_ammount.setPosition(941.5, 481);
	money_ammount.setPosition(778.5, 481);

	medkit_texture.loadFromFile("medkit.png");
	medkit_sprite.setTexture(medkit_texture);

	medkit_sprite.setOrigin(150, 50);
	medkit_sprite.setPosition(860, 570);

	font2.loadFromFile("BOYCOTT.ttf");

	shop_magazine_deagle.setFont(font2);
	shop_magazine_deagle.setCharacterSize(24);
	shop_magazine_deagle.setColor(sf::Color::Black);
	shop_magazine_deagle.setPosition(531.5, 130);
	shop_magazine_deagle.setOrigin(12, 0);

	shop_magazine_uzi.setFont(font2);
	shop_magazine_uzi.setCharacterSize(24);
	shop_magazine_uzi.setColor(sf::Color::Black);
	shop_magazine_uzi.setPosition(531.5, 326);
	shop_magazine_uzi.setOrigin(12, 0);

	shop_magazine_ak.setFont(font2);
	shop_magazine_ak.setCharacterSize(24);
	shop_magazine_ak.setColor(sf::Color::Black);
	shop_magazine_ak.setPosition(531.5, 520);
	shop_magazine_ak.setOrigin(12, 0);

	shop_magazine_usas.setFont(font2);
	shop_magazine_usas.setCharacterSize(24);
	shop_magazine_usas.setColor(sf::Color::Black);
	shop_magazine_usas.setPosition(531.5, 711);
	shop_magazine_usas.setOrigin(12, 0);

	shop_money.setFont(font2);
	shop_money.setCharacterSize(24);
	shop_money.setColor(sf::Color::Black);
	shop_money.setPosition(772, 468);
	shop_money.setOrigin(12, 0);

	shop_life.setFont(font2);
	shop_life.setCharacterSize(24);
	shop_life.setColor(sf::Color::Black);
	shop_life.setPosition(935, 468);
	shop_life.setOrigin(12, 0);

	ostringstream ss3;
	ss3 << main_player.magazine_deagle;
	string str3 = ss3.str();
	shop_magazine_deagle.setString(str3);

	ostringstream ss4;
	ss4 << main_player.magazine_uzi;
	string str4 = ss4.str();
	shop_magazine_uzi.setString(str4);

	ostringstream ss5;
	ss5 << main_player.magazine_ak;
	string str5 = ss5.str();
	shop_magazine_ak.setString(str5);

	ostringstream ss6;
	ss6 << main_player.magazine_usas;
	string str6 = ss6.str();
	shop_magazine_usas.setString(str6);

	ostringstream ss7;
	ss7 << main_player.money;
	string str7 = ss7.str();
	shop_money.setString(str7);

	ostringstream ss8;
	ss8 << main_player.life_player;
	string str8 = ss8.str();
	shop_life.setString(str8);

	





	deagle_button_sprite.setTexture(deagle_button_texture);

	okno.setMouseCursorVisible(true);


	if(main_player.uzi_bought==true)
	{
		uzi_button_sprite.setTexture(uzi_button_texture);
	}
	else
	{
		uzi_button_sprite.setTexture(uzi_button_false_texture);
	}

	if(main_player.ak_bought==true)
	{
		ak_button_sprite.setTexture(ak_button_texture);
	}
	else
	{
		ak_button_sprite.setTexture(ak_button_false_texture);
	}

	if(main_player.usas_bought==true)
	{
		usas_button_sprite.setTexture(usas_button_texture);
	}
	else
	{
		usas_button_sprite.setTexture(usas_button_false_texture);
	}


	while(shop == true)
	{
		sf::Vector2f mouse(sf::Mouse::getPosition(okno));
		while(okno.pollEvent(shop_choose))
		{
			if(shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
				if(next_wave_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
				{
					level = true;
					shop = false;
				}
			}

			if(main_player.uzi_bought == false && main_player.money >= 830 && buy_uzi_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
				
					main_player.uzi_bought = true;
					uzi_button_sprite.setTexture(uzi_button_texture);
					main_player.money = main_player.money - 830;

					ostringstream ss7;
					ss7 << main_player.money;
					string str7 = ss7.str();
					shop_money.setString(str7);
				
			}

			if(main_player.ak_bought == false && main_player.money >= 3125 && buy_ak_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
				
					main_player.ak_bought = true;
					ak_button_sprite.setTexture(ak_button_texture);
					main_player.money = main_player.money - 3125;

					ostringstream ss7;
					ss7 << main_player.money;
					string str7 = ss7.str();
					shop_money.setString(str7);
				
			}

			if(main_player.usas_bought == false && main_player.money >= 5000 && buy_usas_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
				
					main_player.usas_bought = true;
					usas_button_sprite.setTexture(usas_button_texture);
					main_player.money = main_player.money - 5000;

					ostringstream ss7;
					ss7 << main_player.money;
					string str7 = ss7.str();
					shop_money.setString(str7);
				
			}

			if(main_player.uzi_bought == true && main_player.money >= 20 && uzi_magazine_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
				
					main_player.money = main_player.money - 20;
					main_player.magazine_uzi = main_player.magazine_uzi + 1;
					ostringstream ss4;
					ss4 << main_player.magazine_uzi;
					string str4 = ss4.str();
					shop_magazine_uzi.setString(str4);

					ostringstream ss7;
					ss7 << main_player.money;
					string str7 = ss7.str();
					shop_money.setString(str7);

				
			}

			if(main_player.ak_bought == true && main_player.money >= 50 && ak_magazine_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
				
					main_player.money = main_player.money - 50;
					main_player.magazine_ak = main_player.magazine_ak + 1;
					ostringstream ss5;
					ss5 << main_player.magazine_ak;
					string str5 = ss5.str();
					shop_magazine_ak.setString(str5);

					ostringstream ss7;
					ss7 << main_player.money;
					string str7 = ss7.str();
					shop_money.setString(str7);

				
			}

			if(main_player.usas_bought == true && main_player.money >= 100 && usas_magazine_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
				
					main_player.money = main_player.money - 100;
					main_player.magazine_usas = main_player.magazine_usas + 1;
					ostringstream ss6;
					ss6 << main_player.magazine_usas;
					string str6 = ss6.str();
					shop_magazine_usas.setString(str6);

					ostringstream ss7;
					ss7 << main_player.money;
					string str7 = ss7.str();
					shop_money.setString(str7);

				
			}

			if(main_player.life_player <100 && main_player.money >= 100 && medkit_sprite.getGlobalBounds().contains(mouse) && shop_choose.type == sf::Event::MouseButtonPressed && shop_choose.mouseButton.button == sf::Mouse::Left)
			{
					main_player.life_player = 100;
					main_player.money = main_player.money - 100;

					ostringstream ss7;
					ss7 << main_player.money;
					string str7 = ss7.str();
					shop_money.setString(str7);

					ostringstream ss8;
					ss8 << main_player.life_player;
					string str8 = ss8.str();
					shop_life.setString(str8);



			}

		}

		okno.clear(sf::Color(200, 200, 200));
		okno.draw(next_wave_sprite);
		okno.draw(deagle_button_sprite);
		okno.draw(uzi_button_sprite);
		okno.draw(ak_button_sprite);
		okno.draw(usas_button_sprite);
		okno.draw(buy_deagle_sprite);
		okno.draw(buy_uzi_sprite);
		okno.draw(buy_ak_sprite);
		okno.draw(buy_usas_sprite);
		okno.draw(deagle_magazine_sprite);
		okno.draw(uzi_magazine_sprite);
		okno.draw(ak_magazine_sprite);
		okno.draw(usas_magazine_sprite);
		okno.draw(deagle_magazine_ammount_sprite);
		okno.draw(uzi_magazine_ammount_sprite);
		okno.draw(ak_magazine_ammount_sprite);
		okno.draw(usas_magazine_ammount_sprite);
		okno.draw(shop_magazine_deagle);
		okno.draw(shop_magazine_uzi);
		okno.draw(shop_magazine_ak);
		okno.draw(shop_magazine_usas);
		okno.draw(life_ammount);
		okno.draw(money_ammount);
		okno.draw(medkit_sprite);
		okno.draw(shop_life);
		okno.draw(shop_money);
		
		okno.display();




	}





}










