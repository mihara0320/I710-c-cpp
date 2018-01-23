#pragma once
class Kitchen
{
private:
	json this_ingredient;
	json this_recipies;
	vector<int> itemsUsed;
	bool hasStock(string item);
	void use(string item);
public:
	Kitchen(json ingredient, json recipies);
	bool cook(string order);
	vector<int> getItemsUsed();

	//~Kitchen();
};

