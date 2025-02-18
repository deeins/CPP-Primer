// chapter2.5_alias.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//处理类型，类型有时会很复杂，此时可以选择取别名

#include <iostream>
using namespace std;

//类型别名
//可包含类型修饰*&
typedef double wages,*p;
//别名声明
using dou = double;

int main()
{
	const wages ii = 10000;
	dou dd = 4.1;
	const p poi = nullptr;
	const double* poi2 = nullptr;
	//poi = &i;//此句报错表达式必须是可以修改的左值，
	//说明类型const p定义的指针不是指向常量的指针，实际上是常量指针，一旦确定指向的常量就不改变指向
	//所以const p poi=nullptr;
	//不能看作const double *poi;从而将poi视为指向常量的指针。
	//其原因是*作为类型修饰和double是一个整体，const p就是指double*这个类型的指针不能改变
	//const修饰的部分包含指针，所以指针是常量指针。
	//一般的这种语句：const double *poi;
	//const修饰的只是double
	poi2 = &ii;
	
	//2.5.2auto类型说明符，C++11新标准
	// 顶层const会被忽略
	// 底层const根据指向的是否是常量推测
	// 
	//课后练习习题
	// 2.33验证
	//int i = 0, & r = i;
	//auto a = r;
	//const int ci = i, & cr = ci;
	//auto b = ci;
	//auto c = cr;
	//auto d = &i;
	//auto e = &ci;
	//const auto f = ci;
	//auto& g = ci;
	////auto& h = 42;//错误：不能为非常量引用绑定字面值，42的推演类型是int，所以编译器只能推测是auto是int&类型，然后编译时会报错普通引用引用了常量，42换成标识符表示的常量可以通过
	//const auto& j = 42;
	//a = 42;
	//b = 42;
	//c = 42;
	////d = 42;//错误，指针不能绑定常量
	////e = 42;//错误，同上
	////g = 42;//错误，g绑定的是常量

	//2.35
	const int i = 42;
	auto j = i;//int
	const auto& k = i;//const int&
	auto* p = &i;//const int *
	const auto j2 = i, & k2 = i;

	//2.5.3decltype类型指示符，c++11新标准
	//引用一般作为所引用对象的同义词出现，但用在decltype处是个例外
	//decltype会提取引用的引用类型给后面的变量
	int i2 = 10;
	int& yin = i2;
	decltype(yin) aa = yin;//aa是int&类型
	//把引用放入表达式，decltype将不返回引用，只返回基本类型
	decltype(yin + 0) bb = yin;//bb的类型是int，yin+0是一个表达式
	//！！decltype(*p)这样对指针的解引用返回的类型是对应基本类型的引用类型
	//为括号内的变量加上一层或多层括号，编译器会把该变量当成表达式
	//变量是一种可以作为赋值语句左值的特殊表达式，decltype会返回引用类型
	decltype((i2)) i3 = i2;//i3的类型是int&
	(i2) = 11;//(i2)就算可以被视为表达式，也是可以赋值的
	
	//习题2.36，最终结果全是4
	int a2 = 3, b2 = 4;
	decltype(a2) c2 = a2;//int
	decltype((b2)) d2 = a2;//int&
	++c2;
	++d2;
	cout << "a2=" << a2 << ",b2=" << b2 << endl;
	cout << "c2=" << c2 << ",d2=" << d2 << endl;
	//习题2.37和2.38
	//decltype和auto判断类型有区别时
	//情况1，使用了表达式
	decltype(a2 = b2) e2 = a2;//!!a2=b2的类型是int&
	auto f2 = (a2 = b2);//ff的类型是int，所以auto和decltype的区别可以看出在于使用表达式时
	//情况2，使用了引用
	int& l2 = a2;
	decltype(l2) m2 = a2;//m2是int&类型
	auto n2 = a2;//n2是int类型
	//decltype和auto判断类型没有区别时
	decltype(a2) g2 = a2;//g2是int类型
	auto h2 = a2;//h2是int类型

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
