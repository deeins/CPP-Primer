#include "Sales_item.h"

Sales_item& operator+(Sales_item& bk1, Sales_item& bk2)
{
	bk1.per_price = (bk1.book_num * bk1.per_price + bk2.book_num * bk2.per_price) / (bk1.book_num + bk2.book_num);
	bk1.book_num += bk2.book_num;
	return bk1;
}

istream& operator >> (istream& in, Sales_item& bk)
{
	in >> bk.ISBN >> bk.book_num >> bk.per_price;
	return in;
}

ostream& operator<<(ostream& out, Sales_item& bk)
{
	out << bk.ISBN << ' ' << bk.book_num << ' ' << bk.per_price;
	return out;
}