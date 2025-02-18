// chapter3_iterator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//迭代器

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    //练习3.21
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{ 10 };
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector <string> v7{10, "hi"};
    for (int i = 0; i < 7; i++)
    {
        int cnt = 0;
        switch (i)
        {
        case 0:
            cnt = v1.end() - v1.begin();
            break;
        case 1:
            cnt = v2.end() - v2.begin();
            break;
        case 2:
            cnt = v3.end() - v3.begin();
            break;
        case 3:
            cnt = v4.end() - v4.begin();
            break;
        case 4:
            cnt = v5.end() - v5.begin();
            break;
        case 5:
            cnt = v6.end() - v6.begin();
            break;
        case 6:
            cnt = v7.end() - v7.begin();
            break;
        }
        cout << "v" << i + 1 << "含有" << cnt << "个元素" << endl;
    }
    //3.22
    string s = "some text";
    for (auto it = s.begin(); it < s.end(); it++)
    {
        *it = toupper(*it);
    }
    cout << s << endl;
    //3.23
    vector<int> in_vec = { 10,2,1,5,3 };
    for (auto it = in_vec.begin(); it < in_vec.end(); it++)
    {
        *it *= 2;
        cout << *it << ' ';
    }
    cout << endl;
    //3.25
    vector<unsigned> scores(11, 0);
    unsigned grade = 0;
    auto beg = scores.begin();
    while (cin>>grade)
    {
        (*(beg + grade / 10))++;//++优先级比*更高
    }
    for (auto c : scores)
    {
        cout << c << ' ';
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
