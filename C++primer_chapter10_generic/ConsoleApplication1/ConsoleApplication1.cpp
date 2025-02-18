// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include "Sales_data.h"
#include <forward_list>
#include <deque>
using namespace std;
//声明这个命名空间时要带上头文件functional
using namespace placeholders;

//10.11
bool is_shorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

//10.9
void elim_dups(vector<string>& s)
{
	sort(s.begin(), s.end());
	for (const auto c : s)
		cout << c << ' ';
	cout << '\n';
	auto unique_end = unique(s.begin(), s.end());
	for (const auto c : s)
		cout << c << ' ';
	cout << '\n';
	s.erase(unique_end, s.end());
	for (const auto c : s)
		cout << c << ' ';
	cout << '\n';
}

//10.12
bool ISBN_shorter(Sales_data& data1, Sales_data& data2)
{
	return data1.bookNo < data2.bookNo;
}

void compare_ISBN(vector<Sales_data>& data)
{
	sort(data.begin(), data.end(), ISBN_shorter);
}

//10.13
bool over_five(const string& s)
{
	return s.size() > 5;
}

//10.22
bool over_size(const string& s, vector<string>::size_type sz)
{
	return s.size() <= sz;
}

//10.24
bool check_size(const string& s, int i);

//10.16
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elim_dups(words);
	//stable_sort(words.begin(), words.end(),
	//	[](const string& a, const string& b) {return a.size() < b.size();});
	
	/*auto byd_sz = stable_partition(words.begin(), words.end(),
		[sz](const string& a) {return a.size() < sz;});*/

	//10.25
	auto byd_sz = stable_partition(words.begin(), words.end(),
		bind(check_size,_1,sz));
	//int cnt = words.end() - byd_sz;
	//int cnt = count_if(words.begin(), words.end(),
	//	[sz](const string& a) {return a.size() >= sz;});
	//10.22使用函数统计长度小于等于6的单词的数量
	int cnt = count_if(words.begin(), words.end(), bind(over_size,_1,sz));
	auto make_plural = [](int cnt, const string& word, const string& ending) {return cnt == 1 ? word : word + ending;};
	cout << cnt << ' ' << make_plural(cnt, "word", "s")
		<< " of length " << sz << " or shorter" << endl;
}

//10.24
bool check_size(const string& s, int i)
{
	return s.size() < i;
}

//10.42
void elim_dups(list<string>& words)
{
	words.sort();
	words.unique();//链表的unique会删除重复元素，通用版本的不会，只会将重复的放到后面，最后返回指向第一个重复元素的迭代器
}

