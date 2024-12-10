/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "SortType.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	std::cout << "Welcome to the menu! Type \"help\" to begin" << endl;

	while (userCommand != "exit")
	{
		std::cout << "Select an option: ";
		getline(cin, userCommand);
		if (userCommand == "") {
			continue;
		}
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			// Formatting input
			if (parameters.size() > 1) {
				try {
					int sortTypeIndex = stoi(parameters[1]) - 1;
					cout << menu.toString(SortType(sortTypeIndex));
				}
				catch (...) {
					cout << "Invalid sort choice" << endl;
				}
			}
			else {
				cout << menu.toString(SortType::TYPE_ASCENDING);
			}
		}
		else if (command.compare("add") == 0)
		{
			/*
			Iterates though the parameters and adds all items
			that are integers and valid
			*/
			for (auto it = parameters.begin() + 1; it != parameters.end(); ++it) {
				int position;
				try {
					position = stoi(*it);
					Item* item = menu.getItem(position-1);
					order.addItem(item);
				}
				catch(out_of_range e) {
					cerr << "Invalid menu choice: " << *it << endl;
				}
				catch (invalid_argument e) {
					cerr << "Invalid choice: " << *it << endl;
				}
			}
		}
		else if (command.compare("remove") == 0)
		{
			/*
			Iterates though the parameters and adds all items
			that are integers and valid
			*/
			for (auto it = parameters.begin()+1; it != parameters.end(); it++) {
				int position;
				try {
					order.sortItems();
					position = stoi(*it);
					order.removeItem(position-1);
				}
				catch (out_of_range e) {
					cerr << "Invalid order choice: " << *it << endl;
				}
				catch (invalid_argument e) {
					cerr << "Invalid choice: " << *it << endl;
				}
			}
		}
		else if (command.compare("checkout") == 0)
		{
			/*
			Displays the final order total, with an option
			to checkout (store reciept to file) and continue
			*/
			cout << order.toString() << endl;
			string choice;
			cout << "Enter \"y\" to store a recpeipt or enter to continue: ";
			getline(cin, choice);
			if (choice.compare("y") == 0) {
				order.printReceipt();
				cout << "Exiting..." << endl;
				return main();
			}



		}
		else if (command.compare("help") == 0)
		{
			/*
			Displays all commands available
			*/
			std::cout << 
				"Select any of the following:\n" <<
				" - menu [1,2,3,4] - Display menu with an option sort type:\n" <<
					"\t- 1: Course ascending\n" <<
					"\t- 2: Course descending\n" <<
					"\t- 3: Price ascending\n" <<
					"\t- 4: Price descending\n" <<
				" - add - Add item(s) to your order\n"<<
				" - remove - Remove item(s) from your order\n"<<
				" - checkout - Show receipt\n" <<
				" - exit - Quit program"
				<< endl;
		}
		else {
			if (command != "exit") {
				std::cout << "Invalid selection." << endl;
			}
		}

		parameters.clear();
		// Memory management on cstr as the example file didn't
		delete[] cstr;
	}

	std::cout << "Press any key to quit...";
	std::getchar();

}