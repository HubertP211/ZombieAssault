#include "player.h"
//#include "bullet.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "math.h"
#include <sstream>

#include <iostream>
using namespace std;



void player::create_player()
{
	player_texture.loadFromFile("player.png");
	player_sprite.setTexture(player_texture);
	player_sprite.setPosition(200, 200);
    player_sprite.setOrigin(25, 25);

	interface_texture.loadFromFile("interface.png");
	interface_sprite.setTexture(interface_texture);
	interface_sprite.setOrigin(100, 50);
	interface_sprite.setPosition(100, 718);

	life_bar_texture.loadFromFile("life_bar.png");
	life_bar_sprite.setTexture(life_bar_texture);
	life_bar_sprite.setOrigin(0, 10);
	life_bar_sprite.setPosition(25, 741); //741

	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(18);
	text.setColor(sf::Color::Red);

	text.setPosition(140, 680);

	text2.setFont(font);
	text2.setCharacterSize(18);
	text2.setColor(sf::Color::Red);
	text2.setPosition(140, 700);
	

	move1.loadFromFile("move1.png");
    move2.loadFromFile("move2.png");
    move3.loadFromFile("move3.png");
    move4.loadFromFile("move4.png");
    move5.loadFromFile("move5.png");

	view_texture.loadFromFile("view.png");
	view_sprite.setTexture(view_texture);
	view_sprite.setOrigin(1250,1250);

	

	

	

	mouse_aim.loadFromFile("aim.png");
	aim.setTexture(mouse_aim);
	aim.setOrigin(5, 5);

	deagle.loadFromFile("deagle.png");
	uzi.loadFromFile("uzi.png");
	ak.loadFromFile("ak.png");
	usas.loadFromFile("usas.png");

	deagle_shot.loadFromFile("deagle_shot.png");
	uzi_shot.loadFromFile("uzi_shot.png");
	ak_shot.loadFromFile("ak_shot.png");
	usas_shot.loadFromFile("usas_shot.png");

	deagle_sound.loadFromFile("deagle.wav");
	uzi_sound.loadFromFile("uzi.wav");
	ak_sound.loadFromFile("ak.wav");
	usas_sound.loadFromFile("usas.wav");
	empty_sound.loadFromFile("empty.wav");
	reload_sound.loadFromFile("reload.wav");

	
	weapon_sound_deagle.setBuffer(deagle_sound);
	weapon_sound_uzi.setBuffer(uzi_sound);
	weapon_sound_ak.setBuffer(ak_sound);
	weapon_sound_usas.setBuffer(usas_sound);
	weapon_reload_sound.setBuffer(reload_sound);
	weapon_empty_sound.setBuffer(empty_sound);


	weapon.setTexture(deagle);

	//ostringstream ss;
	//ss << magazine_deagle;
	//string str = ss.str();
	//text.setString(str);

	ostringstream ss2;
	ss2 << money;
	string str2 = ss2.str();
	text2.setString(str2);
	
	



	bullet_count = 0;
	//life_player = 100;
	player_speed = 1;
	
}