int main()
{
	//10.1
	vector<int> ivec{1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 6};
	cout << "3在序列ivec中出现了" << count(ivec.cbegin(), ivec.cend(), 3) << "次\n";

	//10.2
	list<string> slist{"app", "app", "ban", "app", "ban"};
	cout << "app在slist中出现了" << count(slist.cbegin(), slist.cend(), "app") << "次\n";

	//10.3
	//accumulate函数位于头文件numeric中
	cout << "ivec中的元素之和为" << accumulate(ivec.cbegin(), ivec.cend(), 0) << '\n';

	//10.6
	fill_n(ivec.begin(), ivec.size(), 0);

	//10.9
	vector<string> s{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	for (const auto c : s)
		cout << c << ' ';
	cout << '\n';
	elim_dups(s);
	stable_sort(s.begin(), s.end(), is_shorter);
	for (const auto c : s)
		cout << c << ' ';
	cout << '\n';

	//10.12
	vector<Sales_data> data_vec;
	Sales_data item;
	while (cin >> item)
	{
		data_vec.push_back(item);
	}
	compare_ISBN(data_vec);
	sort(data_vec.begin(), data_vec.end(),
		[](const Sales_data& data1, const Sales_data& data2) {return data1.bookNo < data2.bookNo;});
	for (const auto& c : data_vec)
		cout << c << '\n';

	//10.13
	vector<string> words{"the", "quickly", "red", "fox", "jumps", "override", "the", "slowly", "red", "turtle"};
	auto par_end = partition(words.begin(), words.end(), over_five);
	words.erase(par_end, words.end());
	for (const auto& c : words)
		cout << c << ' ';
	cout << '\n';

	//10.14
	int a = 10, b = 20;
	auto sum_val = [](const int& a, const int& b)->int {return a + b;};
	cout << sum_val(a, b) << '\n';

	//10.15
	auto sum_val2 = [a](const int& b)->int {return a + b;};
	cout << sum_val2(b) << '\n';

	//10.16
	words = { "the", "quickly", "red", "fox", "jumps", "override", "the", "slowly", "red", "turtle" };
	biggies(words, 5);
	cout << "biggies:\n";
	for (const auto& c : words)
		cout << c << ' ';
	cout << '\n';

	//10.21
	int dec_tester = 9;
	auto dec_val_tozero = [&]() {return dec_tester-- != 0 ? true : false;};
	while (dec_val_tozero())
	{
		cout << dec_tester << ' ';
	}
	cout << '\n';

	//10.22
	ivec = {};
	for (int i = 0;i < 10;++i)
	{
		ivec.push_back(i);
	}
	string check_s = "banana";
	auto sz_over = find_if(ivec.begin(), ivec.end(), bind(check_size, check_s, _1));
	cout << "第一个长度大于" << check_s << "的整型数据值为" << *sz_over << '\n';

	//10.27
	list<int> ilist{1, 2, 3};
	unique_copy(ivec.cbegin(), ivec.cend(), inserter(ilist,ilist.begin()));
	for (const auto& c : ilist)
		cout << c << ' ';
	cout << '\n';

	//10.28
	ilist = {};
	list<int> ilist2;
	deque<int> ideq;
	copy(ivec.cbegin(), ivec.cend(), inserter(ilist,ilist.begin()));
	copy(ivec.cbegin(), ivec.cend(), back_inserter(ilist2));
	copy(ivec.cbegin(), ivec.cend(), front_inserter(ideq));
	for (const auto& c : ilist)
		cout << c << ' ';
	cout << '\n';
	for (const auto& c : ilist2)
		cout << c << ' ';
	cout << '\n';
	for (const auto& c : ideq)
		cout << c << ' ';
	cout << '\n';

	//10.30
	cout << endl;
	istream_iterator<int> in_iter(cin), eof;
	vector<int> ivec2(in_iter, eof);
	for (const auto& c : ivec2)
		cout << c << ' ';
	cout << '\n';
	//istream_iterator<int> in_iter2(cin);
	//vector<int> ivec3(in_iter2, eof);

	//10.34
	auto riter = ivec.rbegin();
	cout << 10.34 << ':';
	for (;riter != ivec.rend();++riter)
	{
		cout << *riter << ' ';
	}
	cout << '\n';

	//10.35
	cout << 10.35 << ':';
	for (auto end = ivec.end()-1;end != ivec.begin();--end)
	{
		cout << *end << ' ';
	}
	cout << *ivec.begin();
	cout << '\n';

	//10.36
	ilist={1, 2, 0, 3};
	auto pos = find(ilist.crbegin(), ilist.crend(), 0);

	//10.37
	//反向迭代器练习
	ostream_iterator<int> out_iter(cout, " ");
	vector<int>::reverse_iterator rivec_end(ivec.begin() + 2);
	vector<int>::reverse_iterator rivec_beg(ivec.begin() + 8);
	list<int> ilist3;
	copy(rivec_beg, rivec_end, back_inserter(ilist3));
	copy(ilist3.begin(), ilist3.end(), out_iter);
	//for (const auto& c : ilist3)
	//	cout << c << ' ';
	cout << '\n';

	//参数为目的迭代器，如果放入普通容器的迭代器，那么复制的值会覆盖原有元素，如果放入插入迭代器或输出流迭代器，则是添加元素到当前位置
	copy(ivec.begin(), ivec.end(), out_iter);
	cout << '\n';
	copy(ilist.begin(), ilist.end(), ivec.begin());
	copy(ivec.begin(), ivec.end(), out_iter);
	cout << '\n';

	//10.42
	slist = { "apple","pen","slow","apple","banana","pen","quick","tik" };
	elim_dups(slist);
	for (const auto& c : slist)
		cout << c << ' ';
	cout << '\n';
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
