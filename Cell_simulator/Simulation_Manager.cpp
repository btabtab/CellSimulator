#include "Simulation_Manager.h"


SimulationManager::SimulationManager(Cell* p_base_cell)
{
	cell_list.push_back(p_base_cell);

	max_cell_count = 100;

	std::cout << cell_list.back()->getInfo().colour.r << std::endl;
	std::cout << cell_list.back()->getInfo().colour.g << std::endl;
	std::cout << cell_list.back()->getInfo().colour.b << std::endl;

}

void SimulationManager::MainCycle(sf::RenderWindow* p_window)
{
	//p_window->setFramerateLimit(60);

	while (p_window->isOpen())
	{
		sf::Event event;
		while (p_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				p_window->close();
			}
		}
		std::cout << cell_list.size();
		std::cout << std::endl;

		checkCells(p_window);

		p_window->display();
		p_window->clear();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			p_window->close();
	}

}

void SimulationManager::checkCells(sf::RenderWindow* p_window)
{

	int cell_count_per_tick = cell_list.size();

	bool check_this_half = true;

	for (int i = 0; i != cell_count_per_tick; i++)
	{
		if (check_this_half)
		{

			cell_list.at(i)->age();

			/*This will check the cell at "ID".*/
			if (cell_list.at(i)->getInfo().will_produce == true)
			{
				
				if (rand() % 73 + 1 <= cell_list.at(i)->getInfo().reproduction_chance)
				{
					if (cell_list.size() >= max_cell_count)
					{
						keep_creating_new_cells = false;
						max_cell_count += max_cell_count / 4;
					}
					if (cell_list.size() <= max_cell_count / 8)
					{
						keep_creating_new_cells = true;
					}

					if (keep_creating_new_cells)
					{
						createCell(i);
						for (int o = 0; o != cell_list.size(); o++)
						{
							if (*cell_list.back()->getPosPtr() == *cell_list.at(o)->getPosPtr())
							{
								cell_list.back()->redoPosition(o);								
							}
							else
							{
								break;
							}
						}
					}

				}
			}

			if (
				cell_list.at(i)->getInfo().time_alive == cell_list.at(i)->getInfo().life_span
				||
				cell_list.at(i)->getInfo().time_alive >= cell_list.at(i)->getInfo().life_span)
			{
				cell_list.at(i)->die();
			}

			if (cell_list.at(i)->getInfo().is_alive != true)
			{
				killCell(i);
				//std::cout << "kill me (im number " << i << " in the list)";
				//std::cout << std::endl;
			}


			check_this_half = false;
		}
		else
		{
			check_this_half = true;
		}

		//cell_list.at(i)->think();

		cell_list.at(i)->render(p_window);

	}

	if (list_needs_mending == true)
	{
		mendCellList();
	}

	if (cell_list.size() > 100000)
	{
		int halt_int;
		std::cin >> halt_int;
	}

}

void SimulationManager::createCell(int ID)
{

	/*This will push a new cell into the "cell_list" and will
	get the cell's info at "ID" and will use that in the
	constructor.
	*/
	cell_list.push_back(new Cell(cell_list.at(ID)->getInfo()));

}

void SimulationManager::killCell(int ID)
{

	cell_list.at(ID)->die();
	list_needs_mending = true;
}

void SimulationManager::mendCellList()
{

	std::vector<Cell*> temp_cell_list;

	for (int i = 0; i < cell_list.size(); i++)
	{
		if (cell_list.at(i)->getInfo().is_alive == true)
		{
			temp_cell_list.push_back(cell_list.at(i));
		}
	}
	
	cell_list.clear();
	cell_list = temp_cell_list;

}
