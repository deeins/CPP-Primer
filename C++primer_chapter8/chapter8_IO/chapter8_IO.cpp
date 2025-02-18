// chapter8_IO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
istream& print(istream& in)
{
    string str;
	while (!in.eof())
	{
		in >> str;
	}
	cout << str;
	in.clear();
	return in;
}

//8.4
vector<string>& read_line(vector<string>& svec)
{
	ifstream is("C:\\Users\\hp\\Desktop\\work\\C++Work\\C++primer_chapter8\\chapter8_IO\\x64\\Debug\\test.txt", ifstream::in);
	string str;
	while(getline(is, str))
		svec.push_back(str);
	return svec;
}
//8.5
vector<string>& read_word(vector<string>& svec)
{
	ifstream is("C:\\Users\\hp\\Desktop\\work\\C++Work\\C++primer_chapter8\\chapter8_IO\\x64\\Debug\\test.txt", ifstream::in);
	string str;
	while(is>>str)
		svec.push_back(str);
	return svec;
}
int main()
{
	//print(cin);
	vector<string> svec;
	read_line(svec);
	for (auto c : svec)
		cout << c << endl;
	read_word(svec);
	for (auto c : svec)
		cout << c << endl;
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
