// chapter3.3_vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //集合是类模板，不是类型，也称为容器
    //类模板实例化的格式如下
    vector<int> ivec{1, 2, 3};//尖括号内部放的是集合存放元素的类型
    //因为集合是存放对象的，所以集合中不含引用
    //集合中能存放自定义的类对象

    vector<string> svec;//默认初始化，svec不含任何元素
    //一般使用集合都是先创建一个空集合，然后向其中放入元素
    vector<int> ivec2(ivec);//拷贝
    vector<int> ivec3 = ivec;//等效于上一行语句
    //注意，不同类型不能拷贝

    vector<string> articles = { "a","an","the" };//{}中可以存放0个或多个元素
    //使用拷贝初始化时只能提供一个初始值，这是普遍的
    //类内初始化，使用=时，只能用拷贝初始化或列表初始化

    vector<int> ivec4(10, 1);//创建十个1为元素的集合

    //1.值初始化的类型必须要是可以支持默认初始化的
    //2.只提供了元素数量，没提供初始值，只能使用直接初始化
    vector<int> ivec5(10);//值初始化，创建十个值为默认值的对象放入集合

    //列表初始化放入的是直接的集合元素，与圆括号不同
    //圆括号的第一个参数是数量
    //但如果列表初始化无法进行会检测是否能够进行，则会按圆括号规则执行
    vector<int> v1(10);//创建十个默认值对象
    vector<int> v2{10};//1个元素
    vector<int> v3(10, 1);//10个元素
    vector<int> v4(10, 2);//两个元素
    vector<string> v5{10, "hi"};//10个值为hi的元素，虽然是用花括号，但这不算列表初始化
    vector<string> v6(10, "hi");//同上

    //练习
    //3.12
    vector<vector<int>> vivec;
    vector<int> vd{10};
    //3.13
    cout << "vd[0]" << endl;
    cout << vd[0] << endl;
    vector<string> vf{10};
    cout << "vf[0]" << endl;
    cout << vf[0] << endl;

    //3.3.2向vector对象中添加元素
    //使用push_back成员函数
    //直接初始化适用于三种情况：
    //1.初始值已知且数量较少，使用列表初始化直接放入元素
    //2.初始值是另一个集合的副本，v1(v2)
    //3.所有元素初始值一样
    //但常见情况是集合内部元素数量和值都未知，即使已知数量也会很大
    //所以使用空集合然后用push_back高效添加元素
    //集合如果指定了大小性能可能更差

    //vector的编程要求
    //包含集合的循环必须准确无误，特别是添加元素时
    //添加元素时，不能使用范围for语句

    //练习
    vector<int> ivect;
    int i = 0;
    while (cin>>i)
    {
        ivect.push_back(i);
    } 

    //3.3.3
    //vector支持的操作
    //v.empty()
    //v.size()
    //v.push_back(t)
    //v[n]
    //v1=v2
    //v1={a,b,c...}
    //v1==v2
    //v1!=v2
    //逻辑运算符比大小，根据字典顺序，可以参考string的比大小

    //vector索引的类型为vector<type>::size_type
    //确保下标合法尽量使用范围for语句

    //练习
    //3.16
    vector<int> vv1;
    vector<int> vv2(10);
    vector<int> vv3(10, 42);
    vector<int> vv4{10};
    vector<int> vv5{10, 42};
    vector<string> vv6{10};
    vector<string> vv7{10, "hi"};
    cout << "vv1 ";
    cout << vv1.size() << endl;
    cout << "vv2 ";
    cout << vv2.size() << endl;
    cout << "vv3 ";
    cout << vv3.size() << endl;
    cout << "vv4 ";
    cout << vv4.size() << endl;
    cout << "vv5 ";
    cout << vv5.size() << endl;
    cout << "vv6 ";
    cout << vv6.size() << endl;
    cout << "vv7 ";
    cout << vv7.size() << endl;
    
    //3.17
    vector<string> word_vec = { "an","a","the" };
    for (auto& c : word_vec)
    {
        //toupper是处理string对象中的字符的函数，所以必须再用一个范围for语句
        for (auto& cc : c)
        {
            cc=toupper(cc);
        }
    }
    for (auto c : word_vec)
    {
        cout << c << endl;
    }

    //3.18
    //vector<int> iivec;
    //iivec[0]=42;
    //上两行语句是错误的
    vector<int> iivec;
    iivec.push_back(42);

    //3.20
    //相邻元素相加
    vector<int> int_vec = { 10,11,20,9,30 };
    if (!int_vec.empty())
    {
        int sum = int_vec[0];
        int index = 0;
        for (const auto& c : int_vec)
        {
            if (index > 0)
            {
                sum += c;
                cout << sum << ' ';
                //重置sum以便下一次循环求和
                sum = c;
            }
            index++;
        }
    }
    cout << endl;
    //首尾相加
    if (!int_vec.empty())
    {
        int sum = 0;
        for (unsigned i = 0; i < (int_vec.size() + 1)/2; i++)
        {
            sum = int_vec[i] + int_vec[int_vec.size() - 1 - i];
            cout << sum << ' ';
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
