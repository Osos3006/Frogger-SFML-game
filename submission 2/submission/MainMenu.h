#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
using namespace sf;
#define Max_items 4
class MainMenu
{
private:
	        int index_selected;
			Texture optionspictures[4];
			Text option[Max_items];
			Font font;

public:
	MainMenu(int,int);
	void createMenu(RenderWindow&window);
	void MoveUp();
	void MoveDown();
	int getSelected() const;
	//void handleEvents(RenderWindow& window);
	~MainMenu();
};

