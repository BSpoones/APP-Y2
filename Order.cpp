#include "Order.h"
#include "Item.h"
#include "Utils.h"
#include "Appetiser.h"
#include <iostream>
#include <numeric>
#include <fstream>
#include <algorithm>

Order::Order() =  default;

/*
Calculates 2 totals for an order
The total price excluding 2-4-1 discounts
and the 2-4-1 discount total
*/
std::vector<double> Order::calculateTotal() { 
	// Split list into those with a 2-4-1 deal and the others
	std::vector<double> twoForOnePrices;
	std::vector<double> totalPrices;

	for (Item* item : items) {
		if (item->getItemType() == ItemType::APPETISER &&
			dynamic_cast<Appetiser*>(item)->isTwoForOne()) {
			twoForOnePrices.push_back(item->getPrice());
		}
		totalPrices.push_back(item->getPrice());
	}
	/*
	Calculates the 2-4-1 total
	To ensure maximumm savings for the business, this sorts the
	vector, then takes the first and last item from the list and
	works inwards, calculating the smallest value.

	This will provide the highest cost savings for the business for
	a 2-4-1 deal, ensuring that only the smallest costs are discounted
	*/
	double twoForOneSavingsSum = 0;
	double totalSum = 0;
	std::sort(twoForOnePrices.begin(), twoForOnePrices.end());
	for (int i = 0; i < twoForOnePrices.size() / 2; i++) {
		// Adding start and end pairs
		twoForOneSavingsSum += std::min(twoForOnePrices[i], twoForOnePrices[twoForOnePrices.size() -1 - i]);

	}
	
	// Calculate sum of the total
	totalSum += std::accumulate(totalPrices.begin(), totalPrices.end(), 0.0);
	return { totalSum, twoForOneSavingsSum };
}
void Order::printReceipt(){
	// Creating a file "reciept.txt" and
	// storing the order string
	std::ofstream receiptFile;
	receiptFile.open("receipt.txt");
	receiptFile << toString();
	receiptFile.close();

	std::cout << "Receipt Printed" << std::endl;
}

std::string Order::toString() { 
	// Sorts items by course and name
	// before showing to a user
	sortItems();
	
	std::string output = "";
	std::vector<double> total = calculateTotal();
	double totalPrice = total[0];
	double twoForOneSavingsPrice = total[1];

	// Showing all items
	output += "--==[ Checkout ]==--\n";
	for (int i = 0; i < items.size(); i++) {
		output += "(" + std::to_string(i+1) + ") " + items[i]->toReceipt() += "\n";
	}
	// Showing price
	output += "----------\n";
	if (twoForOneSavingsPrice != 0) {
		output += "2-4-1 savings: \x9C" + Utils::formatDouble(twoForOneSavingsPrice, 2)+ "\n";
	}
	output += "Total price: \x9C" + Utils::formatDouble(totalPrice - twoForOneSavingsPrice, 2) + "\n";
	return output;
}

/*
Adding a vector of Item pointers to
an order
*/
void Order::addItem(std::vector<Item*> order_items){
	for (Item* order_item : order_items) {
		addItem(order_item);
	}
}
/*
Adding a single item pointer to an order
*/
void Order::addItem(Item* order_item) {
	items.push_back(order_item);
	std::cout << "Item added: " + order_item->getName() << std::endl;
}

/*
Removing a list of items by their index
in the formatted orders list
*/
void Order::removeItem(std::vector<int> indexes) {
	for (int index : indexes) {
		removeItem(index);
	}
	std::cout << "Item(s) removed." << std::endl;
}
/*
Removing a single item by their index
in the formatted ordeers list
*/
void Order::removeItem(int index){
	items.erase(items.begin() + index);
}