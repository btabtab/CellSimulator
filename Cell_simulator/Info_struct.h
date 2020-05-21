#pragma once

/*The struct "Info" will carry information regarding
things to do with the cells stats, such as the position,
colour and type family branch.*/

struct Info
{
	/*This keeps track of the cells position.*/
	sf::Vector2f position;

	/*this keeps track of the cells colour.*/
	sf::Color colour;

	/*when the stats get checked this
	will be used to determin as to wether
	the cell needs to be killed.*/
	bool is_alive;

	/*determins if the cell will mutate
	when it gets created.*/
	bool will_mutate;

	/*Determines as to whether or not
	the cell will attack other cells.*/
	bool is_hostile;

	/*This will used to check for if the
	cell is going to reproduce during this
	tick.*/
	bool will_produce;

	/*this decides how heavily the cell will
	mutate if it does mutate.
	THIS VALUE MUST ALWAYS BE ABOVE 0!!!!!*/
	int mutation_degree;

	/*This keeps track of how many "ticks"
	the cell has been alive.*/
	int time_alive;

	/*This keeps track of how many "ticks" the
	cell can stay alive for.*/
	int life_span;

	/*This checks for the chance that the 
	cell will reproduce.*/
	int reproduction_chance;

	/*This is a sequence that will determin
	the seed for any future mutations from
	the cells family.*/
	std::string family_branch;

	/*This will be used to track the
	generation of the cell (from the
	initial cell).*/
	int generation;
};