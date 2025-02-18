// chapter3.6_multi-dimensional_array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//多维数组

#include <iostream>
using namespace std;
//为一个大小为4的数组取别名
using int_arr = int[4];
typedef int int_arr2[4];

int main()
{
	//多维数组初始化
	int int_array[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int int_array2[3][4] = { 1,2,3,4,5,6,7,8,9,10,12 };
	//仅初始化每行第一个元素
	int int_array3[3][4] = { {0},{4},{8} };
	//仅初始化第一行
	int int_array4[3][4] = { 1,2,3,4 };
	//row绑定int_array的第二行，指针同理
	int (&row)[4] = int_array[1];
	//指向4元素的数组的指针
	int iarray[4] = {};
	int(*p)[4]= &iarray;
	cout << p << endl;
	//若使用指针，且不加括号，表示创建一个指针数组
	int* p1[4];

	//使用范围for处理多维数组
	for (auto& row : int_array)
	{
		//第二个for可以使用引用，也可以不使用
		for (auto col : row)
			cout << col << endl;
	}

	cout << int_array[1] << endl;//不太理解为什么不能用它初始化指向4个元素的指针
	cout << &int_array[1] << endl;
	//if(int_array[1]==&int_array[1])
	//取别名后使用指针更方便
	for (int_arr* p = &int_array[0];p != int_array + 3;p++)
	{
		for (int *q = *p; q !=*p+4; q++)
		{
			cout << *q << ' ';
		}
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
