#pragma once
#include <iostream>
#include <string>
using namespace std;

class Sales_item
{
private:
	string ISBN;
	int saleNumber;
	float tolPrice, perPrice;
public:
	Sales_item() {};
	Sales_item(string is, int sale, float per)
	{
		ISBN = is;
		saleNumber = sale;
		perPrice = per;
	}
	string getISBN() { return ISBN; }
	int getSaleNumber() { return saleNumber; }
	float getTolPrice() { return tolPrice; }
	float getPerPrice() { return perPrice; }
	void setISBN(string is) { ISBN = is; }
	void setSaleNumber(int sale) { saleNumber = sale; }
	void setTolPrice(float tol) { tolPrice = tol; }
	void setPerPrice(float per) { perPrice = per; }
	Sales_item& operator+(Sales_item& book);
	friend istream& operator>>(istream& in, Sales_item& item);
	friend ostream& operator<<(ostream& out, Sales_item& item);
};
//头文件中
int add(int a, int b);


//头文件中不能写下方的定义，会报错多重定义
//istream& operator>>(istream& in, Sales_item& item)
//{
//	in >> item.ISBN >> item.saleNumber >> item.perPrice;
//	return in;
//}

//以下代码也会报错多重定义
//int mul(int a, int b) { return a * b; }

//头文件中，类中可以写简单的定义，类外部不能写定义