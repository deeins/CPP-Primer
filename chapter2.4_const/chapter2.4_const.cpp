// chapter2.4_const.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//作用是防止某些值被程序不小心改变

//关于const功能的记忆方法，摘自知乎
//一个永远不会忘记的方法，const默认是修饰它左边的符号的，如果左边没有，那么就修饰它右边的符号，比如
//
//1. const int* p; 左边没有，看右边的一个，是int，自然就是p指针指向的值不能改变
//2. int const* p; 此时左边有int，其实和上面一样，还是修饰的int
//3. int* const p : 修饰的是 * ，指针不能改变
//4. const int* const p : 第一个左边没有，所以修饰的是右边的int，第二个左边有，所以修饰的是 * ，因此指针和指针指向的值都不能改变
//5. const int const* p : 这里两个修饰的都是int了，所以重复修饰了，有的编译器可以通过，但是会有警告，你重复修饰了，有的可能直接编译不过去

#include <iostream>
#include "file_1.h"
using namespace std;
extern const int buf_size = 3;//其他cpp文件无法访问
//int null = 0;
//int* p = &null;
int main()
{
    //const int i;//const对象必须初始化，否则报错
    //const对象能完成不修改其值的对应类型操作
    //cout << "file_1.h文件中定义的bufff_size=" << bufff_size << endl;//在头文件中的定义报错了，因为头文件只能声明
    cout << "file_1.h文件中声明，file_1.cpp文件中定义的buff_size=" << buff_size << endl;//复习时，注：命名有点糟糕，注意f的数量
    //j = 10;

    //2.4.1const引用
    const int ci = 1024;
    const int& r1 = ci;
    //int& r2 = r1;//普通引用不能引用常量引用，要同时具有底层const资格才能拷贝和拷入

    //初始化和对const的引用
    //初始化常量引用时允许用任意表达式作为初始值，只要该表达式能转换为引用的类型即可
    //！！！对非常量的引用需要类型匹配，这是一个区别
    int i = 42;
    const int& t1 = i;//t1绑定i，但不允许通过t1修改i的值，这一句也说明对const的引用可以引用非const对象
    const int& t2 = 42;//常量引用可以引用字面值
    const int& t3 = t1 * 2;
    int& const t4 = i;//！！虽然写法是顶层const，但实际上const相当于没有，是无效的，用于声明引用的const只能是底层const
    i = 32;
    t4 = 54;//可以修改t4的值
    //t2 = 22;//底层const不能修改其值，其本身指向的对象是常量
    cout << t4 << ' ' << t2 << endl;

    double dval = 3.14;
    const int& ri = dval;
    //上两行代码会被编译器变为下列代码
    /*
    *double dval=3.14;
    * const int temp=dval;//temp是一个临时量对象，编译器用于暂存表达式结果而临时创建的未命名对象，简称临时量
    * const int& ri=temp;
    */
    //在等号两侧类型不一样时，普通引用是这样的一个操作，绑定的是一个临时量，
    //但我们使用引用就是希望绑定原始值dval
    //所以对于普通引用两侧类型不一致时，编译器会报错来阻止你这样写

    
    //2.4.2指针和const
    //指向常量的指针
    const double pi = 3.14;
    //double* p = &pi;//普通指针不能指向常量
    const double* p;
    p= &pi;//指向常量的指针,可以不在创建时初始化
    //*p = 32;//不能给常量赋值
    p = &dval;//指针的类型必须和所指对象一致，！！但指向常量的指针可以指向非常量，这是一个例外

    //const指针 常量指针
    //自身存放的地址不能改变的指针
    //double* const q = &pi;//所指对象类型要一致，指向double类型的常量指针不能指向const double类型的变量，这是因为q没有底层const
    const double* const pp = &pi;//上一行错误，这一行正确。
    int err_numb = 0;
    int* const cur_err = &err_numb;
    /*const int num = 0;
    int *const cur = &num;*/
    
    //顶层const:不能修改自身值的对象，自身是常量
    //顶层const不影响拷贝操作，顶层const对象可以被拷贝，将其视为一个常量即可
    int* const p1=&err_numb;
    //底层const：指向对象是常量，适用于指针和引用
    //底层const都要有底层const资格才能拷贝和拷入
    const int& y1 = err_numb;//变量可以转换为常量，所以尽管类型不一样，但不会报错
    //普通int&不能绑定到const int的常量上
    //const int&能绑定到普通的int变量上

    //2.4.4constexpr和常量表达式
    //常量表达式：指值不会改变并且在编译过程就能得到计算结果的表达式
    //字面值和用常量表达式初始化的const对象属于常量表达式
    const int max_files = 20;//max_files是常量表达式
    const int limit = max_files + 1;//limit是常量表达式
    int staff_size = 27;//staff_size不是常量表达式
    const int sz = staff_size;//不是常量表达式，运行时才能获取到具体值

    //C++11规定用constexpr类型来声明常量表达式，如果认定一个变量是常量表达式，那就声明它为constexpr类型
    constexpr int mf = 20;
    constexpr int limi = mf + 1;
    //constexpr int ss = size();//当size()这个函数是constexpr函数时，这条语句才是正确的
    //C++11允许定义constexpr函数，可以在编译时得到它的值

    //字面值类型
    //constexpr所用到的类型，这些类型比较简单，值容易得到和看出
    //算术类型、引用和指针都是字面值类型
    //各种类和库中的类型则不是字面值类型
    //constexpr指针的初始值必须为nullptr或者0，或者是存储在某个固定地址中的对象
    //函数内部的变量一般不是存放在固定地址中的，所以constexpr类型指针不能指向这种变量
    //定义在函数体外的变量的存储地址都是固定的，可以被指向
    //！！constexpr将它的对象设置为了顶层const
    //int null=0,*p=null;//不能用变量初始化空指针
    int null = 0, * pp2 = nullptr;
    //或者是
    //int null=0,*p=&null;
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
