// draw_line.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

struct Pos {
    float x = 0;
    float y = 0;
    Pos(float, float);
};

Pos::Pos(float x1,float y1)
    :x(x1),y(y1){}

struct color
{
    float c0 = 0;
    float c1 = 0;
    float c2 = 0;
};

void draw_point(Pos pos, color c);

void mid_point_line(Pos pos1, Pos posn,color c)
{
    int dy = posn.y - pos1.y;
    int dx = posn.x - pos1.x;
    int d = dx - 2 * dy;
    int dt = 2 * dx - 2 * dy;
    int db = -2 * dy;
    int x = pos1.x, y = pos1.y;
    while (x < posn.x)
    {
        draw_point(Pos(x, y), c);
        if (d < 0)
        {
            d += dt;
            ++x;
            ++y;
        }
        else
        {
            d += db;
            ++x;
        }
    }
    if (x = posn.x)
        draw_point(posn, c);
}

int main()
{
    std::cout << "Hello World!\n";
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
