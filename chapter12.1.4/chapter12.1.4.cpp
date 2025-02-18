// chapter12.1.4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>

using namespace std;

struct destination
{
    char a;
    int b;
    char c;
    long long d;
};

struct connection
{
    destination* dest;
    connection(destination* destination) 
    { 
        dest = destination; 
        cout << "connect to destination" << endl;
    }
};

void disconnect(connection connect)
{
    delete connect.dest;
    cout << "disconnect" << endl;
}

//删除器，形参为对应类型的指针
void end_connect(connection* p)
{
    cout << "delector \"end_connect\" working" << endl;
    disconnect(*p);
}

int main()
{
    destination* dest = new destination();
    connection c(dest);
    shared_ptr<connection> connect(&c, end_connect);
    cout << "some operation" << endl;
    //使用lambda表达式编写删除器
    auto end_connect_lambda = [](connection* p) 
        {
            cout << "delector \"end_connect_lambda\" working" << endl; 
            disconnect(*p); 
        };
    destination* dest2 = new destination();
    connection c2(dest2);
    shared_ptr<connection> another_connect(&c2, end_connect_lambda);
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
