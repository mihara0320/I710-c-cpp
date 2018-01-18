#include "stdafx.h"
#include "Counter.h"


Counter::Counter()
{
}

string Counter::askOrder()
{
	string order;
	cout << "Hi, what can I get you?" << endl;
	cin >> order;

	return order;
}