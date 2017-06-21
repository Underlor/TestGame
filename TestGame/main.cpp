#include "Engine.h"
#include <SFML/Graphics.hpp>
const int ground = 150;
const int H = 12;
const int W = 40;
const int SizeW = 1024;
const int SizeH = 640;
float offsetx = 0;
float offsety = 0;
using namespace sf;

class Player
{
public:
	float dx, dy;
	FloatRect Rect;
	bool onGround;
	Sprite sprite;
	float CurrentFrame;
	Player(Texture &image)
	{
		sprite.setTexture(image);
		Rect = FloatRect(0, 0, 40, 50);
		sprite.setTextureRect(IntRect(0, 244, 40, 50));
		dx = dy = 0;
		Rect.top = 50;
		Rect.left = 50;
		sprite.setPosition(150, 50);
		CurrentFrame = 0;
	}
	//void Collision(int);

	void update(float time)
	{
		Rect.left += dx*time;
		//Collision(0);
		if (!onGround) dy = dy+ 0.0005 * time;
		Rect.top += dy*time;
		onGround = false;
		//Collision(1);
		//if (Rect.top > ground) { Rect.top = ground; dy = 0; onGround = true; };
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 6) CurrentFrame -= 6;
		if (dx > 0)	sprite.setTextureRect(IntRect(40 * int(CurrentFrame), 244, 40, 50));
		if (dx < 0)	sprite.setTextureRect(IntRect(40 * int(CurrentFrame)+40, 244, -40, 50));
		sprite.setPosition(Rect.left - offsetx, Rect.top - offsety);
		dx = 0;
	}
private:

};


int main()
{
	KeyboardListener *KeyListen = new KeyboardListener();
	RenderWindow window(sf::VideoMode(SizeW, SizeH), GameName);
	CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	Map TileMap("Map.ini");
	Texture t;
	t.loadFromFile("sprites\\fang.png");
	Player p(t);
	float CurrentFrame = 0;
	Clock clock;
	RectangleShape rectangle;
	rectangle.setSize(Vector2f(32, 32));

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 300; //скорость игры
		sf::Event event;
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			p.dx = -0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			p.dx = 0.1;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{

		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (p.onGround) { p.dy = -0.4; p.onGround = false; }
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();// Временно потом будет меню...
			}
		}
		
		p.update(time);
		if(p.Rect.left > SizeW/2)offsetx = p.Rect.left- SizeW / 2;
		if(p.Rect.top > SizeH/2)offsety = p.Rect.top-SizeH/2;
		window.clear();
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'B') rectangle.setFillColor(Color::White);
				else
					if (TileMap[i][j] == '0') rectangle.setFillColor(Color::Green);
					else
				if (TileMap[i][j] == ' ') continue;
				rectangle.setPosition(j * 32 - offsetx, i * 32 - offsety);
				window.draw(rectangle);
			}

		}
		//window.draw(shape);
		window.draw(p.sprite);
		window.display();
	}

	return 0;
} 
//
//void Collision(int dir)
//{
//	for (size_t i = Rect.top / 32; i < (Rect.top + Rect.height) / 32; i++)
//	{
//		for (size_t j = Rect.left / 32; j < (Rect.left + Rect.width) / 32; j++)
//		{
//			if (TileMap[i][j] == 'B')
//			{
//				if (dx > 0 && dir == 0) Rect.left = j * 32 - Rect.width;
//				if (dx < 0 && dir == 0) Rect.left = j * 32 + 32;
//				if (dy > 0 && dir == 1) { Rect.top = i * 32 - Rect.height; dy = 0; onGround = true; }
//				if (dy < 0 && dir == 1) { Rect.top = i * 32 + 32; dy = 0; }
//			}
//			if (TileMap[i][j] == '0')
//			{
//				TileMap[i][j] = ' ';
//			}
//		}
//	}
//}