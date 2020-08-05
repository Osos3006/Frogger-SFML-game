#include "MainMenu.h"



MainMenu::MainMenu(int w , int h)
{
	if (!font.loadFromFile("sansation.ttf"))
	{
		std::cout << "failed to load menu font";
	}
	option[0].setFont(font);
	option[0].setFillColor(Color::Red);
	option[0].setString("Start");
	option[0].setPosition(Vector2f(w / 2, h / (Max_items + 1) * 1));

	option[1].setFont(font);
	option[1].setFillColor(Color:: Black);
	option[1].setString("Options");
	option[1].setPosition(Vector2f(w / 2, h / (Max_items + 1) * 2));

	option[2].setFont(font);
	option[2].setFillColor(Color:: Black);
	option[2].setString("HighScores");
	option[2].setPosition(Vector2f(w / 2, h / (Max_items + 1) * 3));

	option[3].setFont(font);
	option[3].setFillColor(Color:: Black);
	option[3].setString("Exit");
	option[3].setPosition(Vector2f(w / 2, h / (Max_items + 1) * 4));

	index_selected = 0;
}
void MainMenu::createMenu(RenderWindow& window)
{
	for (int i = 0; i < Max_items; i++)
		window.draw(option[i]);
}
void MainMenu::MoveUp()
{
	if (index_selected - 1 >= 0)
	{
		option[index_selected].setFillColor(Color::Black);
		index_selected--;
		option[index_selected].setFillColor(Color::Red);
	}
}
void MainMenu::MoveDown()
{
	if (index_selected + 1 < Max_items )
	{
		option[index_selected].setFillColor(Color:: Black);
		index_selected++;
		option[index_selected].setFillColor(Color::Red);
	}
}
int MainMenu::getSelected() const
{
	return index_selected;
}
MainMenu::~MainMenu()
{
}
/*
Event even
while( window.pollEvent(event)
{
switch (event.type)
{
case:: Event:: KeyReleased:
switch(event.key.code)
{
case Keyboard::Up:
menu.MoveUp();
break
case Keyboard::Down:
menu.MoveDown();
break;
case Keyboard::Return:
switch(menu.getSelected())
{
case 0:
std::cout<<" Start Pressed " << std::endl;
break;
case 1:
std::cout<<" options Pressed " << std::endl;
break;
case 2:
std::cout<<" HighScores Pressed " << std::endl;
break;
case 3:
window.close();
break;
}
break;
}

*/