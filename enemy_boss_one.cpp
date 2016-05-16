#include "enemy_boss_one.h"


#include "enemy.h"
#include "player.h"
#include "math.h"



void enemy_boss_one::create_enemy()
{
	
	int random;
	random = rand() % 4;
	enemy_texture.loadFromFile("enemy_boss_one.png");
	enemy_sprite.setTexture(enemy_texture);

	if(random == 0) enemy_sprite.setPosition(rand() % 1024, rand() % 2000 - 1999);
	if(random == 1) enemy_sprite.setPosition(rand() % 2000 + 1024, rand() % 768);
	if(random == 2) enemy_sprite.setPosition(rand() % 1024, rand() % 2000 + 768);
	if(random == 3) enemy_sprite.setPosition(rand() % 2000 - 1999, rand() % 768);
	enemy_sprite.setOrigin(75, 75);


	//enemy_move1.loadFromFile("enemy_move1.png");
    enemy_move2.loadFromFile("enemy_boss_one_move2.png");
    enemy_move3.loadFromFile("enemy_boss_one_move3.png");
    enemy_move4.loadFromFile("enemy_boss_one_move4.png");
    enemy_move5.loadFromFile("enemy_boss_one_move5.png");
	//dead_enemy.loadFromFile("dead_enemy.png");

	enemy_speed = 0.5;
	//enemy_speed = enemy_speed/10;
	enemy_life = 10000;
	dead = false;
}


void enemy_boss_one::enemy_movement(int &frame, sf::RenderWindow &okno, float posx, float posy)
{
	//enemy_speed = 1.2;
	
	if(dead==false)
	{
		if(frame > 80 && frame < 140)
		{
			enemy_speed = 2;
		}
		else
		{
			enemy_speed = 0.5;
		}


		enemy_angle = atan2(posy - enemy_sprite.getPosition().y, posx - enemy_sprite.getPosition().x);
		enemy_velocityx = cos(enemy_angle)*enemy_speed;
		enemy_velocityy = sin(enemy_angle)*enemy_speed;

	
		enemy_angle2 = atan2(posy - enemy_sprite.getPosition().y, posx - enemy_sprite.getPosition().x)* 180/3.14;

		enemy_sprite.setRotation(enemy_angle2);
		enemy_sprite.move(enemy_velocityx, enemy_velocityy);

			if(frame<20) enemy_sprite.setTexture(enemy_move2);
			if(frame>=20 && frame<40) enemy_sprite.setTexture(enemy_move3);
			if(frame>=40 && frame<60) enemy_sprite.setTexture(enemy_move4);
			if(frame>=60 && frame<80) enemy_sprite.setTexture(enemy_move5);
			if(frame>=80 && frame<100) enemy_sprite.setTexture(enemy_move4);
			if(frame>=100 && frame<120) enemy_sprite.setTexture(enemy_move3);
			if(frame>=120 && frame<140) enemy_sprite.setTexture(enemy_move2);
	}

	if(dead==true)
	{
		enemy_sprite.setTexture(dead_enemy);

	}

	





	//if(enemy_sprite.getPosition().x+15 <= posx+15 && enemy_sprite.getPosition().x-15 >= posx-15 && enemy_sprite.getPosition().y+15 <= posy+15 && enemy_sprite.getPosition().y-15 >= posy-15)
	//{

	
	

	 





}

void enemy_boss_one::spawn_enemy(enemy main_enemy[])
{
	for(int i = 0; i<10; i++)
	{
		main_enemy[i].create_enemy();
	}

}

void enemy_boss_one::draw_enemy(sf::RenderWindow &okno, enemy main_enemy[], float posx, float posy, int &frame)
{
	for(int i = 0; i<10; i++)
	{
		main_enemy[i].enemy_movement(frame, okno, posx, posy);
		okno.draw(main_enemy[i].enemy_sprite);
	}
}
