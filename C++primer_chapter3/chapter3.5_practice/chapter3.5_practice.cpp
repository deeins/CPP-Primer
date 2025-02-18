// chapter3.5_practice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//3.28
string sa[10];
int ia[10];

int main()
{
    //3.28
    string sa2[10];
    int ia2[10];
    cout << sa[9] << endl;
    cout << ia[9] << endl;
    cout << sa2[9] << endl;
    cout << ia2[9] << endl;//没有初始化，值未知
    //3.29
    //相比vector，数组有哪些缺点？
    //1.数组不能拷贝和赋值
    //2.数组不能扩展容量

    //3.31
    int iarr[10];
    for (size_t i = 0; i < 10; i++)
    {
        iarr[i] = i;
        cout << iarr[i] << ' ';
    }
    cout << endl;

    //3.32
    //数组不能直接拷贝
    int iarr2[10];
    for (size_t i = 0; i < 10; i++)
    {
        iarr2[i] = iarr[i];
        cout << iarr2[i] << ' ';
    }
    cout << endl;
    vector<int> ivec;
    for (int i = 0; i < 10; i++)
    {
        ivec.push_back(i);
    }
    for (auto c : ivec)
        cout << c << ' ';
    cout << endl;
    vector<int> ivec2 = ivec;//向量可以直接拷贝
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
