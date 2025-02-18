// chapter2.6_self-defining_data_structure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//自定义数据结构

#include <iostream>
//头文件中包含的库类型和头文件会隐含地被引入到使用该头文件的文件中
//如此处使用Sale_data.h头文件隐含地引入了string.h头文件
#include "Sales_data.h"
//如果多次引入同一个头文件，编译时会报错重定义
// 使用预处理器可以保证头文件被多次包含仍能正常工作
#include "Sales_data.h"
//#include是一项预处理功能，预处理器识别到#include时，会将其替换成后面的头文件
//！！预处理器保护符部分见Sales_data.h头文件


using namespace std;

////使用sturct关键词声明Sales_data数据结构
////可以在声明时初始化，可以使用列表初始化
////未初始化的量会在定义对象时默认初始化，默认值为0的不同表现
//struct Sales_data
//{
//    string bookNo;
//    unsigned units_sold = 0;
//    double revenue = 0.0;
//};//注意写分号

//没有分号的结尾会将后面的main函数包含在内，报错return返回的类型不能转换为这个数据结构
//struct MyStruct
//{
//
//}

int main()
{
    Sales_data book;
    //检测是否有输入，输入是否合法
    if (cin >> book)
    {
        int cnt = 1;
        Sales_data tmp;
        while (cin >> tmp)
        {
            if (book.bookNo == tmp.bookNo)
            {
                //收集所有相同书的数量
                book = book + tmp;
                //统计书的数量
                cnt++;
            }
            else
            {
                cout.precision(5);
                //当书不同时，输出一次，
                cout << book << "\t" << cnt << endl;
                //然后把新书赋值给对象book
                book = tmp;
            }
        }
        cout << book << "\t\t" << cnt << endl;
    }
    else
    {
        cerr << "ERROR:未输入合法数据！" << endl;
        return -1;
    }
    return 0;
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
