#ifndef frog_h
#define frog_h
#include <SFML/Graphics.hpp>
using namespace sf;
class frog
{
private:

	RectangleShape frogShape;
	Texture frog_pic;
	int step = 50;
	int score;
	int lives;    // will be initialized and decremented in main func
	bool alive = true;

public:
	frog();
	frog(int, int);
	void setfrogtexture(Texture&frog_pic);
	void setfrogsize(int frogsizex, int frogsizey);
	void setfrogposition(int frogx, int frogy);
	int getfrogpositionx() const;
	int getfrogpositiony() const;
	void drawfrog(RenderWindow&);
	void move_up(RenderWindow& window);
	void move_down(RenderWindow& window);
	void move_right(RenderWindow& window);
	void move_left(RenderWindow& window);
	void setalive(bool alive);
	bool getalive() const;
	void setlives(int lives);
	int getlives() const;
	void inc_score();
	void dec_lives();
	void inc_lives();
	void setscore(int score);
	int getscore()const;
	bool intersect_obs(RectangleShape);
	bool intersect_pick(RectangleShape);
	~frog();
};
#endif

//i didn't add seperate intersection function with car, as all causes of death will be handled in the main function (car, water,bounds of window), also intersection func with obs will return true anyways.

