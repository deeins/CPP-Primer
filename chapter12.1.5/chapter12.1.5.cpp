// chapter12.1.5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
using namespace std;
typedef unique_ptr<int> IntP;

int main()
{
    unique_ptr<int> p(new int(42));
    //对unique_ptr进行拷贝会报错“它是已删除的函数”
    //unique_ptr<int> q(p);
    int x = 1024, * pi = &x, * pi2 = new int(1024);
    //IntP p1(pi);
    IntP p2(pi2);
    //IntP p3(&x);
    IntP p5(p2.get());
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单t5
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
