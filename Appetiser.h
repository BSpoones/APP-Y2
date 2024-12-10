#pragma once
#include <string>
#include "Item.h"

class Appetiser : public Item {
public:
	Appetiser(
		const std::string& name,
		double price,
		int calories,
		bool shareable,
		bool twoForOne
	);
	~Appetiser();
	// Getter for shareable
	bool isShareable() const;
	// Getter for twoForOne
	bool isTwoForOne();
private:
	bool shareable;
	bool twoForOne;
protected:
	ItemType getItemType() const override;
	std::string toString();
	std::string toReceipt() override;
};