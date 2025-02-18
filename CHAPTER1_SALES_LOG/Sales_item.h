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
//ͷ�ļ���
int add(int a, int b);


//ͷ�ļ��в���д�·��Ķ��壬�ᱨ����ض���
//istream& operator>>(istream& in, Sales_item& item)
//{
//	in >> item.ISBN >> item.saleNumber >> item.perPrice;
//	return in;
//}

//���´���Ҳ�ᱨ����ض���
//int mul(int a, int b) { return a * b; }

//ͷ�ļ��У����п���д�򵥵Ķ��壬���ⲿ����д����