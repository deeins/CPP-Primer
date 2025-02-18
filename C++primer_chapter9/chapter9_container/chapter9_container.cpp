// chapter9_container.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <forward_list>
#include <fstream>
#include <stack>
using namespace std;

//9.28
void find_insert(forward_list<string> &flist, const string &str, const string &str2)
{
    forward_list<string>::iterator prev = flist.before_begin(),
        curr = flist.begin();
    while (curr != flist.end())
    {
        if (*curr == str)
        {
            //找到了
            flist.insert_after(curr, str2);
            return;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
    //没找到
    flist.insert_after(prev, str2);
}

//9.43
void my_assign(string& s, const string& old_val, const string& new_val)
{
    string tmp;
    //int cnt = 0;
    //居然忘了for循环的顺序...第一个循环后的循环的顺序：条件，循环体，初始值更新，这导致后面的beg+=那里要-1，因为循环体后立即执行初始值更新
    for (auto beg = s.begin(); beg != s.end(); ++beg)
    {
        tmp.assign(beg, beg + old_val.size());
        if (tmp == old_val)
        {
            beg = s.erase(beg, beg + old_val.size());//迭代器范围都支持左闭右开
            beg = s.insert(beg, new_val.begin(), new_val.end());
            beg += new_val.size()-1;
            ////检验是否经过end
            //if (beg == s.end())
            //    cout << "beg has been equal to end" << endl;
        }
        //++cnt;
    }
    //cout << "cnt=" << cnt << endl;
}

//9.44
void my_replace(string& s, const string& old_val, const string& new_val)
{
    //size是从1开始，下标是从0开始，最后在逻辑上下标i移动到了\0的位置，在执行表达式3后会指向\0的下一位，而size返回的值比最大下标大1，i不执行表达式3就已经与size相等了，所以size要+1
    for (string::size_type i = 0;i != s.size()+1;++i)
    {
        string tmp(s,i,old_val.size());
        //cout << tmp << endl;
        if (tmp == old_val)
        {
            s.replace(i, old_val.size(), new_val);
            i += new_val.size();
            cout << "i=" << i << endl;
            cout << "s.size()" << s.size() << endl;
        }
    }
}

//9.45
string& insert_pre_end(string& s, const string& pre, const string& end)
{
    s.insert(s.begin(), pre.begin(),pre.end());
    s.append(end.begin(),end.end());
    return s;
}

//9.46
string& insert_pre_end2(string& s, const string& pre, const string& end)
{
    s.insert(0, pre);
    //作为下标，s.size()表示空字符位置，所以不需要+1就能在空字符前插入元素了
    s.insert(s.size(), end);
    return s;
}

//9.51
class Date
{
public:
    Date():year(2000),month(1),day(1) {}
    Date(string date);
    void print_date();
private:
    unsigned year, month, day;
    static vector<string> months;
    static string numbers;
};
vector<string> Date::months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
string Date::numbers{"0123456789"};
Date::Date(string date)
{
    cout << "Date constructor working" << '\n';
    int pos = 0;
    for (auto i = 0; i != 12; ++i)
    {
        if (date.find(months[i]) != string::npos)
        {
            month = i + 1;
            pos = date.find_first_of(numbers, pos);
            day = stoi(date.substr(pos++));
            //数字通常不会连在一起，所以移动下标两次可以跳过两位数的情况，另外年份是最后出现，所以不用考虑它的情况
            ++pos;
            pos = date.find_first_of(numbers, pos);
            year = stoi(date.substr(pos));
            return;
        }
    }
    //全是数字时
    pos = date.find_first_of(numbers, pos);
    month = stoi(date.substr(pos++));
    ++pos;
    pos = date.find_first_of(numbers, pos);
    day = stoi(date.substr(pos++));
    ++pos;
    pos = date.find_first_of(numbers, pos);
    year = stoi(date.substr(pos));
}

void Date::print_date()
{
    cout << year << '/' << month << '/' << day;
}

int main()
{
    //9.17
    list<int> ilist{1, 2, 9};
    vector<int> ivec{1, 2, 8, 9, 10};
    vector<int> ivec2(ilist.begin(), ilist.end());
    if (ivec2 == ivec)
        cout << "两容器相等" << endl;
    else
        cout << "两容器不等" << endl;

    ////9.18
    //deque<string> sdeq;
    //string str;
    //while (cin>>str)
    //{
    //    sdeq.push_back(str);
    //}
    //for (deque<string>::iterator beg = sdeq.begin(); beg < sdeq.end(); ++beg)
    //{
    //    cout << *beg << ' ';
    //}
    //cout << "\n";

    //9.19
    list<string> slist;
    string str2;
    while (cin>>str2)
    {
        slist.push_back(str2);
    }
    for (list<string>::iterator beg = slist.begin(); beg != slist.end(); ++beg)
    {
        cout << *beg << ' ';
    }
    cout << "\n";

    //9.20
    list<int> ilist2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> ideq, ideq2;
    for (list<int>::iterator beg = ilist2.begin(); beg != ilist2.end(); ++beg)
    {
        if (*beg % 2 != 0)
            ideq.push_back(*beg);
        else
            ideq2.push_back(*beg);
    }
    for (deque<int>::iterator beg = ideq.begin(); beg != ideq.end(); ++beg)
    {
        cout << *beg << ' ';
    }
    cout << "\n";
    for (deque<int>::iterator beg = ideq2.begin(); beg != ideq2.end(); ++beg)
    {
        cout << *beg << ' ';
    }
    cout << "\n";

    //9.22
    vector<int> iv(ivec);
    vector<int>::iterator iter = iv.begin(),
        mid = iv.begin() + iv.size() / 2;
    int some_val = 2;
    while (iter!=mid)
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, some_val * 2) + 1;
            mid = iv.begin() + iv.size() / 2;
            cout << *iter << endl;
        }
        else
        {
            ++iter;
        }
    }
    for (auto c : iv)
        cout << c << ' ';
    cout << endl;

    //9.24
    ivec = {};
    //cout << *ivec.begin() << endl;
    //cout << ivec[0] << endl;//越界产生未定义行为
    //cout << ivec.at(0) << endl;//越界抛出异常
    //cout << ivec.front() << endl;

    //9.25
    ivec = { 1,2,2,3,4,5,5,6,6 };
    //erase的参数为两个相同迭代器时什么都不删除，返回值为放入的参数
    vector<int>::iterator it = ivec.begin(), it2 = ivec.begin(), it3 = ivec.erase(it, it2);
    cout << ivec.at(0) << endl;
    cout << *it3 << endl;

    //9.26
    int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
    vector<int> iavec(begin(ia), end(ia));
    list<int> ialist(begin(ia), end(ia));
    list<int>::iterator ia_iter = ialist.begin();
    cout << "ialist:";
    while (ia_iter!=ialist.end())
    {
        if (*ia_iter % 2 != 0)
            ia_iter = ialist.erase(ia_iter);
        else
            ++ia_iter;
    }
    for (auto c : ialist)
        cout << c << ' ';
    cout << "\n";
    vector<int>::iterator ia_iter2 = iavec.begin();
    while (ia_iter2!=iavec.end())
    {
        if (*ia_iter2 % 2 == 0)
            ia_iter2 = iavec.erase(ia_iter2);
        else
            ++ia_iter2;
    }
    cout << "iavec:";
    for (auto c : iavec)
        cout << c << ' ';
    cout << '\n';

    //9.27
    //删除奇数
    forward_list<int> iflist{1, 2, 3, 4, 5, 6, 7};
    forward_list<int>::iterator prev = iflist.before_begin(),
        curr = iflist.begin();
    while (curr!=iflist.end())
    {
        if (*curr % 2 != 0)
            curr = iflist.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }
    cout << "iflist:";
    for (auto c : iflist)
        cout << c << ' ';
    cout << '\n';

    //9.28
    forward_list<string> sflist{"abc", "def", "g", "hi", "jk"};
    find_insert(sflist, "hi", "123");
    find_insert(sflist, "none", "456");
    cout << "sflist:";
    for (auto c : sflist)
        cout << c << ' ';
    cout << '\n';

    //9.31
    list<int> li = { 0,1,2,3,4,5,6,7,8,9 };
    auto li_iter = li.begin();
    while (li_iter != li.end())
    {
        if (*li_iter % 2)
        {
            li_iter = li.insert(li_iter, *li_iter);
            ++(++li_iter);//list的迭代器不支持算术运算与大于小于，但支持递增递减和不等相等
        }
        else
        {
            li_iter = li.erase(li_iter);
        }
    }
    cout << "li:";
    for (auto c : li)
        cout << c << ' ';
    cout << '\n';
    
    forward_list<int> fli = { 0,1,2,3,4,5,6,7,8,9 };
    auto fli_iter = fli.begin(), fli_prev = fli.before_begin();
    while (fli_iter != fli.end())
    {
        if (*fli_iter % 2)
        {
            //此处不用重新定位迭代器
            fli.insert_after(fli_prev, *fli_iter);//在放入的迭代器之后插入元素，所以下一行只加一
            (++fli_iter);
            ++(++fli_prev);
        }
        else
        {
            fli_iter = fli.erase_after(fli_prev);//删除有必要重新定位迭代器，因为有迭代器指向被删除的元素
        }
    }
    cout << "fli:";
    for (auto c : fli)
        cout << c << ' ';
    cout << '\n';

    //9.43
    string str("tho tho");
    str2 = str;
    cout << "my_assign:";
    my_assign(str, "tho", "though");
    cout << str << '\n';
    cout << "my_replace:";
    my_replace(str2, "tho", "though");
    cout << str2 << '\n';

    //9.45
    str = "Joe";
    str2 = str;
    cout << insert_pre_end(str, "Mr.", "III") << '\n';
    //9.46
    cout << insert_pre_end2(str2, "Mr.", "III") << '\n';

    //9.47
    string wait_find("ab2c3d7R4E6"), numbers("0123456789");
    string::size_type pos = 0;
    while ((pos=wait_find.find_first_of(numbers,pos))!=string::npos)
    {
        cout << "数字" << wait_find[pos] << "出现在下标为" << pos << "处" << endl;
        ++pos;
    }
    string alph("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    //for (char c = 'a';c < c + 26;++c)
    //{
    //    alph = alph + c;
    //    cout << c << endl;
    //}
    //for (char c = 'A';c < c + 26;++c)
    //{
    //    alph = alph + c;
    //}
    pos = 0;
    while ((pos=wait_find.find_first_of(alph,pos))!=string::npos)
    {
        cout << "字母" << wait_find[pos] << "出现在下标为" << pos << "处" << endl;
        ++pos;
    }

    //9.49
    ofstream word_list("words.txt");
    word_list << "apple banana emo ann joe anna temptation";
    string upalph("bdfhijklt"), downalph("gjpqy"), normalph("acemnorsuvwxz");
    ifstream words("words");
    string word, max_word;
    size_t len = 0;
    while (words >> word)
    {
        if (word.find_first_of(upalph) == string::npos && word.find_first_of(downalph) == string::npos)
        {
            if (word.size() > len)
            {
                len = word.size();
                max_word = word;
            }
        }
    }
    cout << "既不包含上出头部分也不包含下出头部分的单词中，最长的是" << max_word << '\n';

    //9.50
    vector<string> num_svec = { "1","9","8.5","1.5" };
    int sum = 0;
    for (const auto n : num_svec)
        sum += stoi(n);
    cout << "num_svec中的元素转换为整型后的和为" << sum << '\n';
    double dsum = 0;
    for (const auto n : num_svec)
        dsum += stod(n);
    cout << "num_svec中的元素转换为浮点型后的和为" << dsum << '\n';

    //9.51
    Date nice_day("January 1,1900");
    nice_day.print_date();
    cout << '\n';
    //默认初始化不要带函数调用符()，那样是声明一个函数类型
    Date default_day;
    default_day.print_date();
    cout << '\n';
    Date all_num_day("8 27 2023");
    all_num_day.print_date();
    cout << '\n';
    Date all_num_day2("8/27/2023");
    all_num_day2.print_date();
    cout << '\n';

    //9.52
    stack<char> cstack;
    stack<double> dstack;
    string expression = "(10+8*2) (17+6) (1+9)";
    auto expr_beg = expression.begin();
    auto expr_end = expression.end();
    //while (expr_beg != expr_end)
    //{
    //    if (*expr_beg == '(')
    //    {
    //        int pos = 0;
    //        while (*expr_beg != ')')
    //        {
    //            if (isdigit(*expr_beg))
    //                dstack.push(stod(&*expr_beg));
    //            else if (*expr_beg == '*')

    //            else
    //                cstack.push(*expr_beg);
    //            cstack.push(*expr_beg);
    //        }
    //    }
    //}

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
