#include "Game.h"
Game::Game()
{
	// Çàãðóæàåì øðèôò èç ïàïî÷êè fonts, ñïàñèáî Source Engine çà òî, ÷òî ïðèó÷èë ìåíÿ âñå ðàñêèäûâàòü ïî îòäåëüíûì ïàïî÷êàì
	font.loadFromFile("fonts/calibrib.ttf");
	Init();
}

void Game::Init()
{
	// Çàëèâàåì ìàññèâ ñ ïëàøå÷êàìè
	for (int i = 0; i < ARRAY_SIZE - 1; i++) elements[i] = i + 1;
	empty_index = ARRAY_SIZE - 1;	// Ïóñòàÿ ïëàøêà (øïåéîí) — â ïîñëåäíåì ýëåìåíòå ìàññèâà
	elements[empty_index] = 0;	// Ïóñòàÿ ïëàøêà èìååò çíà÷åíèå = 0
	solved = true;
}

bool Game::Check()
{
	// Ñîáðàíà ëè ãîëîâîëîìêà? (Check (îò àíãë.) — ïðîâåðÿòü, ïðîâåðêà)
	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		if (elements[i] > 0 && elements[i] != i + 1) return false;
	}
	return true;
}

void Game::Move(Direction direction)
{
	// Êàêàÿ ïëàøêà ïóñòàÿ???????
	int col = empty_index % SIZE;
	int row = empty_index / SIZE;

	// Ïîèñê ïîäõîäÿùåé ïëàøêè
	int move_index = -1;
	if (direction == Direction::Left && col < (SIZE - 1)) move_index = empty_index + 1;
	if (direction == Direction::Right && col > 0) move_index = empty_index - 1;
	if (direction == Direction::Up && row < (SIZE - 1)) move_index = empty_index + SIZE;
	if (direction == Direction::Down && row > 0) move_index = empty_index - SIZE;

	// Ïåðåìåùåíèå ïëàøêè íà ñâîáîäíîå ìåñòî
	if (empty_index >= 0 && move_index >= 0)
	{
		int tmp = elements[empty_index];
		elements[empty_index] = elements[move_index];
		elements[move_index] = tmp;
		empty_index = move_index;
	}
	solved = Check();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 200);

	sf::Texture arrayTexture[15];
	sf::Sprite image_Texture;
	if (SIZE == 2)
	{
		arrayTexture[0].loadFromFile("materials/SIZE2/image_part_001.jpg");
		arrayTexture[1].loadFromFile("materials/SIZE2/image_part_002.jpg");
		arrayTexture[2].loadFromFile("materials/SIZE2/image_part_003.jpg");
	}
	if (SIZE == 3)
	{
		arrayTexture[0].loadFromFile("materials/SIZE3/image_part_001.jpg");
		arrayTexture[1].loadFromFile("materials/SIZE3/image_part_002.jpg");
		arrayTexture[2].loadFromFile("materials/SIZE3/image_part_003.jpg");
		arrayTexture[3].loadFromFile("materials/SIZE3/image_part_004.jpg");
		arrayTexture[4].loadFromFile("materials/SIZE3/image_part_005.jpg");
		arrayTexture[5].loadFromFile("materials/SIZE3/image_part_006.jpg");
		arrayTexture[6].loadFromFile("materials/SIZE3/image_part_007.jpg");
		arrayTexture[7].loadFromFile("materials/SIZE3/image_part_008.jpg");
	}
	if (SIZE == 4)
	{
		arrayTexture[0].loadFromFile("materials/SIZE4/image_part_001.jpg");
		arrayTexture[1].loadFromFile("materials/SIZE4/image_part_002.jpg");
		arrayTexture[2].loadFromFile("materials/SIZE4/image_part_003.jpg");
		arrayTexture[3].loadFromFile("materials/SIZE4/image_part_004.jpg");
		arrayTexture[4].loadFromFile("materials/SIZE4/image_part_005.jpg");
		arrayTexture[5].loadFromFile("materials/SIZE4/image_part_006.jpg");
		arrayTexture[6].loadFromFile("materials/SIZE4/image_part_007.jpg");
		arrayTexture[7].loadFromFile("materials/SIZE4/image_part_008.jpg");
		arrayTexture[8].loadFromFile("materials/SIZE4/image_part_009.jpg");
		arrayTexture[9].loadFromFile("materials/SIZE4/image_part_010.jpg");
		arrayTexture[10].loadFromFile("materials/SIZE4/image_part_011.jpg");
		arrayTexture[11].loadFromFile("materials/SIZE4/image_part_012.jpg");
		arrayTexture[12].loadFromFile("materials/SIZE4/image_part_013.jpg");
		arrayTexture[13].loadFromFile("materials/SIZE4/image_part_014.jpg");
		arrayTexture[14].loadFromFile("materials/SIZE4/image_part_015.jpg");
	}

	// Ðàìêà èãðîîãî ïîëÿ (1 "ýòàæ")
	sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	// Ðàìêà äëÿ îòðèñîâêè ïëàøåê (2 "ýòàæ")
	shape.setSize(sf::Vector2f(CELL_SIZE - 2 , CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	sf::Text text("", font, 52);

	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		if (solved)
		{
			// Öâåò âñåé ðåøåííîé ãîëîâîëîìêè
			shape.setOutlineColor(sf::Color::Cyan);
			text.setFillColor(sf::Color::Cyan);
		}
		}
		if (elements[i] > 0)
		{
			// Êîîðäèíàòû ïëàøåê äëÿ ðåíäåðà
			sf::Vector2f position(i % SIZE * CELL_SIZE + 10.f, i / SIZE * CELL_SIZE + 10.f);
			shape.setPosition(position);
			text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
				image_Texture.setPosition(position);
				image_Texture.setTexture(arrayTexture[elements[i]-1]);
			target.draw(image_Texture, states);
			target.draw(shape, states);
			if (SIZE > 4)
			{
			target.draw(text, states);
			}
		}
	}
}
