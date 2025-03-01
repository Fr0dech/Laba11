#pragma once
#include <SFML/Graphics.hpp>

const int SIZE = 7;						// ����� ����� ������ � �������
const int ARRAY_SIZE = SIZE * SIZE;		// ����� ����� ������ ������
const int FIELD_SIZE = 564;		// ������� ���� � ��������, ��������� �� ���-�� ������ � �������
const int CELL_SIZE = 564 / SIZE;				// ������ ������ � ��������

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Game : public sf::Drawable, public sf::Transformable
{
public:
	int elements[ARRAY_SIZE];	// ��������������� ���� (������)
	int empty_index;			// ������ ������
	bool solved;				// ������?
	sf::Font font;				// �����
public:
	Game();						// ����
	void Init();				// ���������� ������� � �������� � �������� �� ������
	bool Check();				// �������� (�� ����.) check
	void Move(Direction direction);	// �������� �����
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;	// ��������� ����� ����, ����������� ����� ��������
};