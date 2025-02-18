// C++primer_chapter6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//6.2.3
// 6.17
//对于形参为引用的函数，以下两种情况成立，其他类型是否有const都一样
//接受字面量和普通string对象
bool have_upper(const string& s)
{
    for (const auto c : s)
    {
        if (isupper(c) == true)return true;
    }
    return false;
}
//不接受字面量
string& to_lower(string& s)
{
    for (auto& c : s)
    {
        c = tolower(c);
    }
    return s;
}
//6.2.4
//6.21
int compare(const int& i, const int* p)
{
    if (i > *p)return i;
    else return *p;
}
//6.24
void print(const int ia[10])
{
    for (size_t i = 0;i != 10;++i)
    {
        cout << *(ia+i) << endl;
    }
}

//6.2.6
//6.27
int sum_intlist(initializer_list<int> list)
{
    int sum=0;
    for (const auto& i : list)
    {
        sum += i;
    }
    return sum;
}

//6.3.2
//6.33
// 执行顺序有点复杂
//递归生成vector对象的字符串连接
string print_svec(vector<string>::iterator beg,vector<string>::iterator end)
{
    string s=*(beg);
    if (end != beg + 1)
    {
        s += " " + print_svec(beg + 1, end);
        return s;
    }
    else
    {
        return *beg;
    }
}
int main()
{
    string s = "abc";
    cout << have_upper(s)<<endl;
    cout << have_upper("abc") << endl;
    cout << have_upper("ABC") << endl;
    string s1 = "ABCD";
    cout << to_lower(s1) << endl;

    //6.21
    int i = 12, j = 15, * p = &j;
    cout << compare(i, p) << endl;
    //6.24
    int ia[10] = { 10 };
    print(ia);

    //6.27
    cout << sum_intlist({ 1,2,3,4,5,6,7,8,9 });
    cout << endl;

    //6.33
    vector<string> svec = { "this","is","a","test","text" };
    cout << print_svec(svec.begin(), svec.end());
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
