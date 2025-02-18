//#pragma once
#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include <string>
#include <iostream>
using namespace std;

struct Sales_item
{
	string ISBN;
	unsigned book_num;
	double per_price;
};

Sales_item& operator+(Sales_item& bk1, Sales_item& bk2);

istream& operator >> (istream& in, Sales_item& bk);

ostream& operator<<(ostream& out, Sales_item& bk);
#endif // !SALES_ITEM_H

