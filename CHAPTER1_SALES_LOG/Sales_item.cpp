#include "Sales_item.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& in, Sales_item& item)
{
	in >> item.ISBN >> item.saleNumber >> item.perPrice;
	item.tolPrice = item.saleNumber * item.perPrice;
	return in;
}

ostream& operator<<(ostream& out, Sales_item& item)
{
	out << item.ISBN << '\t' << item.saleNumber << '\t' << item.tolPrice << '\t' << item.perPrice;
	// TODO: 在此处插入 return 语句
	return out;
}

int add(int a, int b)
{
	return a + b;
}

Sales_item& Sales_item::operator+(Sales_item& book)
{
	//判断是否是同一本书
	if (this->ISBN == book.getISBN())
	{
		this->tolPrice += book.getTolPrice();
		this->saleNumber += book.getSaleNumber();
		this->perPrice = this->tolPrice / this->saleNumber;
	}
	else
	{
		//输出错误信息，如果是写入文件的程序，不会将cerr中的信息写入到文件中，cerr输出的是错误信息，写到cerr的数据是不缓存冲的，在执行窗口中输出
		cerr << "ERROR:there are different books." << endl
			<< this->getISBN() << " and " << book.getISBN() << endl;
	}
	// TODO: 在此处插入 return 语句
	return *this;
}
