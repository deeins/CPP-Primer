//#pragma once//���ǿ�����ͷ�ļ���α���������ʹ�õ���䣬��Ϊ����֤�������ݣ�����ע��

//ͷ�ļ�������
//#define�趨Ԥ�������������һ��Ϊͷ�ļ���ȫ��д��ʽ��
// Ԥ�������������״̬���Ѷ����δ����
//#ifndef��#ifdef���Ԥ��������Ƿ��Ѷ���
//#ifndef��Ԥ�������δ����ʱΪ�棬#ifdef��֮
//�������Ϊ��ʱ���ᰴ˳��ִ�к���������ֱ������#endif
//�������Ϊ��ʱ�������#ifndef��#endif֮��Ĳ���
#ifndef Sales_item_H
#define Sales_item_H//�����˾�ʱ��Ԥ���������Ϊ�Ѷ��壬���ض���ͷ�ļ�ʱ��#ifndef�����Ϊ��
#include <string>
using namespace std;
//ʹ��sturct�ؼ�������Sales_item���ݽṹ
//����������ʱ��ʼ��������ʹ���б��ʼ��
//δ��ʼ���������ڶ������ʱĬ�ϳ�ʼ����Ĭ��ֵΪ0�Ĳ�ͬ����
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
};//ע��д�ֺ�


Sales_item& operator+(Sales_item& da1, Sales_item& da2);

ostream& operator<<(ostream& out, Sales_item data);

istream& operator>>(istream& in, Sales_item& data);

#endif // !Sales_item_H