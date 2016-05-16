#include "bullet.h"
//#include "player.h"

void bullet::build_bullet(sf::RenderWindow &okno)
{
	bullet_texture.loadFromFile("pocisk.png");
	bullet_sprite.setTexture(bullet_texture);
	bullet_sprite.setPosition(100, 100);
	bullet_sprite.setOrigin(7.5, 7.5);
	
}


void bullet::create_bullet(sf::RenderWindow &okno, float posx, float posy, float angle, bool usas_choosen)
{
	
	if(usas_choosen == true)
	{
		speed = 30;
		bullet_angle = atan2(sf::Mouse::getPosition(okno).y - posy, sf::Mouse::getPosition(okno).x - posx);
		velocityx = (cos(bullet_angle)*speed) + (rand() % 25 - 12);
		velocityy = (sin(bullet_angle)*speed) + (rand() % 25 - 12);
		bullet_sprite.setPosition(posx, posy);
		bullet_sprite.setRotation(angle);
		bullet_sprite.move(velocityx, velocityy);
	}
	else
	{
		speed = 30;
		bullet_angle = atan2(sf::Mouse::getPosition(okno).y - posy, sf::Mouse::getPosition(okno).x - posx);
		velocityx = cos(bullet_angle)*speed;
		velocityy = sin(bullet_angle)*speed;
		bullet_sprite.setPosition(posx, posy);
		bullet_sprite.setRotation(angle);
		bullet_sprite.move(velocityx, velocityy);
	}
	
	
	
	
	

	

}



