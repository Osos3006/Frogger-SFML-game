#include<SFML/Graphics.hpp>
#include "frog.h" 
#include"obstacle.h"
#include"MainMenu.h"
#include"message.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace sf;
using namespace std;
int const rows = 13;
int const cols = 20;
int const rowslog = 10; ////////////////////
int const colslog = 10;////////////////
int const tile_size = 50;

Clock carC;
Clock log1C;
Clock log2C;
Text Level_Name;
Text lives;
Font font;
RectangleShape flag_win;
bool game_End = false;
#define step 50
#define number_of_cars 7
#define number_of_turtles 7
#define number_of_logs 6
#define number_of_CarRows 3
#define number_of_LogRows 2
#define number_of_turtleRows 2


obstacle cars[3][number_of_cars];
obstacle turtles[2][number_of_turtles];
obstacle logs[2][number_of_logs];
/*obstacle Red_Car[number_of_cars];
obstacle Blue_Car[number_of_cars];
obstacle Orange_Car[number_of_cars];
obstacle Turtles_1[number_of_turtles];
obstacle Turtles_2[number_of_turtles];*/

RectangleShape tunnels[number_of_CarRows], tunnels1[number_of_CarRows], bridges[4],bridges1[4];

MainMenu menu(600, 600);

frog Frog(3, 0);    ////////////////

ifstream background;
Texture land, water, street, tunnel, carR, carB, carO, Turtle, frog_pic, Log, flag_texture, bridge;




int x1;
RenderWindow window;
RenderWindow Menu_window;
RectangleShape A[rows][cols];
message gameOver("sansation.ttf");
message win("Sansation.ttf");
RectangleShape B[rowslog][colslog];
RectangleShape frogShape;       ////////////////
void level_One();
void handle(RenderWindow &window, RenderWindow& Menu_window, frog & Frog, MainMenu&menu);
void Menu();
//void MoveObs(int, Clock, int);
void check_situation(frog &Frog)
{
	//if (Frog.getfrogpositiony() <= 400 && Frog.getfrogpositiony() < 550)
	//{

	for (int i = 0; i < number_of_CarRows; i++)
		for (int j = 0; j < number_of_cars; j++)
		{

			if (Frog.intersect_obs(cars[i][j].GetShape()))
			{
				Frog.dec_lives();
				Frog.setfrogposition(550, 700);

				//lives.setString("Lives " + std::to_string(Frog.getlives()));
				if (Frog.getlives() == 0)
				{
					Frog.setalive(false);
				}
			}

		}

	//}
	//else
	//{
	bool flag = false;
	//if (Frog.getfrogpositiony() <= 150 && Frog.getfrogpositiony() < 350)
	//{
	for (int i = 0; i < number_of_turtleRows; i++)
		for (int j = 0; j < number_of_turtles; j++)
			if (Frog.intersect_obs(turtles[i][j].GetShape()))
			{
				Frog.setfrogposition(turtles[i][j].getPositionX(), turtles[i][j].getPositionY());
				flag = true;
				if (Frog.getfrogpositionx() >= 1000 || Frog.getfrogpositionx() <= 150)
				{
					Frog.setfrogposition(550, 700);
					Frog.dec_lives();
					if (Frog.getlives() == 0)
					{
						Frog.setalive(false);
					}
				}
			}
	//	if (!flag)
		//{
	for (int i = 0; i < number_of_LogRows; i++)
		for (int j = 0; j < number_of_logs; j++)
			if (Frog.intersect_obs(logs[i][j].GetShape()))
			{
				Frog.setfrogposition(logs[i][j].getPositionX(), logs[i][j].getPositionY());
				flag = true;
				if (Frog.getfrogpositionx() >= 1000 || Frog.getfrogpositionx() <= 200)
				{
					Frog.setfrogposition(550, 700);
					Frog.dec_lives();
					if (Frog.getlives() == 0)
					{
						Frog.setalive(false);
					}
				}
			}
	//}

	if (!flag && Frog.getfrogpositiony() > 150 && Frog.getfrogpositiony() < 350)
	{

		Frog.dec_lives();
		Frog.setfrogposition(550, 700);
		if (Frog.getlives() == 0)
		{
			Frog.setalive(false);
		}

	}
	
}
  

//	}





