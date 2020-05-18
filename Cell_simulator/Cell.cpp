#include "Cell.h"

Cell::Cell(Info* info)
{
	Stats = *info;

	Stats.colour = sf::Color::White;


	if (Stats.will_mutate == true)
	{
		mutate();
	}

	body.resize(1);
	body.setPrimitiveType(sf::Points);
	body[0].color		= Stats.colour;
	body[0].position	= Stats.position;

	delete info;
	std::cout << "c_r " << Stats.colour.r			 << std::endl;
	std::cout << "c_g " << Stats.colour.g			 << std::endl;
	std::cout << "c_b " << Stats.colour.b			 << std::endl;
	std::cout << "m_d " << Stats.mutation_degree	 << std::endl;
	std::cout << "l_s " << Stats.life_span			 << std::endl;
}

Cell::Cell(Info info)
{
	Stats = info;


	if (Stats.will_mutate == true)
	{
		mutate();
	}

	//produceRandomValue(4, 0);
	Stats.position.x += produceRandomValue(8, 1);
	Stats.position.y += produceRandomValue(8, 1);

	body.resize(1);
	body.setPrimitiveType(sf::Points);
	body[0].color = Stats.colour;
	body[0].position = Stats.position;

	//std::cout << "c_r " << Stats.colour.r			 << std::endl;
	//std::cout << "c_g " << Stats.colour.g			 << std::endl;
	//std::cout << "c_b " << Stats.colour.b			 << std::endl;
	//std::cout << "m_v " << Stats.mutation_volatility << std::endl;
	//std::cout << "m_d " << Stats.mutation_degree	 << std::endl;
	//std::cout << "l_s " << Stats.life_span			 << std::endl;
}

Info Cell::getInfo()
{
	return Stats;
}

void Cell::mutate()
{

	Stats.is_alive				 = true;
	Stats.time_alive			 = 0;
	Stats.family_branch			 = generateFamilyBranch();

	Stats.colour.r				= Stats.colour.r			+ produceRandomValue(Stats.mutation_degree + 2, 1);
	Stats.colour.g				= Stats.colour.g			+ produceRandomValue(Stats.mutation_degree + 2, 1);
	Stats.colour.b				= Stats.colour.b			+ produceRandomValue(Stats.mutation_degree + 2, 1);
																				 
	Stats.mutation_degree		= Stats.mutation_degree		+ produceRandomValue(Stats.mutation_degree, 1);
	Stats.life_span				= Stats.life_span			+ produceRandomValue(Stats.mutation_degree, 1);
	Stats.reproduction_chance	= Stats.reproduction_chance + produceRandomValue(Stats.mutation_degree, 1);

	if (Stats.mutation_degree == 0)
		Stats.mutation_degree++;

	Stats.will_mutate == false;
	if (produceRandomValue(10, 1) > 5)
	{
		Stats.will_mutate == true;
	}

	if (Stats.mutation_degree == 0)
		Stats.mutation_degree++;
}

int Cell::produceRandomValue(int max, int min)
{
	float A;
	float B;
	float AB;

	if (max == 0)
		max++;

	if (min == 0)
		min++;

	A = rand() % max + min;

	B = rand() % max + min;

	AB = A - B;

	AB = (AB) + (A - B);

	return AB;
}

std::string Cell::generateFamilyBranch()
{
	return " ";
}

void Cell::render(sf::RenderWindow* p_window)
{
	p_window->draw(body);
}

void Cell::die()
{
	Stats.is_alive = false;
}

void Cell::age()
{
	Stats.time_alive++;
}

void Cell::setPos(sf::Vector2f n_pos)
{
}
