#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	// ������ ������ X �� X � �������� ���������� 60 FPS
	sf::RenderWindow window(sf::VideoMode(705, 705), "Tiles Game");
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("fonts/calibrib.ttf");
	// ����� � �������
	sf::Text text("F2 - New Game | Esc - Exit | Arrow keys - Move tiles", font, 20);
	text.setFillColor(sf::Color::Blue);
	text.setPosition(50.f, 5.f);

	// ������� ������ ����
	Game game;
	game.setPosition(50.f, 50.f);

	sf::Event event;
	int move_counter = 0;	// ������� ��������� ����� ��� ������������� �����������

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// �� ��� �� �������, ����� �� ������ ���������, Esc
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);
				// ����� ��������� �� ���� F2
				if (event.key.code == sf::Keyboard::F2)
				{
					game.Init();		// ��� ������ ����� ��������� �� ���������� ��������� ���������
					move_counter = 100;	// ��� ���������� ��������� ��� ���������
				}
			}
		}

		// ���� ������� ����� ������ ����, ���������� �������� �����������
		if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

		// ������ ������� ��������� ������, � ������ �����
		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}