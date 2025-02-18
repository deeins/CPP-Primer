// CHAPTER1_SALES_LOG.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//本程序的功能是读取多个关于书的销售数据，输出一个他们的和

#include <iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
    ////只支持读取四个元素的程序
    //Sales_item book1,book2,book3,book4;
    //cin >> book1 >> book2 >> book3 >> book4;
    ////cout << book.getISBN() << add(1,2) << endl;
    ////cout << book << endl;
    //cout << book1 + book2 + book3 + book4 << endl;
    //return 0;

    //有顺序地统计多条不同数据，可以自适应大小，还未实现自适应大小的条件下排序数据
    Sales_item book;
    cout << "请按顺序输入，输入结束时，请再输入一个空格和一个整数" << endl;
    if (cin>>book)
    {
        int cnt = 1;
        Sales_item tmp;
        while (cin >> tmp)
        {
            if (book.getISBN() == tmp.getISBN())
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
                cout << book << "\t\t" << cnt << endl;
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

//g++ -o addItems CHAPTER1_SALES_LOG.cpp Sales_item.cpp
//上一行命令是在终端使用编译本程序生成exe文件的命令，需要一次性把所有cpp文件写出
//否则报错error: ld returned 1 exit status

//终端指令 addItems <salesData.txt>log.txt，将运行名为addItems的可执行文件读入salesData.txt文件中的数据，写入到log.txt文件中




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
