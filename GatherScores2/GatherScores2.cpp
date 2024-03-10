// GatherScores2.cpp : Defines the entry point for the console application.
/*
	Dean Hartfield
	8-14-2015
	Module 06 Application Assignment - Gathering Scores 2
	This program will ask for names and scores from 10 different players,
	and then it will display the scores in descending order and the names in alphabetical order
*/


#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <numeric>


const int NUMBER_OF_PLAYERS = 10;
std::array<int, NUMBER_OF_PLAYERS> scores;
std::array<std::string, NUMBER_OF_PLAYERS> names;
std::array<int, NUMBER_OF_PLAYERS> index;


static bool compareScores(int a, int b)
{
	return scores[a] > scores[b];
}


static bool compareNames(int a, int b)
{
	return names[a].compare(names[b]) < 0;
}


static void capturePlayers()
{
	for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
	{
		std::cout << "Player " << (i + 1) << " please enter your name: ";
		std::cin >> names[i];
		std::cout << names[i] << " please enter your score: ";
		std::cin >> scores[i];
	}
}


static void printList()
{
	for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
	{
		std::cout << names[index[i]] << " - " << scores[index[i]] << std::endl;
	}
}


int main(int argc, _TCHAR* argv[])
{
	capturePlayers();

	// Clear the console
	system("cls");
	
	// Initialize the indexing array to be sequential numbers starting at 0
	iota(begin(index), end(index), 0);
	
	// Sort by descending scores and then print the sorted list
	sort(begin(index), end(index), compareScores);
	std::cout << "Descending scores" << std::endl;
	std::cout << "-----------------" << std::endl;
	printList();

	std::cout << std::endl << std::endl;

	// Initialize the indexing array to be sequential numbers starting at 0
	iota(begin(index), end(index), 0);
	
	// Sort by name alphabetically and then print the sorted list
	sort(begin(index), end(index), compareNames);
	std::cout << "Alphabetical names" << std::endl;
	std::cout << "------------------" << std::endl;
	printList();

	std::cout << std::endl;
	system("pause");
	return 0;
}
