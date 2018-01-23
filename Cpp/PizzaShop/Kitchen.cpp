#pragma once

#include "stdafx.h"
#include "Kitchen.h"

Kitchen::Kitchen(json ingredients, json recipes)
{
	this_ingredient = ingredients;
	this_recipies = recipes;
}

vector<string> itemsMissing;
map<string, int> missingMap;
map<string, int>::iterator it;

void reportMissingItems() {

	cout << endl << "The order cannot be made because: ";
	for each (auto& el in missingMap)
	{
		it = missingMap.find(el.first);
		cout << it->first << " is missing " << it->second << endl;
	}

	missingMap.clear();
}

bool Kitchen::hasStock(string item) {
	bool stockLeft;


	for each (json stock in this_ingredient) {

		if (stock["name"] == item) {
			if ((int)stock["quantity"] > 0) {
				stockLeft = true;
			}
			else {
				stockLeft = false;

				if (missingMap.count(stock["name"]) == 0) {
					// not found
					missingMap.insert(pair<string, int>(stock["name"], 1));
				}
				else {
					// found
					missingMap[stock["name"]] += 1;
				}
				
			}
		}
	}
	return stockLeft;
}

void Kitchen::use(string item)
{
	for (size_t i = 0; i < this_ingredient.size(); i++) {
		json stock = this_ingredient[i];
		if (stock["name"] == item) {
			this_ingredient[i]["quantity"] = this_ingredient[i]["quantity"] - 1;
			itemsUsed.push_back(stock["priceType"]);
		}
	}
}



bool Kitchen::cook(string order) {
	bool canBeCooked = true;

	json items;

	for each (json recipe in this_recipies) {
		if (recipe["name"] == order) {
			items = recipe["ingredients"];
			for each (json item in items) {
				if (!hasStock(item)) {
					canBeCooked = false;
				}
			}
			if (canBeCooked) {
				for each (json item in items) {
					use(item);
				}
			}
			else {
				reportMissingItems();
			}
		}

	}

	return canBeCooked;
}

vector<int> Kitchen::getItemsUsed() {

	return itemsUsed;
}



