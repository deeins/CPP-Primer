// chapter8.6_book_store.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//传入一个文件名进行读取销售数据

#include <iostream>
#include <fstream>
#include "Sales_data.h"
using namespace std;

int main(int argc, char* argv[])
{
    Sales_data book, next_book;
    //传入文件名
    ifstream is(argv[1]);
    ofstream os(argv[2], ofstream::app);
    if (is >> book)
    {
        int data_cnt = 1;
        while (is >> next_book)
        {
            if (book.bookNo == next_book.bookNo)
            {
                book = book + next_book;
                ++data_cnt;
            }
            else
            {
                cout << book;
                cout << "  共有" << data_cnt << "条数据" << endl;
                os << book;
                os << "  共有" << data_cnt << "条数据" << endl;
                book = next_book;
                data_cnt = 1;
            }
        }
        cout << book;
        cout << "  共有" << data_cnt << "条数据" << endl;
        os << book;
        os << "  共有" << data_cnt << "条数据" << endl;
    }
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