void player::player_movement(int &frame, sf::RenderWindow &okno, bullet bullet_player[], bool &menu, bool &level)
{
	
	aim.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(okno)));

	weapon.setPosition(player_sprite.getPosition());
	view_sprite.setPosition(player_sprite.getPosition());
	
	
	angle = atan2(sf::Mouse::getPosition(okno).y - player_sprite.getPosition().y, sf::Mouse::getPosition(okno).x - player_sprite.getPosition().x)* 180/3.14;
	player_sprite.setRotation(angle);
	weapon.setRotation(angle);
	view_sprite.setRotation(angle);
	

	if(deagle_choosen==true)
	{
		weapon.setTexture(deagle);
		damage = rand() % 40 + 31;
		
	}

	if(uzi_choosen==true)
	{
		weapon.setTexture(uzi);
		damage = rand() % 25 + 11;
		
		
	}

	if(ak_choosen==true)
	{
		weapon.setTexture(ak);
		damage = rand() % 70 + 49;
	}

	if(usas_choosen==true)
	{
		weapon.setTexture(usas);
		damage = rand() % 20 + 39;
	}
	

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
                if(player_sprite.getPosition().y!=0)
                {
                    player_sprite.move(0, -player_speed);

					if(frame<20) player_sprite.setTexture(move1);
					if(frame>=20 && frame<40) player_sprite.setTexture(move2);
					if(frame>=40 && frame<60) player_sprite.setTexture(move3);
					if(frame>=60 && frame<80) player_sprite.setTexture(move4);
					if(frame>=80 && frame<100) player_sprite.setTexture(move5);
					if(frame>=100 && frame<120) player_sprite.setTexture(move4);
					if(frame>=120 && frame<140) player_sprite.setTexture(move3);
					//frame++;
					//if(frame>140) frame = 0;

					
                    
				}


	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
                if(player_sprite.getPosition().y!=768)
                {
                    player_sprite.move(0, player_speed);

					if(frame<20) player_sprite.setTexture(move1);
					if(frame>=20 && frame<40) player_sprite.setTexture(move2);
					if(frame>=40 && frame<60) player_sprite.setTexture(move3);
					if(frame>=60 && frame<80) player_sprite.setTexture(move4);
					if(frame>=80 && frame<100) player_sprite.setTexture(move5);
					if(frame>=100 && frame<120) player_sprite.setTexture(move4);
					if(frame>=120 && frame<140) player_sprite.setTexture(move3);
					//frame++;
					//if(frame>140) frame = 0;


                    
				}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
                if(player_sprite.getPosition().x!=0)
                {
                    player_sprite.move(-player_speed, 0);

					if(frame<20) player_sprite.setTexture(move1);
					if(frame>=20 && frame<40) player_sprite.setTexture(move2);
					if(frame>=40 && frame<60) player_sprite.setTexture(move3);
					if(frame>=60 && frame<80) player_sprite.setTexture(move4);
					if(frame>=80 && frame<100) player_sprite.setTexture(move5);
					if(frame>=100 && frame<120) player_sprite.setTexture(move4);
					if(frame>=120 && frame<140) player_sprite.setTexture(move3);
					//frame++;
					//if(frame>140) frame = 0;
                    
				}
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
                if(player_sprite.getPosition().x!=1024)
                {
                    player_sprite.move(player_speed, 0);

					if(frame<20) player_sprite.setTexture(move1);
					if(frame>=20 && frame<40) player_sprite.setTexture(move2);
					if(frame>=40 && frame<60) player_sprite.setTexture(move3);
					if(frame>=60 && frame<80) player_sprite.setTexture(move4);
					if(frame>=80 && frame<100) player_sprite.setTexture(move5);
					if(frame>=100 && frame<120) player_sprite.setTexture(move4);
					if(frame>=120 && frame<140) player_sprite.setTexture(move3);
					//frame++;
					//if(frame>140) frame = 0;
                    
				}
	}

	if(uzi_choosen == true)
	{
		if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
		{
				
			if(ammo_uzi_dynamic == 0 )
			{
				weapon_empty_sound.play();
			}
			
			
			if(ammo_uzi_dynamic > 0)
			{
				//if(frame==5 || frame==10 || frame==15 || frame==20 || frame==25 || frame==30 || frame==35 || frame==40 || frame==45 || frame==50 || frame==55 || frame==60 || frame==65 || frame==70 || frame==75 || frame==80 || frame==85 || frame==90 || frame==95 || frame==100 || frame==105 || frame==110 || frame==115 || frame==120 || frame==125 || frame==130 || frame==135 || frame==140)
				if(frame==7 || frame==14 || frame==21 || frame==28 || frame==35 || frame==42 || frame==49 || frame==56 || frame==63 || frame==70 || frame==77 || frame==84 || frame==91 || frame==98 || frame==105 || frame==112 || frame==119 || frame==126 || frame==133 || frame==140 )
				{
					bullet_count = bullet_count + 1;
					bullet_player[bullet_count].build_bullet(okno);
					bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
					weapon_sound_uzi.play();
					ammo_uzi_dynamic = ammo_uzi_dynamic - 1;
					weapon.setTexture(uzi_shot);

				}
			}
		}

	}

	if(ak_choosen == true)
	{
		if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
		{
				
			if(ammo_ak_dynamic == 0 )
			{
				weapon_empty_sound.play();
			}
			
			
			if(ammo_ak_dynamic > 0)
			{
				//if(frame==5 || frame==10 || frame==15 || frame==20 || frame==25 || frame==30 || frame==35 || frame==40 || frame==45 || frame==50 || frame==55 || frame==60 || frame==65 || frame==70 || frame==75 || frame==80 || frame==85 || frame==90 || frame==95 || frame==100 || frame==105 || frame==110 || frame==115 || frame==120 || frame==125 || frame==130 || frame==135 || frame==140)
				//if(frame==7 || frame==14 || frame==21 || frame==28 || frame==35 || frame==42 || frame==49 || frame==56 || frame==63 || frame==70 || frame==77 || frame==84 || frame==91 || frame==98 || frame==105 || frame==112 || frame==119 || frame==126 || frame==133 || frame==140 )
				if(frame==10 || frame==20 || frame==30 || frame==40 || frame==50 || frame==60 || frame==70 || frame==80 || frame==90 || frame==100 || frame==110 || frame==120 || frame==130 || frame==140 )
				{
					bullet_count = bullet_count + 1;
					bullet_player[bullet_count].build_bullet(okno);
					bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
					weapon_sound_ak.play();
					ammo_ak_dynamic = ammo_ak_dynamic - 1;
					weapon.setTexture(ak_shot);


				}
			}
		}

	}

	


	while(okno.pollEvent(event_anim_return))
	{
			if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::W)
            {
                player_sprite.setTexture(player_texture);
				
            }

            if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::A)
            {
                player_sprite.setTexture(player_texture);
            }

            if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::S)
            {
                player_sprite.setTexture(player_texture);
            }

            if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::D)
            {
                player_sprite.setTexture(player_texture);
            }

			if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::Num1)
            {
                deagle_choosen = true;
				uzi_choosen = false;
				ak_choosen = false;
				usas_choosen = false;

				ostringstream ss;
				ss << magazine_deagle;
				string str = ss.str();
				text.setString(str);

            }

			if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::Num2 && uzi_bought == true)
            {
                deagle_choosen = false;
				uzi_choosen = true;
				ak_choosen = false;
				usas_choosen = false;

				
				ostringstream ss;
				ss << magazine_uzi;
				string str = ss.str();
				text.setString(str);

            }

			if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::Num3 && ak_bought == true)
            {
                deagle_choosen = false;
				uzi_choosen = false;
				ak_choosen = true;
				usas_choosen = false;

				
				ostringstream ss;
				ss << magazine_ak;
				string str = ss.str();
				text.setString(str);

            }

			if(event_anim_return.type == sf::Event::KeyReleased && event_anim_return.key.code == sf::Keyboard::Num4 && usas_bought == true)
            {
                deagle_choosen = false;
				uzi_choosen = false;
				ak_choosen = false;
				usas_choosen = true;

				
				ostringstream ss;
				ss << magazine_usas;
				string str = ss.str();
				text.setString(str);

            }

			if(event_anim_return.type == sf::Event::KeyPressed && event_anim_return.key.code == sf::Keyboard::Escape)
			{
				level = false;
				menu = true;
				//okno.close();

			}

			if(event_anim_return.type == sf::Event::KeyPressed && event_anim_return.key.code == sf::Keyboard::R)
			{
				if(deagle_choosen == true && magazine_deagle>0 && ammo_deagle_dynamic != ammo_deagle_static)
				{
					ammo_deagle_dynamic = ammo_deagle_static;
					//magazine_deagle = magazine_deagle - 1;
					weapon_reload_sound.play();

					ostringstream ss;
					ss << magazine_deagle;
					string str = ss.str();
					text.setString(str);
				}

				if(uzi_choosen == true && magazine_uzi>0 && ammo_uzi_dynamic != ammo_uzi_static)
				{
					ammo_uzi_dynamic = ammo_uzi_static;
					magazine_uzi = magazine_uzi - 1;
					weapon_reload_sound.play();

					ostringstream ss;
					ss << magazine_uzi;
					string str = ss.str();
					text.setString(str);
				}

				if(ak_choosen == true && magazine_ak>0 && ammo_ak_dynamic != ammo_ak_static)
				{
					ammo_ak_dynamic = ammo_ak_static;
					magazine_ak = magazine_ak - 1;
					weapon_reload_sound.play();

					ostringstream ss;
					ss << magazine_ak;
					string str = ss.str();
					text.setString(str);
				}

				if(usas_choosen == true && magazine_usas>0 && ammo_usas_dynamic != ammo_usas_static)
				{
					ammo_usas_dynamic = ammo_usas_static;
					magazine_usas = magazine_usas - 1;
					weapon_reload_sound.play();

					ostringstream ss;
					ss << magazine_usas;
					string str = ss.str();
					text.setString(str);
				}
				
			}

			
			if(deagle_choosen == true)
			{
				
				
				
				
				
				if(event_anim_return.type == sf::Event::MouseButtonPressed && event_anim_return.mouseButton.button == sf::Mouse::Left)   //utworz pocisk - tutaj, poniewaz moze byc jeden event w klasie? funkcja musi w while w mainie
				{
					if(ammo_deagle_dynamic > 0)
					{
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						ammo_deagle_dynamic = ammo_deagle_dynamic - 1;
						weapon_sound_deagle.play();
						weapon.setTexture(deagle_shot);

					}

					if(ammo_deagle_dynamic == 0 )
					{
						weapon_empty_sound.play();
					}
				
				
				
				}
			}

			if(usas_choosen == true)
			{
				
				
				
				
				
				if(event_anim_return.type == sf::Event::MouseButtonPressed && event_anim_return.mouseButton.button == sf::Mouse::Left)   //utworz pocisk - tutaj, poniewaz moze byc jeden event w klasie? funkcja musi w while w mainie
				{
					if(ammo_usas_dynamic > 0)
					{
						
						
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						bullet_count = bullet_count + 1;
						bullet_player[bullet_count].build_bullet(okno);
						bullet_player[bullet_count].create_bullet(okno, player_sprite.getPosition().x, player_sprite.getPosition().y, angle, usas_choosen);
						
						ammo_usas_dynamic = ammo_usas_dynamic - 1;
						weapon_sound_usas.play();
						weapon.setTexture(usas_shot);
						cout<<bullet_count<<endl;

					}

					if(ammo_usas_dynamic == 0 )
					{
						weapon_empty_sound.play();
					}
				
				
				
				}
			}
		}
			
	}

	








