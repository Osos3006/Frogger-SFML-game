#include "pickup.h"

pickup::pickup()
{
	pickupShape.setSize(Vector2f(50, 50));
}

pickup::pickup(Texture texture)
{
	pickupShape.setSize(Vector2f(50, 50));
	pickupShape.setTexture(&texture);
}

RectangleShape pickup::GetShape() const
{
	return pickupShape;
}

void pickup::drawPickup(RenderWindow window)
{
	window.draw(pickupShape);
}

void pickup::changeTexture(Texture new_texture)
{
	pickupShape.setTexture(&new_texture);
}

pickup::~pickup()
{
}
