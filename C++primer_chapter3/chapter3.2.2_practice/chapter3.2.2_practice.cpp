// chapter3.2.2_practice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //3.2读入一整行
	cout << "3.2" << endl;
    string str;
	//getline会读入一行中所有元素，包括空格和换行符
	while (getline(cin, str) && str != "end")
	{
		cout << str << endl;
	}
	//读入一个单词
	string str2;
	//cin无法读入空格，所以可以通过cin分割出单词
	while (cin>>str2 && str2 != "end")
	{
		cout << str2 << endl;
	}
	//3.4
	cout << 3.4 << endl;
	string str3, str4;
	cin >> str3 >> str4;
	if (str3 > str4)
	{
		cout << "the bigger one between str3 and str4 is";
		cout << str3 << endl;
	}
	else if(str3 < str4)
	{
		cout << "the bigger one between str3 and str4 is";
		cout << str4 << endl;
	}
	else
	{
		cout << "they are same" << endl;
	}
	cin >> str3 >> str4;
	if (str3.size()>str4.size())
	{
		cout << str3 << endl;
	}
	else if (str3.size()<str4.size())
	{
		cout << str4 << endl;
	}
	else
	{
		cout << "they have same length" << endl;
	}

	//3.5
	cout << 3.5 << endl;
	cin >> str4;
	while (cin>>str3&&str3!="end")
	{
		str4 += ' '+str3;
	}
	cout << str4 << endl;
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