void player::player_shot(sf::RenderWindow &okno, bullet bullet_player[], int &bullet_count, enemy *main_enemy, int &x, int &frame, float posx, float posy, int &y)		//poruszanie sie pocisku i wyswietlanie go - funkcja odpalana na koncu maina (zeby rysowalo)
{
	

			

	
	if(bullet_count>0)
	{
		
		for(int i = 1; i<=bullet_count; i++)
		{
			
			bullet_player[i].bullet_sprite.move(bullet_player[i].velocityx, bullet_player[i].velocityy);
			if(bullet_player[i].bullet_sprite.getPosition().x<0 || bullet_player[i].bullet_sprite.getPosition().x>1024 || bullet_player[i].bullet_sprite.getPosition().y<0 || bullet_player[i].bullet_sprite.getPosition().y>768 )   //kolizja z ekranem
			{
				if(i==1)
				{
					for(int i = 1; i<=bullet_count; i++)
					{
						swap(bullet_player[i], bullet_player[i+1]);
						//delete bullet_player[i];
					}
					bullet_count = bullet_count - 1;
				}

				if(i!=1)
				{
					for(int j = i; j<=bullet_count; j++)
					{
						swap(bullet_player[j], bullet_player[j+1]);
					}
					bullet_count = bullet_count - 1;
				}

			}
		}
	}  //koniec kolizji z ekranem



	
	if(x>0)
	{
		for(int i = 0; i<x; i++)
		{
			main_enemy[i].enemy_movement(frame, okno, posx, posy);
			for(int j = 1; j<=bullet_count; j++)
			{
				if(bullet_player[j].bullet_sprite.getPosition().x <= main_enemy[i].enemy_sprite.getPosition().x+25  && bullet_player[j].bullet_sprite.getPosition().x >= main_enemy[i].enemy_sprite.getPosition().x-25 && bullet_player[j].bullet_sprite.getPosition().y <= main_enemy[i].enemy_sprite.getPosition().y+25 && bullet_player[j].bullet_sprite.getPosition().y >= main_enemy[i].enemy_sprite.getPosition().y-25 && main_enemy[i].dead == false )
				{
					if(j==1 && i==0)
					{
						for(int j = 1; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						
						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += rand() % 30 + 1;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
					}

					if(j!=1 && i==0)
					{
						for(int j = i; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += rand() % 30 + 1;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}

						
					}

					if(j==1 && i!=0)
					{
						for(int j = 1; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += rand() % 30 + 1;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
						
					}

					if(j!=1 && i!=0)
					{
						for(int l = j; l<=bullet_count; l++)
						{
							swap(bullet_player[l], bullet_player[l+1]);
							
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += rand() % 30 + 1;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
					}




				}


			}

			
		}
	}
	//if(y==0)
	//{
	//	y=x;
	//	for(int i = 0; i<y; i++)
	//	{
	//		main_enemy[i].create_enemy();
	//	}
		
		
	//}
	
	





}

void player::player_draw_everything(sf::RenderWindow &okno, bullet bullet_player[], int &bullet_count, enemy *main_enemy, int &x, int &y, bool &level, bool &shop)
{
	if(x>0)
	{
		for(int j = 0; j<x; j++)
		{
			
			
			if(main_enemy[j].dead == true) okno.draw(main_enemy[j].enemy_sprite);
			
			
		}

		for(int j = 0; j<x; j++)
		{
			
			
			if(main_enemy[j].dead == false) okno.draw(main_enemy[j].enemy_sprite);
			
			
		}
	}

	if(bullet_count>0)
	{
		
		for(int i = 1; i<=bullet_count; i++)
		{
			okno.draw(bullet_player[i].bullet_sprite);
		}
	}

	if(y==0)
	{
		level = false;
		shop = true;
	}



}

void player::player_vs_enemy(sf::RenderWindow &okno, enemy *main_enemy, int &x, float posx, float posy, double &life_player)
{
	
	if(life_player < 1)
	{
		player_speed = 0;
	}
	
	
	for(int i = 0; i<x; i++)
	{
		if(main_enemy[i].dead == false && life_player>0)
		{
			if(main_enemy[i].enemy_sprite.getPosition().x <= posx+15 && main_enemy[i].enemy_sprite.getPosition().x >= posx-15 && main_enemy[i].enemy_sprite.getPosition().y <= posy+15 && main_enemy[i].enemy_sprite.getPosition().y >= posy-15)
			{
				life_player = life_player - 0.2;
			}
		}
	}

	double size = life_player/100;
	life_bar_sprite.setScale(size, 1);
}

//************************************************************************************BOSS 1*****************************************************************************

void player::player_shot(sf::RenderWindow &okno, bullet bullet_player[], int &bullet_count, enemy_boss_one *main_enemy, int &x, int &frame, float posx, float posy, int &y)		//poruszanie sie pocisku i wyswietlanie go - funkcja odpalana na koncu maina (zeby rysowalo)
{
	

			

	
	if(bullet_count>0)
	{
		
		for(int i = 1; i<=bullet_count; i++)
		{
			
			bullet_player[i].bullet_sprite.move(bullet_player[i].velocityx, bullet_player[i].velocityy);
			if(bullet_player[i].bullet_sprite.getPosition().x<0 || bullet_player[i].bullet_sprite.getPosition().x>1024 || bullet_player[i].bullet_sprite.getPosition().y<0 || bullet_player[i].bullet_sprite.getPosition().y>768 )   //kolizja z ekranem
			{
				if(i==1)
				{
					for(int i = 1; i<=bullet_count; i++)
					{
						swap(bullet_player[i], bullet_player[i+1]);
						//delete bullet_player[i];
					}
					bullet_count = bullet_count - 1;
				}

				if(i!=1)
				{
					for(int j = i; j<=bullet_count; j++)
					{
						swap(bullet_player[j], bullet_player[j+1]);
					}
					bullet_count = bullet_count - 1;
				}

			}
		}
	}  //koniec kolizji z ekranem



	
	if(x>0)
	{
		for(int i = 0; i<x; i++)
		{
			main_enemy[i].enemy_movement(frame, okno, posx, posy);
			for(int j = 1; j<=bullet_count; j++)
			{
				if(bullet_player[j].bullet_sprite.getPosition().x <= main_enemy[i].enemy_sprite.getPosition().x+50  && bullet_player[j].bullet_sprite.getPosition().x >= main_enemy[i].enemy_sprite.getPosition().x-50 && bullet_player[j].bullet_sprite.getPosition().y <= main_enemy[i].enemy_sprite.getPosition().y+50 && bullet_player[j].bullet_sprite.getPosition().y >= main_enemy[i].enemy_sprite.getPosition().y-50 && main_enemy[i].dead == false )
				{
					if(j==1 && i==0)
					{
						for(int j = 1; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						
						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
					}

					if(j!=1 && i==0)
					{
						for(int j = i; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}

						
					}

					if(j==1 && i!=0)
					{
						for(int j = 1; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
						
					}

					if(j!=1 && i!=0)
					{
						for(int l = j; l<=bullet_count; l++)
						{
							swap(bullet_player[l], bullet_player[l+1]);
							
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
					}




				}


			}

			
		}
	}
	//if(y==0)
	//{
	//	y=x;
	//	for(int i = 0; i<y; i++)
	//	{
	//		main_enemy[i].create_enemy();
	//	}
		
		
	//}
	
	





}

void player::player_draw_everything(sf::RenderWindow &okno, bullet bullet_player[], int &bullet_count, enemy_boss_one *main_enemy, int &x, int &y, bool &level, bool &shop)
{
	if(x>0)
	{
		for(int j = 0; j<x; j++)
		{
			
			
			if(main_enemy[j].dead == true) okno.draw(main_enemy[j].enemy_sprite);
			
			
		}

		for(int j = 0; j<x; j++)
		{
			
			
			if(main_enemy[j].dead == false) okno.draw(main_enemy[j].enemy_sprite);
			
			
		}
	}

	if(bullet_count>0)
	{
		
		for(int i = 1; i<=bullet_count; i++)
		{
			okno.draw(bullet_player[i].bullet_sprite);
		}
	}

	if(y==0)
	{
		level = false;
		shop = true;
	}



}

void player::player_vs_enemy(sf::RenderWindow &okno, enemy_boss_one *main_enemy, int &x, float posx, float posy, double &life_player)
{
	
	if(life_player < 1)
	{
		player_speed = 0;
	}
	
	
	for(int i = 0; i<x; i++)
	{
		if(main_enemy[i].dead == false && life_player>0)
		{
			if(main_enemy[i].enemy_sprite.getPosition().x <= posx+50 && main_enemy[i].enemy_sprite.getPosition().x >= posx-50 && main_enemy[i].enemy_sprite.getPosition().y <= posy+50 && main_enemy[i].enemy_sprite.getPosition().y >= posy-50)
			{
				life_player = life_player - 0.1;
			}
		}
	}

	double size = life_player/100;
	life_bar_sprite.setScale(size, 1);
}



//**************************************************************************************BOSS 2********************************************

void player::player_shot(sf::RenderWindow &okno, bullet bullet_player[], int &bullet_count, enemy_boss_two *main_enemy, int &x, int &frame, float posx, float posy, int &y)		//poruszanie sie pocisku i wyswietlanie go - funkcja odpalana na koncu maina (zeby rysowalo)
{
	

			

	
	if(bullet_count>0)
	{
		
		for(int i = 1; i<=bullet_count; i++)
		{
			
			bullet_player[i].bullet_sprite.move(bullet_player[i].velocityx, bullet_player[i].velocityy);
			if(bullet_player[i].bullet_sprite.getPosition().x<0 || bullet_player[i].bullet_sprite.getPosition().x>1024 || bullet_player[i].bullet_sprite.getPosition().y<0 || bullet_player[i].bullet_sprite.getPosition().y>768 )   //kolizja z ekranem
			{
				if(i==1)
				{
					for(int i = 1; i<=bullet_count; i++)
					{
						swap(bullet_player[i], bullet_player[i+1]);
						//delete bullet_player[i];
					}
					bullet_count = bullet_count - 1;
				}

				if(i!=1)
				{
					for(int j = i; j<=bullet_count; j++)
					{
						swap(bullet_player[j], bullet_player[j+1]);
					}
					bullet_count = bullet_count - 1;
				}

			}
		}
	}  //koniec kolizji z ekranem



	
	if(x>0)
	{
		for(int i = 0; i<x; i++)
		{
			main_enemy[i].enemy_movement(frame, okno, posx, posy);
			for(int j = 1; j<=bullet_count; j++)
			{
				if(bullet_player[j].bullet_sprite.getPosition().x <= main_enemy[i].enemy_sprite.getPosition().x+50  && bullet_player[j].bullet_sprite.getPosition().x >= main_enemy[i].enemy_sprite.getPosition().x-50 && bullet_player[j].bullet_sprite.getPosition().y <= main_enemy[i].enemy_sprite.getPosition().y+50 && bullet_player[j].bullet_sprite.getPosition().y >= main_enemy[i].enemy_sprite.getPosition().y-50 && main_enemy[i].dead == false )
				{
					if(j==1 && i==0)
					{
						for(int j = 1; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						
						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
					}

					if(j!=1 && i==0)
					{
						for(int j = i; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}

						
					}

					if(j==1 && i!=0)
					{
						for(int j = 1; j<=bullet_count; j++)
						{
							swap(bullet_player[j], bullet_player[j+1]);
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
						
					}

					if(j!=1 && i!=0)
					{
						for(int l = j; l<=bullet_count; l++)
						{
							swap(bullet_player[l], bullet_player[l+1]);
							
						}
						bullet_count = bullet_count - 1;

						//main_enemy[i].enemy_speed = 0;
						main_enemy[i].enemy_life = main_enemy[i].enemy_life - damage; 
						if(main_enemy[i].enemy_life<=0)
						{
							main_enemy[i].dead = true;
							y = y - 1;
							money += 800;
							ostringstream ss2;
							ss2 << money;
							string str2 = ss2.str();
							text2.setString(str2);
						}
						
					}




				}


			}

			
		}
	}
	//if(y==0)
	//{
	//	y=x;
	//	for(int i = 0; i<y; i++)
	//	{
	//		main_enemy[i].create_enemy();
	//	}
		
		
	//}
	
	





}

void player::player_draw_everything(sf::RenderWindow &okno, bullet bullet_player[], int &bullet_count, enemy_boss_two *main_enemy, int &x, int &y, bool &level, bool &shop)
{
	if(x>0)
	{
		for(int j = 0; j<x; j++)
		{
			
			
			if(main_enemy[j].dead == true) okno.draw(main_enemy[j].enemy_sprite);
			
			
		}

		for(int j = 0; j<x; j++)
		{
			
			
			if(main_enemy[j].dead == false) okno.draw(main_enemy[j].enemy_sprite);
			
			
		}
	}

	if(bullet_count>0)
	{
		
		for(int i = 1; i<=bullet_count; i++)
		{
			okno.draw(bullet_player[i].bullet_sprite);
		}
	}

	if(y==0)
	{
		level = false;
		shop = true;
	}



}

void player::player_vs_enemy(sf::RenderWindow &okno, enemy_boss_two *main_enemy, int &x, float posx, float posy, double &life_player)
{
	
	if(life_player < 1)
	{
		player_speed = 0;
	}
	
	
	for(int i = 0; i<x; i++)
	{
		if(main_enemy[i].dead == false && life_player>0)
		{
			if(main_enemy[i].enemy_sprite.getPosition().x <= posx+50 && main_enemy[i].enemy_sprite.getPosition().x >= posx-50 && main_enemy[i].enemy_sprite.getPosition().y <= posy+50 && main_enemy[i].enemy_sprite.getPosition().y >= posy-50)
			{
				life_player = life_player - 0.1;
			}
		}
	}

	double size = life_player/100;
	life_bar_sprite.setScale(size, 1);
}



	
	
	



