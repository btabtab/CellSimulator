#include <SFML/Graphics.hpp>

#include "Info_struct.h"
#include "Cell.h"
#include "Simulation_Manager.h"

int main()
{
	Info temp;

	temp.position = sf::Vector2f(300.f, 300.f);
		
	temp.colour = sf::Color::White;

	std::cout << "temp.colour.r = " << temp.colour.r << std::endl;
	std::cout << "temp.colour.g = " << temp.colour.g << std::endl;
	std::cout << "temp.colour.b = " << temp.colour.b << std::endl;
		
	temp.position				= sf::Vector2f(300.f, 300.f);
	temp.is_alive				= true;
	temp.will_mutate			= true;
	temp.will_produce			= true;
	temp.is_hostile				= false;
	temp.mutation_degree		= 1;
	temp.time_alive				= 0;
	temp.life_span				= 60;
	temp.family_branch			= "0";
	temp.reproduction_chance	= 70;

	Cell test_cell(temp);

	sf::RenderWindow window(sf::VideoMode(600.f, 600.f), "window");

	SimulationManager MainRunspace(&test_cell);
	MainRunspace.MainCycle(&window);


}