
#ifndef frog_h
#define frog_h
#include <SFML/Graphics.hpp>
using namespace sf;
class frog
{
private:

	RectangleShape frogShape;
	Texture frog_pic;
	int score;
	int lives;    // will be initialized and decremented in main func
	bool alive = true;

public:
	frog(int, int);
	void setfrogtexture(Texture&frog_pic);
	void drawfrog(RenderWindow&, RectangleShape&);
	void movefrog(RectangleShape&frogshape);
	RectangleShape getfrogShape() const;
	void setalive(bool alive);
	bool getalive() const;
	void setlives(int lives);
	int getlives() const;
	void setscore(int score);
	int getscore()const;
	bool intersect_obs( RectangleShape);
	bool intersect_pick( RectangleShape);
	~frog();
};
#endif;

//i didn't add seperate intersection function with car, as all causes of death will be handled in the main function (car, water,bounds of window), also intersection func with obs will return true anyways.
