//#pragma once//���ǿ�����ͷ�ļ���α���������ʹ�õ���䣬��Ϊ����֤�������ݣ�����ע��

//ͷ�ļ�������
//#define�趨Ԥ�������������һ��Ϊͷ�ļ���ȫ��д��ʽ��
// Ԥ�������������״̬���Ѷ����δ����
//#ifndef��#ifdef���Ԥ��������Ƿ��Ѷ���
//#ifndef��Ԥ�������δ����ʱΪ�棬#ifdef��֮
//�������Ϊ��ʱ���ᰴ˳��ִ�к���������ֱ������#endif
//�������Ϊ��ʱ�������#ifndef��#endif֮��Ĳ���
#ifndef SALES_DATA_H
#define SALES_DATA_H//�����˾�ʱ��Ԥ���������Ϊ�Ѷ��壬���ض���ͷ�ļ�ʱ��#ifndef�����Ϊ��
#include <string>
using namespace std;
//ʹ��sturct�ؼ�������Sales_data���ݽṹ
//����������ʱ��ʼ��������ʹ���б��ʼ��
//δ��ʼ���������ڶ������ʱĬ�ϳ�ʼ����Ĭ��ֵΪ0�Ĳ�ͬ����
struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};//ע��д�ֺ�

Sales_data& operator+(Sales_data& da1, Sales_data& da2);

ostream& operator<<(ostream& out, Sales_data data);

istream& operator>>(istream& in, Sales_data& data);
#endif // !SALES_DATA_H