#include "Sales_data.h"
#include <iostream>
using namespace std;

//���da1û��ʹ�����ã���ô�ڴ˺����������ɾ��da1�����ݣ����˺����ַ���da1�����ã����Ի���ʴ���
// ����֪��Ϊʲô�����da1�ĵڶ��������ݣ���һ������û�����
//Sales_data& operator+(Sales_data da1, Sales_data da2)
//{
//    da1.revenue = (da1.revenue * da1.units_sold + da2.revenue * da2.units_sold) / (da1.units_sold+da2.units_sold);
//    da1.units_sold = da1.units_sold + da2.units_sold;
//    // TODO: �ڴ˴����� return ���
//    return da1;
//}

Sales_data& operator+(Sales_data& da1, Sales_data& da2)
{
    da1.revenue = (da1.revenue * da1.units_sold + da2.revenue * da2.units_sold) / (da1.units_sold + da2.units_sold);
    da1.units_sold = da1.units_sold + da2.units_sold;
    // TODO: �ڴ˴����� return ���
    return da1;
}

ostream& operator<<(ostream& out, Sales_data data)
{
    // TODO: �ڴ˴����� return ���
    //û��iostreamͷ�ļ��ᱨ��û��ƥ���<<�����
    out << data.bookNo << ' ' << data.units_sold << ' ' << data.revenue;
    return out;
}

istream& operator>>(istream& in, Sales_data& data)
{
    in >> data.bookNo >> data.units_sold >> data.revenue;
    // TODO: �ڴ˴����� return ���
    return in;
}
