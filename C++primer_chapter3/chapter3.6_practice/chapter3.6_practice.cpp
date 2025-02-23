﻿// chapter3.6_practice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//存在部分地方未理解

#include <iostream>
#include <cstddef>
using namespace std;
using int_array = int[4];
typedef int int_array2[4];

int main()
{
	//多维数组初始化
	int iarray[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	//范围for
	//此处的引用不能换成指针
	for (int(&row)[4] : iarray)
	{
		for (int col : row)
			cout << col << ' ';
		cout << endl;
	}
	//使用下标
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0;j < 4;j++)
		{
			cout << iarray[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	//使用指针
	for (int (*p)[4] = &iarray[0]; p !=iarray+3; p++)
	{
		for (int* q = *p;q != *p + 4;q++)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;

	//使用auto
	//范围for
	//此处的引用不能换成指针
	for (auto &row : iarray)
	{
		for (int col : row)
			cout << col << ' ';
		cout << endl;
	}
	//使用下标
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0;j < 4;j++)
		{
			cout << iarray[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	//使用指针
	for (auto p = &iarray[0]; p != iarray + 3; p++)
	{
		for (auto q = *p;q != *p + 4;q++)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;

	//范围for
//此处的引用不能换成指针
	for (int(&row)[4] : iarray)
	{
		for (int col : row)
			cout << col << ' ';
		cout << endl;
	}
	//使用下标
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0;j < 4;j++)
		{
			cout << iarray[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	//使用指针
	for (int(*p)[4] = &iarray[0]; p != iarray + 3; p++)
	{
		for (int* q = *p;q != *p + 4;q++)
			cout << *q << ' ';
		cout << endl;
	}
	cout << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
