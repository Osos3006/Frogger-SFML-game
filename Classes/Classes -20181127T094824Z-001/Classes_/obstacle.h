#include <SFML/Graphics.hpp>
using namespace sf;
class obstacle
{
private:

RectangleShape obsShape;

public:

obstacle();
obstacle(Texture texture);
void drawObs (RenderWindow window);
void moveObs (int stepx, int stepy, Clock clock,int milliseconds);
void changeTexture(Texture new_texture);
RectangleShape GetShape() const;

~obstacle();
};
