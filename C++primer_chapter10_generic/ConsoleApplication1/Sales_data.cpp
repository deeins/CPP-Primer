#include "Sales_data.h"
#include <iostream>
using namespace std;

//如果da1没有使用引用，那么在此函数结束后会删除da1的数据，而此函数又返回da1的引用，所以会访问错误，
// 但不知道为什么会输出da1的第二三个数据，第一个数据没有输出
//Sales_data& operator+(Sales_data da1, Sales_data da2)
//{
//    da1.revenue = (da1.revenue * da1.units_sold + da2.revenue * da2.units_sold) / (da1.units_sold+da2.units_sold);
//    da1.units_sold = da1.units_sold + da2.units_sold;
//    // TODO: 在此处插入 return 语句
//    return da1;
//}

Sales_data& operator+(Sales_data& da1, Sales_data& da2)
{
    da1.revenue = (da1.revenue * da1.units_sold + da2.revenue * da2.units_sold) / (da1.units_sold + da2.units_sold);
    da1.units_sold = da1.units_sold + da2.units_sold;
    // TODO: 在此处插入 return 语句
    return da1;
}

ostream& operator<<(ostream& out, Sales_data data)
{
    // TODO: 在此处插入 return 语句
    //没有iostream头文件会报错没有匹配的<<运算符
    out << data.bookNo << ' ' << data.units_sold << ' ' << data.revenue;
    return out;
}

istream& operator>>(istream& in, Sales_data& data)
{
    in >> data.bookNo >> data.units_sold >> data.revenue;
    // TODO: 在此处插入 return 语句
    return in;
}
