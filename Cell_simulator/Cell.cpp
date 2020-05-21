#include "Cell.h"

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

	Stats.generation++;

	std::cout << "generation:" << Stats.generation;
	std::cout << std::endl;
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

																				 
	Stats.mutation_degree		= Stats.mutation_degree		+ produceRandomValue(Stats.mutation_degree , 1);
	Stats.life_span				= Stats.life_span			+ produceRandomValue(Stats.mutation_degree, 1);
	Stats.reproduction_chance	= Stats.reproduction_chance + produceRandomValue(Stats.mutation_degree, 1);
	
	Stats.colour.r				= Stats.mutation_degree;
	Stats.colour.g				= Stats.life_span;
	Stats.colour.b				= Stats.reproduction_chance;

	if (Stats.mutation_degree == 0)
		Stats.mutation_degree++;

	Stats.will_mutate == false;
	if (produceRandomValue(10, 1) > 5)
	{
		Stats.will_mutate == true;
	}

	if (Stats.mutation_degree == 0)
		Stats.mutation_degree++;

	//checks if the stats are below 0.
	if (Stats.mutation_degree == 0)
		Stats.mutation_degree++;

	if (Stats.mutation_degree < 0)
	{
		Stats.mutation_degree = 1;
	}

	if (Stats.life_span < 0)
	{
		Stats.life_span = 1;
	}

	if (Stats.reproduction_chance < 0)
	{
		Stats.reproduction_chance = 1;
	}

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
	Stats.life_span--;
}

sf::Vector2f* Cell::getPosPtr()
{
	return &Stats.position;
}

void Cell::redoPosition(int distance)
{
	Stats.position.x += produceRandomValue(distance + 20, 1);
	Stats.position.y += produceRandomValue(distance + 20, 1);
}

void Cell::think()
{
	std::cout << "life = " << Stats.time_alive << " / " << Stats.life_span;
	std::cout << std::endl;
}
