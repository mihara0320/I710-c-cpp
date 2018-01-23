#pragma once

#include "stdafx.h"
#include "Counter.h"


Counter::Counter(json prices) {
	this_prices = prices;
}

string Counter::askOrder() {
	string order;
	cout << "*****************************" << endl;
	cout << "Menu: Americana / Margherita" << endl;
	cout << "*****************************" << endl;
	cout << "Hi, what can I get you?" << endl;
	cin >> order;

	return order;
}

double Counter::getPrice(vector<int> usedItemTypes) {
	double totalPrice = 0;

	for (size_t i = 0; i < usedItemTypes.size(); i++) {
		int itemType = usedItemTypes[i];
		for (size_t i = 0; i < this_prices.size(); i++) {
			if (this_prices[i]["id"] == itemType) {
				totalPrice += (double)this_prices[i]["price"];
			}
		}
	}
	return totalPrice;
}