int main()
{
	if (!font.loadFromFile("sansation.ttf"))
		cout << "error font not loaded";
	Level_Name.setString("Level 1");
	Level_Name.setFillColor(Color::Red);
	Level_Name.setFont(font);
	Level_Name.setPosition(10, 25);
	lives.setString("Lives " + std::to_string(Frog.getlives()));
	lives.setFillColor(Color::Red);
	lives.setFont(font);
	lives.setPosition(1000, 25);
	Menu();

}
void handle(RenderWindow &window, RenderWindow& Menu_window, frog & Frog, MainMenu&menu)
{
	Event event;
	while (Menu_window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			Menu_window.close();
			break;
		case Event::KeyReleased:
			switch (event.key.code)
			{
			case Keyboard::Up:
				menu.MoveUp();
				break;
			case Keyboard::Down:
				menu.MoveDown();
				break;
			case Keyboard::Return:
				switch (menu.getSelected())
				{
				case 0:
					std::cout << " Start Pressed " << std::endl;
					Menu_window.close();
					level_One();
					break;
				case 1:
					std::cout << " options Pressed " << std::endl;
					break;
				case 2:
					std::cout << " HighScores Pressed " << std::endl;
					break;
				case 3:
					Menu_window.close();
					break;
				}
				break;
			}
		}
	}
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			
				switch (event.key.code)
				{
					
				case Keyboard::Down:
				case Keyboard::S:
					if(!game_End)
					Frog.move_down(window);
					break;
				case Keyboard::Up:
				case Keyboard::W:
					if (!game_End)
					Frog.move_up(window);
					break;
				case Keyboard::Right:
				case Keyboard::D:
					if (!game_End)
					Frog.move_right(window);
					break;
				case Keyboard::Left:
				case Keyboard::A:
					if (!game_End)
					Frog.move_left(window);
					break;
			
				case Keyboard::Escape:
					window.close();
					Menu();
					break;

				}
			
			//check_situation(Frog);
			//lives.setString("Lives " + std::to_string(Frog.getlives()));
			break;
		}
	}



}
void level_One()
{
	game_End = false;
	window.create(VideoMode(1200, 850), "Frogger!!");


	if (!flag_texture.loadFromFile("flag.png"))
		cout << "error flag.jpg";
	if (!carR.loadFromFile("RedCar.png"))
		cout << "error RedCar.jpg";
	if (!Turtle.loadFromFile("Turttle.png"))
		cout << "error Turtle.jpg";
	if (!carO.loadFromFile("CarOrange.png"))
		cout << "error CarOrange.jpg";
	if (!carB.loadFromFile("BlueCar.png"))
		cout << "error BlueCar.jpg";
	if (!land.loadFromFile("sand2.jpg"))
		cout << "error Sand2.jpg";
	if (!water.loadFromFile("blue1.jpg"))
		cout << "error blue1.jpg";
	if (!street.loadFromFile("street5.jpg"))
		cout << "error street5.jpg";
	if (!tunnel.loadFromFile("tunnel.png"))
	cout << "error tunnel.png";
	//Frog.setfrogtexture(&frog_pic);
	if (!frog_pic.loadFromFile("frog3.png"))
		cout << "error frog2.png";     ////////////
	if (!bridge.loadFromFile("bridge1.png"))
		cout << "error bridge.png";
	if (!Log.loadFromFile("log.png"))
		cout << "error log.png";
	//Frog.getfrogShape().setTexture(&frog_pic); ///////////////
	Frog.setfrogtexture(frog_pic);
	Frog.setlives(3);
	Frog.setalive(true);
	Frog.setfrogposition(550, 700);
	Frog.setfrogsize(50, 50);
	flag_win.setSize(Vector2f(50, 50));
	flag_win.setPosition(600, 100);
	flag_win.setTexture(&flag_texture);

	for (int i = 0; i < number_of_CarRows; i++)
	{
		tunnels[i].setTexture(&tunnel);
		tunnels1[i].setTexture(&tunnel);

		tunnels[i].setPosition(100, 400 +(i*50));
		tunnels1[i].setPosition(1050, 400 +(i*50));

		tunnels[i].setSize(Vector2f(50, 50));
		tunnels1[i].setSize(Vector2f(50, 50));

	}

	for (int i = 0; i < 4; i++)
	{
		bridges[i].setTexture(&bridge);
		bridges1[i].setTexture(&bridge);

		bridges[i].setPosition(100, 150 + (i * 50));
		bridges1[i].setPosition(1050, 150 + (i * 50));

		bridges[i].setSize(Vector2f(50, 50));
		bridges1[i].setSize(Vector2f(50, 50));

	}



	int x = 125;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < number_of_cars; j++)
		{
			cars[i][j].setSize(50, 40);
			switch (i)
			{
			case 0:
				cars[i][j].setTexture(carR);
				cars[i][j].setPosition(x+30, 400);
				break;
			case 1:
				cars[i][j].setTexture(carB);
				cars[i][j].setPosition(x+70, 455);
				break;
			case 2:
				cars[i][j].setTexture(carO);
				cars[i][j].setPosition(x, 510);
				break;

			}
			x += 80 + (20 * j);
			
		}
		x = 125;
	}

	x = 125;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < number_of_turtles; j++)
		{
			turtles[i][j].setSize(40, 40);
			turtles[i][j].setTexture(Turtle);


			switch (i)
			{
			case 0:
				turtles[i][j].setPosition(x, 150);

				break;
			case 1:
				turtles[i][j].setPosition(x, 250);
				break;
			}
			x += 75 + (20 * j);

		}
		x = 125;

	}


	x = 125;


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < number_of_logs; j++)
		{
			logs[i][j].setSize(70, 40);
			logs[i][j].setTexture(Log);


			switch (i)
			{
			case 0:
			{
				logs[i][j].setPosition(x, 200);
				x += 90 + (30 * j);
			}
			break;
			case 1:
			{
				logs[i][j].setPosition(x, 300);
				x += 70 + (30 * j + 40);
			}
			break;
			}
			//x += 50 + (20 * j);


		}
		x = 125;


	}
	/*Red_Car[i].setSize(50, 40);
	Red_Car[i].setTexture(carR);
	Red_Car[i].setPosition(x, 400);
	Blue_Car[i].setSize(50, 40);
	Blue_Car[i].setTexture(carB);
	Blue_Car[i].setPosition(x, 455);
	Orange_Car[i].setSize(50, 40);
	Orange_Car[i].setTexture(carO);
	Orange_Car[i].setPosition(x, 510);
	Turtles_1[i].setSize(60, 60);
	Turtles_1[i].setTexture(Turtle);
	Turtles_1[i].setPosition(x, 160);
	Turtles_2[i].setSize(60, 60);
	Turtles_2[i].setTexture(Turtle);
	Turtles_2[i].setPosition(x, 260);*/

	//Frog.getfrogShape().setPosition(550, 700); /////////////
	//Frog.getfrogShape().setSize(Vector2f(50, 50)); ////////////////


	background.open("background.txt");
	if (background.is_open())
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
			{
				if (!background.eof())
					background >> x1;

				A[i][j].setPosition(j*tile_size + 100, i*tile_size + 100);
				A[i][j].setSize(Vector2f(tile_size, tile_size));

				switch (x1)
				{
				case 0:
					A[i][j].setTexture(&land);
					break;
				case 1:
					A[i][j].setTexture(&water);
					break;
				case 2:
					A[i][j].setTexture(&street);
					break;

				}
			}
	}

	background.close();



	while (window.isOpen())
	{


		window.clear();


		handle(window, Menu_window, Frog, menu);
		
		//if (carC.getElapsedTime().asMilliseconds() >= 600)
		//{
			

		//}
		lives.setString("Lives " + std::to_string(Frog.getlives()));

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				window.draw(A[i][j]);



		for (int i = 0; i < number_of_CarRows; i++)
		{
			for (int j = 0; j < number_of_cars; j++)
			{
				cars[i][j].drawObs(window);
				
			}
			window.draw(tunnels[i]);
			window.draw(tunnels1[i]);
		}

		
	
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < number_of_turtles; j++)
				turtles[i][j].drawObs(window);

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < number_of_logs; j++)
				logs[i][j].drawObs(window);

		for (int i = 0; i < 4; i++)
		{
			window.draw(bridges[i]);
			window.draw(bridges1[i]);
		}


		if (carC.getElapsedTime().asMilliseconds() >= 600)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < number_of_cars; j++)
				{
					cars[i][j].moveObs(30);

					if (cars[i][j].getPositionX() >= 1050)
					{
						cars[i][j].setPosition(155, cars[i][j].getPositionY());
					}

					carC.restart();

				}
					check_situation(Frog);
				

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < number_of_turtles; j++)
				{
					switch (i)
					{
					case 0:
					{
						turtles[i][j].moveObs(-20);
						if (turtles[i][j].getPositionX() < 115)
							turtles[i][j].setPosition(1015, turtles[i][j].getPositionY());
					}

					break;

					case 1:
					{
						turtles[i][j].moveObs(-35);
						if (turtles[i][j].getPositionX() < 115)
						turtles[i][j].setPosition(1015, turtles[i][j].getPositionY());
					}
					break;

					}
					check_situation(Frog);


					/*if (turtles[i][j].getPositionX() <= 80)

					turtles[i][j].setPosition(1000, turtles[i][j].getPositionY());*/



				}

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < number_of_logs; j++)
				{
					switch (i)
					{
					case 0:

						logs[i][j].moveObs(30);


						break;

					case 1:

						logs[i][j].moveObs(40);

						break;

					}


					if (logs[i][j].getPositionX() > 900)

						logs[i][j].setPosition(125, logs[i][j].getPositionY());



				}

			check_situation(Frog);

			//window.draw(Frog.getfrogShape());             ///////
		}
			Frog.drawfrog(window);  ///////////
			window.draw(Level_Name);
			window.draw(flag_win);
			window.draw(lives);
			if (!Frog.getalive())
			{
				gameOver.printGameOver(window, 450, 30);
			}
			if (Frog.getalive() && Frog.getfrogpositiony() < 150)
			{
				win.printWin(window, 350, 30);
				game_End = true;
			}

			window.display();
		


	}

}

void Menu()
{
	Menu_window.create(VideoMode(600, 600), "Menu test");



	while (Menu_window.isOpen())
	{
		Menu_window.clear(Color::Black);
		menu.createMenu(Menu_window);
		handle(window, Menu_window, Frog, menu);
		Menu_window.display();
	}
}
void moveObs(int stepx, RectangleShape & obsShape, Clock clock, int ms)
{
	if (clock.getElapsedTime().asMilliseconds() >= ms)
	{
		obsShape.move(stepx, 0);
	}

}
