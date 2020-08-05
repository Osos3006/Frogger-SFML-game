#include "message.h"
#include<string>
#include<iostream>

message::message()
{

}
message::message(String font)
{
	if (MsgFont.loadFromFile(font))
	{
		Msg.setFont(MsgFont);
		Msg.setFillColor(Color::White);
		Msg.setCharacterSize(30);
		Msg.setStyle(Text::Bold);
	}
}
void message::printGameOver(RenderWindow& window,int x,int y)
{
	Msg.setString("Game Over !!");
	Msg.setPosition(x, y);
	window.draw(Msg);
}
Text message :: getText() const
{
	return Msg;
}
void message::printWin(RenderWindow& window, int x, int y)
{
	Msg.setString("Congratulations Froogy ! You Won !!");
	Msg.setPosition(x, y);
	window.draw(Msg);
}
void message::printExit(RenderWindow& window, int x, int y)
{
	Msg.setString("Are You Sure that You Want to Exit? coward?");
	Msg.setPosition(x, y);
	window.draw(Msg);
}
void message::printScore(RenderWindow& window, int x, int y, int score)
{
	Msg.setString("Score"+ std::to_string(score));
	Msg.setPosition(x, y);
	window.draw(Msg);
}


message::~message()
{
}
