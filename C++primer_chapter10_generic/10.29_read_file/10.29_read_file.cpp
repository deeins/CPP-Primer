// 10.29_read_file.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    //先输出再输入文件内容会导致输入内容为空白，运行一次输出后注释可以解决此问题
    //ofstream os("word_list.txt", ofstream::out);
    //os << "apple banana pen ant"<<" count";
    ifstream is("word_list.txt",ifstream::in);
    istream_iterator<string> word_iter(is), eof;
    vector<string> svec;
    while (word_iter != eof)
        svec.push_back(*word_iter++);
    //vector<string> svec(word_iter, eof);
    for (const auto& c : svec)
        cout << c << ' ';
    cout << '\n';

    //10.30
    //尾后迭代器不能使用上一个流迭代器创建时同时创建的尾后迭代器
    istream_iterator<int> in_iter(cin),eof2;
    vector<int> ivec(in_iter, eof2);
    sort(ivec.begin(), ivec.end());
    //第二个参数必须是字符串，表示每次输出后都输出一个该参数
    ostream_iterator<int>out_iter(cout, " ");
    unique_copy(ivec.cbegin(), ivec.cend(), out_iter);
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
