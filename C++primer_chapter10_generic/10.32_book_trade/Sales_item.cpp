#include "Sales_item.h"
#include <iostream>
using namespace std;

//���da1û��ʹ�����ã���ô�ڴ˺����������ɾ��da1�����ݣ����˺����ַ���da1�����ã����Ի���ʴ���
// ����֪��Ϊʲô�����da1�ĵڶ��������ݣ���һ������û�����
//Sales_item& operator+(Sales_item da1, Sales_item da2)
//{
//    da1.revenue = (da1.revenue * da1.units_sold + da2.revenue * da2.units_sold) / (da1.units_sold+da2.units_sold);
//    da1.units_sold = da1.units_sold + da2.units_sold;
//    // TODO: �ڴ˴����� return ���
//    return da1;
//}

Sales_item& operator+(Sales_item& da1, Sales_item& da2)
{
    da1.revenue = (da1.revenue * da1.units_sold + da2.revenue * da2.units_sold) / (da1.units_sold + da2.units_sold);
    da1.units_sold = da1.units_sold + da2.units_sold;
    // TODO: �ڴ˴����� return ���
    return da1;
}

ostream& operator<<(ostream& out, Sales_item data)
{
    // TODO: �ڴ˴����� return ���
    //û��iostreamͷ�ļ��ᱨ��û��ƥ���<<�����
    out << data.bookNo << ' ' << data.units_sold << ' ' << data.revenue;
    return out;
}

istream& operator>>(istream& in, Sales_item& data)
{
    in >> data.bookNo >> data.units_sold >> data.revenue;
    // TODO: �ڴ˴����� return ���
    return in;
}

