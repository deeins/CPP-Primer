// WHILE_FOR.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    int val = 1, sum = 0;
	/*
	* 下列循环，当输入的值不是整数或者文件结束符时，会一直循环
	* cin是istream对象，在输入错误或遇到文件结束符时会变得无效，也就会让循环终止
	* 文件结束符在windows系统中可以使用CTRL+Z键入，然后使用回车就可以输入
	*/
	while (cin >> val)
	{
		sum += val;
		cout << "sum is " << sum << endl;
		cout << "in while,val is " << val << endl;
	}
	cout << "val is " << val << endl;
	val = ';';
	cout << "now,val is " << val << endl;
	{
		val = 1;
	}
	cout << "在局部代码块中修改val的值后，在外部输出val的值为" << val << endl;
	//cin在输入的值与>>运算符整型右值类型不一样时，会放入0到整型右值中，并不会将输入的数据转换为ASCii码后放入
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
