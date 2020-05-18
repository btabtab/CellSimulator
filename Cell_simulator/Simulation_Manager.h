#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Info_struct.h"
#include "Cell.h"

class SimulationManager
{
public:

	SimulationManager();
	SimulationManager(Cell* p_base_cell);

	void MainCycle(sf::RenderWindow* p_window);

	void checkCells(sf::RenderWindow* p_window);

	/*This will add a new cell to the
	list.*/
	void createCell(int ID);

	/*Removes a cell.*/
	void killCell(int ID);

	/*This will go through the "cell_list" and
	make it a proper, contigous list and remove
	any trace of any "dead" cells.*/
	void mendCellList();

private:
	std::vector<Cell*>	cell_list;

	bool				list_needs_mending;

	int max_cell_count;
	bool keep_creating_new_cells;

};