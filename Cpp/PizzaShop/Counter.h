#pragma once
class Counter {
private:
	json this_prices;
public:
	Counter(json prices);
	string askOrder();
	double getPrice(vector<int> usedItemTypes);
};

