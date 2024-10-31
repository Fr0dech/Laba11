#pragma once
#include <SFML/Graphics.hpp>

const int SIZE = 7;						// Скока многа плашек в строчке
const int ARRAY_SIZE = SIZE * SIZE;		// Скока многа плашек вообще
const int FIELD_SIZE = 564;		// Размера поля в пикселях, скейлится от кол-ва плашек в строчке
const int CELL_SIZE = 564 / SIZE;				// Размер плашки в пикселях

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Game : public sf::Drawable, public sf::Transformable
{
public:
	int elements[ARRAY_SIZE];	// Непосредственно каха (плитки)
	int empty_index;			// Пустая плитка
	bool solved;				// Победа?
	sf::Font font;				// Шрифт
public:
	Game();						// Игра
	void Init();				// Заполнение массива с плашками и проверка на победу
	bool Check();				// Проверка (от англ.) check
	void Move(Direction direction);	// Движение жизнь
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;	// Отрисовка чтобы было, виртуальное чтобы работало
};