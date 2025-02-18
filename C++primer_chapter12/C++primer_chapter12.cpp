// C++primer_chapter12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <memory>
#include "StrBlob.h"

using namespace std;



int main()
{
    StrBlob a({ "C++", " ", "primer" });
    a.print();
    {
        StrBlob b({ "primer"," ","C++" });
        a = b;
        a.print();
        b.print();
    }
    a.print();
    StrBlob c = fun({"C++"});
    c.print();
}
