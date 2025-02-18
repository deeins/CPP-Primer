//#pragma once//这是可以让头文件多次被包含还能使用的语句，但为了验证书上内容，将其注释

//头文件保护符
//#define设定预处理变量，名字一般为头文件的全大写形式，
// 预处理变量有两种状态：已定义和未定义
//#ifndef和#ifdef检查预处理变量是否已定义
//#ifndef在预处理变量未定义时为真，#ifdef反之
//当检查结果为真时，会按顺序执行后续操作，直到遇到#endif
//当检查结果为假时，会忽略#ifndef和#endif之间的部分
#ifndef Sales_item_H
#define Sales_item_H//遇到此句时，预处理变量变为已定义，当重定义头文件时，#ifndef检查结果为假
#include <string>
using namespace std;
//使用sturct关键词声明Sales_item数据结构
//可以在声明时初始化，可以使用列表初始化
//未初始化的量会在定义对象时默认初始化，默认值为0的不同表现
struct Sales_item
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_item(){}
    Sales_item(string isbn, unsigned sold, double rev)
        :bookNo(isbn), units_sold(sold), revenue(rev) {}
    Sales_item(string isbn)
        :bookNo(isbn) {}
};//注意写分号


Sales_item& operator+(Sales_item& da1, Sales_item& da2);

ostream& operator<<(ostream& out, Sales_item data);

istream& operator>>(istream& in, Sales_item& data);

#endif // !Sales_item_H