// chapter3.1using_3.2string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
//3.1 using声明
//单独声明某个需要的名字，每个名字要单独声明，不能同时声明多个，每个名字声明用分号隔开
using std::cout;
using std::cin;
using namespace std;
//头文件的内容会拷贝到所有引用该头文件的文件中去
//using声明也会被拷贝
// 位于头文件中的代码一般来说不应该使用using声明，很容易被意外引用
//！！如果同一个名字出现在两个名字空间然后被意外使用using声明时，就会出现报错

int main()
{
    //3.2string
    //string由于是一个对象，所以对象能用的初始化它也能用
    //有等号的是拷贝初始化
    string str = "test string1";//拷贝初始化
    string str2("test string2");
    string str3 = str;//这是拷贝初始化，因为str会先被拷贝到新建的一个
    string str4(str);
    string str5;//这样写默认初始化为空串，虽然是在函数体内部
    cout << str5 << endl;//可以访问str5
    string str6();//这样写没有初始化，和str5原理不一样，！！！不清楚原因
    //cout << str6 << endl;
    string str7(5, 'c');//这一条语句第二个参数不能是字符串，否则报错。它的含义是创建一个5个c构成的字符串
    cout << str7 << endl;
    string str8 = string(3, 'd');//这样写实现了多个字符构成一个字符串的拷贝初始化，但可读性较差
    //上一行代码实际执行的操作是
    /*string temp(3, 'd');
    string str8 = temp;*/

    //3.2.2string对象上的操作
    //在此只写出不熟悉的
    //1.getline(istream,s)//从is对象读取一行给s，然后返回is对象
    //会读取换行符
    //endl会刷新缓冲区
    string line;
    while (getline(cin,line))
    {
        cout << line << endl;
    }

    //2.s.empty();//s为空返回true，反之返回false
    // 
    //3.s.size();//返回s中的字符个数
    // size函数返回一个string::size_type类型的值，是一个无符号整型数，而不是int或者是unsigned
    // size_type类型的声明使用string::size_type，不是std，因为size_type是在string类中定义的
    //size返回的是无符号整型数，所以参与计算时混入了带符号数会产生意想不到的结果，
    //比如s.size()<n（n是负的整型数）的返回结果肯定是true，用汇编的知识想想n会转换成什么值吧 
    //所以表达式中有size时就不要使用int类型的值了
    auto len = line.size();//len的类型是string::size_type

    //4.s[n]返回对应索引的引用
    //5.s1+s2//连接s1和s2，返回连接结果
    //字符串字面值和string是不同类型，字符和字符串字面值可以转换为string
    str = str + ',' + str2 + ",test text";
    //但要确保+两边至少有一个string类型对象
    //str = "hello" + '!';//错误写法
    //cout << str << endl;//编译不报错，但输出的是Lock
    str = str + ":hello" + '!';//正确的写法，原因是第一个+返回string对象以便连续运算

    //6.大于小于等逻辑运算符，利用字符在字典中的顺序进行比较，且对字母的大小写敏感
    //长度不同，但对应位置字符相同的两个字符串，大小由长度决定
    //字符存在不同，由第一对不同的字符比大小的结果决定字符串的大小

    //3.2.3处理string对象中的字符
    //这些处理由cctype头文件中的函数执行
    /*
    *isalnum()  如果参数是字母数字，即字母或者数字，函数返回true
    *isalpha()  如果参数是字母，函数返回true
    *iscntrl()  如果参数是控制字符，函数返回true
    *isdigit()  如果参数是数字（0－9），函数返回true
    *isgraph()  如果参数是除空格之外的打印字符，函数返回true
    *islower()  如果参数是小写字母，函数返回true
    *isprint()  如果参数是打印字符（包括空格），函数返回true
    *ispunct()  如果参数是标点符号，函数返回true
    *isspace()  如果参数是标准空白字符，如空格、换行符、水平或垂直制表符，函数返回true
    *isupper()  如果参数是大写字母，函数返回true
    *isxdigit() 如果参数是十六进制数字，即0－9、a－f、A－F，函数返回true
    *tolower()  如果参数是大写字符，返回其小写，否则返回该参数
    *toupper()  如果参数是小写字符，返回其大写，否则返回该参数
    */
    //C++版本的标准库文件没有.h后缀，建议使用这个版本，比如name.h对应cname
    //C++版本的标准库文件的名字都定义在std命名空间中
    
    //范围for语句，每次迭代c会变成str下一个字符
    for (auto c : str)
        cout << c << endl;
    //使用范围for语句改变字符串中的字符，循环变量必须设置为引用
    for (auto& c : str)
        c = toupper(c);
    cout << str << endl;
    //不想依次访问，就使用索引访问对应的字符
    //[]中的索引的类型是string::size_type
    //下标必须大于0小于s.size()
    //访问时检测下标合法性，可以将下标类型设为string::size_type类型，然后保证小于s.size()即可

    //3.2.3练习
    //3.6 3.7
    string s = "test";
    //for (auto &c : s)
    //3.7循环变量改为char不影响结果
    for (char &c : s)
    {
        c = 'X';
    }
    cout << s << endl;
    //3.8
    s = "test2";
    string::size_type n = 0;
    while (n<s.size())
    {
        s[n] = 'X';
        n++;
    }
    cout << s << endl;
    s = "test3";
    for (string::size_type i = 0; i < s.size(); i++)
    {
        s[i] = 'X';
    }
    cout << s << endl;
    //范围for处理带索引的类型比较方便

    //3.9
    //string s1;
    //cout << s1[0] << endl;//这两行会输出s1第一个字符，虽然没报错，但这样写不合法，会引发意想不到的后果

    //3.10
    string s3 = "a,b,c,d";
    for (auto &c:s3)
    {
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
    //3.11
    //c的类型是const char&
    const string s4 = "Keep out!";
    for (auto& c : s4)
    {
        cout << c;
    }
    cout << endl;
    return 0;
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
