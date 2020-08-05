#include "obstacle.h"

obstacle::obstacle()
{
	obsShape.setSize(Vector2f(50, 50));
}

obstacle::obstacle(Texture texture)
{
	obsShape.setSize(Vector2f(50, 50));
	obsShape.setTexture(&texture);
}

RectangleShape obstacle:: GetShape() const
{
	return obsShape;
}

void obstacle::drawObs(RenderWindow window)
{
	window.draw(obsShape);
}

void obstacle::moveObs( int stepx, int stepy, Clock clock, int ms)
{
	if (clock.getElapsedTime().asMilliseconds() >= ms)
	{
		obsShape.move(stepx, stepy);
	}

}

void obstacle::changeTexture(Texture new_texture)
{
	obsShape.setTexture(&new_texture);
}


obstacle::~obstacle()
{
}
