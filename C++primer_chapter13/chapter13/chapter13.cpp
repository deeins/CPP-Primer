// chapter13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

void otherFunction(int& arg) {
    std::cout << "L-value reference: " << arg << std::endl;
}

void otherFunction(int&& arg) {
    std::cout << "R-value reference: " << arg << std::endl;
}

template <typename T>
void process(T&& arg) {
    otherFunction(std::forward<T>(arg));
}

template <typename T>
void fun(T&& val)
{
    cout << val << endl;
}

int main()
{
    vector<int> temp{ 1,2,3,4,5,6,7 };
    vector<vector<int>> vec;
    //不调用move，这里temp就不会被移动到vec中，而是进行一次拷贝再插入
    vec.emplace_back(move(temp));
    //temp.front() = 9;
    cout << "temp:";
    for (const auto& c : temp)
    {
        cout << c << ' ';
    }
    cout << endl << "vec:";
    for (const auto& c : vec)
    {
        for(const auto &p:c)
            cout << p << ' ';
    }
    cout << endl;

    int x = 10;

    process(x); // 传递左值，调用 L-value 引用版本
    process(5); // 传递右值，调用 R-value 引用版本

    fun(x);//此处还进行了隐式类型推导，如果想显式类型推导，需要在函数名后使用尖括号<>指明类型
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
