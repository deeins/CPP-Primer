// C++primer_chapter4_expression.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>
using namespace std;

int main()
{
	//4.2节
	cout << "4.5" << endl;
	int i = -30 / 3 * 21 % 4;
	cout << "i=" << i << endl;

	//4.4节
	cout << "4.14" << endl;
	//if (42 = i);//报错
	if (i = 42);

	cout << "4.15" << endl;
	double dval;
	int ival;
	int* pi=0;
	dval = ival = 0;//指针赋值后返回对象本身
	cout << dval << endl;
	cout << ival << endl;
	//cout << *pi << endl;
	//pi = ival = dval = 0;//错误改法

	//132页疑问测试
	//i++ = 1;//后置递增不能作为左值
	//因为后置递增返回的是一个原始对象的副本，
	//实际上执行完++后，原始对象已经进行了+1操作

	++i = 1;//前置递增返回递增后的对象，可以作为左值

	//4.5
	cout << "4.19" << endl;
	ival++ && ival;
	vector<int> vec(10, 0);
	(vec[ival++] <= vec[ival]);
	vec[++ival] <= vec[++ival];
	cout << i << ' ' << ++i << endl;
	++ival + (++ival);
	for (auto& c : vec)
		cout << c << ' ';
	cout << endl;
	
	//4.6
	cout << "4.20" << endl;
	vector<string>::iterator iter;
	vector<string> svec(10, "hi");
	iter = svec.begin();
	*iter++;
	//(*iter)++;//string没有++操作
	//*iter.empty();//括号
	iter->empty();
	//++*iter;//string没有++操作
	iter++->empty();

	//4.7
	cout << "4.21" << endl;
	vector<int> ivec;
	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}
	for (auto c : ivec)
	{
		c = c % 2 ? c * 2 : c;
		cout << c << ' ';
	}
	cout << endl;

	cout << "4.22" << endl;
	int grade;
	cin >> grade;
	//if版本分支划分要明显一点，条件运算符版本光是判断分支就已经很麻烦了，
	//此处的条件运算符表达式比较有规律，
	//但如果把条件写得更复杂些，条件运算符的真假都有自己的分支
	//那可读性就更差了
	cout << (grade > 90 ? "high pass" : grade > 75 ? "pass" : grade > 60 ? "low pass" : "fail") << endl;
	if (grade > 90)
		cout << "high pass";
	else if (grade > 75)
		cout << "pass";
	else if (grade > 60)
		cout << "low pass";
	else
		cout << "fail";
	cout << endl;

	cout << "4.23" << endl;
	string s = "word";
	//下一行语句由于+的优先级大于==，所以与's'比较的是一个字符串
	//这条语句本来是想用s的最后一个字符与's'比较的
	//所以修改方式是加一个括号
	//string pl = s + s[s.size() - 1] == 's' ? "" : "s";
	string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
	cout << pl << endl;

	cout << "4.24" << endl;
	/*
	*条件运算符是右结合律的，
	* 所以会优先计算右边的值，
	* 联想一下同样是右结合律的=就能理解了。
	* 如果改成左结合律，
	* 那么会优先计算左边的表达式，
	* 计算完后，返回右侧表达式的值，
	* 这个值需要是已知的，
	* 所以如果有嵌套条件运算符，
	* 第二个条件运算符的条件可能会被当成第一个的返回值，
	* 第一个条件运算符的结果（无论哪个分支）都会作为第二个条件运算符的条件，
	* 所以无法输出第一个条件运算符的结果作为整个条件运算符嵌套语句的结果
	*/
	//比如这一句只能返回"fail""pass"，不能返回"high pass"
	//"high pass"和(grade<60)会作为第一个条件运算符的返回值
	string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";

	cout << "4.9节" << endl;
	cout << setiosflags(ios::fixed) << setprecision(32) <<bitset<10>('q'<<6) << endl;
	cout << bitset<10>('@') << endl;
	cout << char('q' << 6) << endl;
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
