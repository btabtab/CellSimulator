#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Info_struct.h"

class Cell
{
public:

	Cell() {}

	/*This constructor will be used to
	pass information from the previous cell
	so as to keep it similiar and to have
	some groundwork for any mutation.*/
	Cell(Info* info);
	Cell(Info info);

	Info		getInfo();

	void		mutate();

	int			produceRandomValue();
	int			produceRandomValue(int max, int min);

	std::string generateFamilyBranch();

	void		render(sf::RenderWindow* p_window);

	void		die();

	void		age();

	void		setPos(sf::Vector2f n_pos);

private:

	Info			Stats;

	sf::VertexArray body;

};