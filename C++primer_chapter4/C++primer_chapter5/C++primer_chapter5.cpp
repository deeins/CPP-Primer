// C++primer_chapter5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char c;
	bool flag = false;
	int ffcnt = 0, flcnt = 0, ficnt = 0;
	//while (cin>>c)
	//{
	//	switch (c)
	//	{
	//	case 'f':
	//		cin >> c;
	//		switch (c)
	//		{
	//		case 'f':
	//			int k;
	//			++ffcnt;
	//			break;
	//		case 'l':
	//			k = 0;
	//			++flcnt;
	//			break;
	//		case 'i':
	//			++ficnt;
	//			break;
	//		default:
	//			break;
	//		}
	//	default:
	//		break;
	//	}
	//}
	//cout << ffcnt << endl;
	//cout << flcnt << endl;
	//cout << ficnt << endl;
	
	//switch中不能初始化变量，可以声明
	//cin >> c;
	//switch (c)
	//{
	//case 'a':
	//	int j;
	//case 'b':
	//	int k;
	//default:
	//	break;
	//}

	/*string str,tmp,max_str;
	int max = 1, cnt = 1;
	while (cin>>str)
	{
		if (tmp==str)
		{
			++cnt;
		}
		else
		{
			max = max > cnt ? max : cnt;
			max_str = max > cnt ? max_str : tmp;
			cout << 1 << endl;
			cout << max_str << endl;
			cnt = 1;
		}
		tmp = str;
	}
	cout << max_str << endl;
	cout << max << endl;
	int sz = 10;
	for(int ix=0;ix!=sz;++ix,++sz){}*/

	//vector<int> ivec1{0, 0, 2}, ivec2{ 0,1,2,3,4 };
	//vector<int> shorter = ivec1.size() < ivec2.size() ? ivec1 : ivec2;
	//vector<int> longer = ivec1.size() > ivec2.size() ? ivec1 : ivec2;
	//for (int i = 0; i < shorter.size(); i++)
	//{
	//	if (shorter[i] != longer[i])
	//		return 0;
	//}
	//return 1;

	//5.6.3节练习
	int s1, s2;
	while(cin >> s1 >> s2)
	{
		try
		{
			//抛出异常
			if (s2 == 0)throw runtime_error("第二个输入的数不能为0");
			//try中遇到异常就会跳到catch中处理异常，try内部不会执行异常之后的代码
			//下一行就不会在抛出异常后执行
			cout << s1 / s2 << endl;
		}
		//处理异常
		catch (runtime_error err)
		{
			cout << err.what()
				<< "\n再次输入？y or n:";
			char c;
			cin >> c;
			if (c == 'n')
				break;
		}
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
