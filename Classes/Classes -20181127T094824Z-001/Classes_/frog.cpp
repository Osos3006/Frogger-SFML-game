#include "frog.h"                     
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;


frog::frog(int s, int l)
{
	score = s;
	lives = l;
}

frog::~frog()
{
}
void frog::setfrogtexture(Texture&frog_pic)
{
	if (alive)
	{
		if (!frog_pic.loadFromFile("frog.jpg"))
			std::cout << "frog texture not loaded" << std::endl;
		frogShape.setTexture(&frog_pic);
	}
}
void frog::drawfrog(RenderWindow & window, RectangleShape &frogshape)
{
	if (alive)
		window.draw(frogshape);
}
void frog::movefrog(RectangleShape&frogshape)
{
	int step = 10;
	if (alive)
	{
		Event event;

		switch (event.key.code)
		{
		case Keyboard::Down:
			frogshape.move(0, step);
			break;
		case Keyboard::Up:
			frogshape.move(0, -step);
			break;
		case Keyboard::Right:
			frogshape.move(step, 0);
			break;
		case Keyboard::Left:
			frogshape.move(-step, 0);
			break;
		}
	}


}
RectangleShape frog::getfrogShape() const
{
	return  frogShape;
}
void frog::setalive(bool alive)
{
	alive = true;
}
bool frog::getalive() const
{
	return alive;
}
void frog::setlives(int l)
{
	lives = l;
}
int frog::getlives() const
{
	return lives;
}
void frog::setscore(int s)
{
	score = s;
}
int frog::getscore()const
{
	return score;
}
bool frog::intersect_obs(RectangleShape obsShape)
{
	if (frogShape.getGlobalBounds().intersects(obsShape.getGlobalBounds()))
		return true;
	else
		return false;
}
bool frog::intersect_pick(RectangleShape pickupShape)
{
	if (frogShape.getGlobalBounds().intersects(pickupShape.getGlobalBounds()))
		return true;
	else
		return false;
}
