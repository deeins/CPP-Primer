// chapter8.6_book_store.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//传入一个文件名进行读取销售数据

#include <iostream>
#include <fstream>
#include "Sales_item.h"
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool compare_ISBN(Sales_item& data1, Sales_item& data2)
{
    return data1.bookNo < data2.bookNo;
}

int main(int argc, char* argv[])
{
    Sales_item book, next_book;
    //传入文件名，要带后缀
    /*ifstream is(argv[1]);
    ofstream os(argv[2]);*/
    //文件从所在项目的最外层读入
    ifstream is("salesData.txt");
    ofstream os("log.txt");
    istream_iterator<Sales_item> sales_iter(is), eof;
    vector<Sales_item> book_datas(sales_iter, eof),log;
    sort(book_datas.begin(), book_datas.end(), compare_ISBN);
    int data_cnt = 1;
    vector<Sales_item>::iterator beg = book_datas.begin();
    auto end = beg + 1;
    int pos = 0;
    //此处的beg需要引用传递，默认是值传递，所以需要写上&

    auto small_isbn = [&beg](const Sales_item& item) {return (*beg).bookNo != item.bookNo;};
    //法1
    while ((end=find_if(beg,book_datas.end(), small_isbn)) != book_datas.end())
    {
        cout << accumulate(beg, end, Sales_item((*beg).bookNo));
        cout << "  共有" << count_if(beg, end, [](const Sales_item& item) {return true;}) << "条数据" << endl;
        beg = end++;
    }
    cout << accumulate(beg, end, Sales_item((*beg).bookNo));
    cout << "  共有" << count_if(beg, end, [](const Sales_item& item) {return true;}) << "条数据" << endl;
    //法2
    /*while (end != book_datas.end())
    {
        if ((*beg).bookNo != (*end).bookNo)
        {
            os << accumulate(beg, end, Sales_item((*beg).bookNo));
            os << "  共有" << data_cnt << "条数据" << endl;
            data_cnt = 1;
            beg = end++;
        }
        else
        {
            ++end;
            ++data_cnt;
        }
    }
    log.push_back(accumulate(beg, end, Sales_item((*beg).bookNo)));
    os << accumulate(beg, end, Sales_item((*beg).bookNo));
    os << "  共有" << data_cnt << "条数据" << endl;*/
   
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
