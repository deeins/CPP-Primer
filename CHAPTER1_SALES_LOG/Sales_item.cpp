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
	// TODO: �ڴ˴����� return ���
	return out;
}

int add(int a, int b)
{
	return a + b;
}

Sales_item& Sales_item::operator+(Sales_item& book)
{
	//�ж��Ƿ���ͬһ����
	if (this->ISBN == book.getISBN())
	{
		this->tolPrice += book.getTolPrice();
		this->saleNumber += book.getSaleNumber();
		this->perPrice = this->tolPrice / this->saleNumber;
	}
	else
	{
		//���������Ϣ�������д���ļ��ĳ��򣬲��Ὣcerr�е���Ϣд�뵽�ļ��У�cerr������Ǵ�����Ϣ��д��cerr�������ǲ������ģ���ִ�д��������
		cerr << "ERROR:there are different books." << endl
			<< this->getISBN() << " and " << book.getISBN() << endl;
	}
	// TODO: �ڴ˴����� return ���
	return *this;
}
