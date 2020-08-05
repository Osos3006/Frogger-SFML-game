#include<SFML/Graphics.hpp>
using namespace sf;
class pickup
{
private:
	RectangleShape pickupShape;
public:
	pickup();
	pickup(Texture texture);
	void drawPickup(RenderWindow window);
	void changeTexture(Texture new_texture);
	RectangleShape GetShape() const;

	~pickup();
};

