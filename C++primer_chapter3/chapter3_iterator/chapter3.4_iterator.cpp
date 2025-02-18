// chapter3_iterator.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//迭代器

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	//3.4.1
	//所有标准库容器都可以使用迭代器，
	// 但少数才能使用下标运算符，比如vector。
	// string对象虽然不是容器，但也可以使用迭代器
	// 迭代器提供了对对象的间接访问
	// 有效的迭代器指向元素，或者尾元素的下一位置
	//
	//迭代器类型拥有成员begin和end
	// begin返回指向第一个元素的迭代器
	// end返回指向尾元素下一位置的迭代器，被称为尾后迭代器
	// 它们可以使用递增递减运算符，指向下一个或上一个元素
	//
	vector<string> ivec = { 10,"hi"};
	//迭代器常用auto声明，因为我们常常不在意迭代器的类型，它的类型是对应类中定义的类型，
	//比如vector的迭代器类型可以为vector<int>::iterator,
	auto it = ivec.begin();
	int cnt = ivec.end() - it;//这一句可以得到容器的大小
	//迭代器的操作
	it++;//1.it指向下一个元素，可分为4种
	if (ivec.begin() != ivec.end())//此语句可以判断容器是否为空
		cout << "ivec不为空" << endl;
	cout << "迭代器it指向的元素为" << *it << endl;//2.*it返回迭代器所指元素的引用
	//3.->是箭头运算符，(*it).men等效于it->men
	cout << "使用迭代器访问向量的成员size()，返回长度" << it->size() << endl;
	//4.迭代器还有==和!=的操作，判断两个迭代器是否一样
	//添加向量元素的操作会让迭代器失效

	//int arr[10] = { 0 };
	//auto it = arr.begin();//数组不能用迭代器

	//3.4.2
	//所有容器都定义了!+和==操作
	//vector和string多定义了一部分迭代器运算
	//iter+n
	//iter-n
	//iter+=n
	//iter-=n
	//iter1-iter2
	//> < >= <=反映迭代器的位置关系
	//迭代器的距离由两个迭代器相减得到，其类型为difference_type，定义在vector和string中
	//该类型可正可负

	//使用迭代器运算的一个经典算法是二分算法
	vector<int> sear_vec = { 1,2,3,4,5,6,7,8,9,10 };
	auto beg = sear_vec.begin(),end=sear_vec.end();
	//通过为指向第一个元素的迭代器加上对象长度的一半得到指向对象中间元素的迭代器mid
	auto mid = beg + sear_vec.size() / 2;
	int sought;
	cout << "请输入带查找的数：";
	cin >> sought;
	while (sought!=*mid&&beg<end)
	{
		if (sought>*mid)
		{
			beg = mid + 1;
		}
		else
		{
			end = mid;
		}
		mid = beg + (end - beg) / 2;
		//mid=(beg+end)/2
		//不使用上一行的原因是vector中没有定义迭代器相加的操作
	}
	if (sought == *mid)
	{
		cout << "在sear_vec中找到了sought，位置是" << mid - sear_vec.begin() + 1 << endl;
	}
	else
	{
		cout << "在sear_vec中没找到sought" << endl;
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
