// chapter11_associative_container.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <set>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <ostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
using namespace std;

//11.4
//传入的字符不是字母返回1
bool not_alph(const char &c)
{
    return !(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

int main()
{
    //单词计数器，可以忽略标点和大小写，输出小写形式，单词后直接跟一个标点、跟一个标点和一个单词的情况都可以统计
    cout << 11.3 << endl;
    set<string> word_list = { "a","an","the","or","and",
                            "A","An","The","Or","And" };
    string word;
    map<string, size_t> word_count;
    string anther_word;
    string::iterator not_need;
    while (cin>>word)
    {
        //find_if接受一个一元谓词，返回第一个传入谓词返回非0的元素的迭代器
        not_need = find_if(word.begin(), word.end(), not_alph);
        //只有一个标点 时去除标点
        if (word.end()-not_need == 1 || not_need == word.end())
        {
            //这种写法的参数是一个迭代器，会删除该迭代器指向的一个元素
            word.erase(not_need);
            //如果只有一个非字母的字符，那么在被删除后值为""，此时不用执行后续语句
            if (word == "")continue;
            //全变为小写
            for (auto &c : word)
                c=tolower(c);
        }
        //当标点后面有字母时返回一个新的单词
        else
        {
            anther_word = string(not_need + 1, word.end());
            //全变为小写
            for (auto &c : anther_word)
                c=tolower(c);
            //去除常用的单词后，为单词计数加1
            if (word_list.find(anther_word) == word_list.end())
                ++word_count[anther_word];
            //这种写法会删除一个范围的元素
            word.erase(not_need,word.end());
        }
        if(word_list.find(word)==word_list.end())
            ++word_count[word];
    }
    //输出单词出现次数
    for(const auto &c:word_count)
        cout << "The word " << c.first << " occurs " << c.second << " times" << endl;
    cout << endl;


    cout << 11.7 << endl;
    map <string, vector <pair<string,string>> > family{ {"James",{}},{"Black",{}},{"Smith",{}} };
    string family_name,first_name,birthday;
    //模拟输入
    vector<string> name = { "Joe","James","11.2","Joe","Smith","11.2","Joe","Black","11.2","Jack","Blow","11.2","Alex","Blow","11.2","Alex","James","11.2"};
    for (auto iter = name.begin(); iter != name.end(); ++iter)
    {
        first_name = *iter;
        family_name = *(++iter);
        birthday = *(++iter);
        //可以添加没有的元素，说明有了关键字会默认初始化值
        family[family_name].push_back({ first_name,birthday });
    }
    for (const auto& c : family)
    {
        cout << "family of " << c.first << " have " << c.second.size() << " persons ,they are:";
        for (const auto& p : c.second)
            cout << p.first << ' ';
        cout << ".Their birthday is:";
        for (const auto& p : c.second)
            cout << p.second << ' ';
        cout << endl;
    }


    //向vector中放入不重复的元素。与vector对比起来，set对于这种情况非常好处理
    cout << 11.8 << endl;
    vector<string> no_repeat_wordvec;
    auto name_iter = name.begin();
    while (name_iter != name.end())
    {
        if (find(no_repeat_wordvec.begin(), no_repeat_wordvec.end(), *name_iter) == no_repeat_wordvec.end())
            no_repeat_wordvec.push_back(*name_iter);
        //cout << *name_iter << endl;
        ++name_iter;
    }
    ostream_iterator<string> out(cout," ");
    copy(no_repeat_wordvec.begin(), no_repeat_wordvec.end(), out);
    cout << '\n';

    //定义一个马匹，关键字为保存的单词、值为它出现行号的list
    cout << 11.9 << endl;
    map<string, list<unsigned>> word_which_line;
    string word119;
    stringstream ss,ss2;
    ifstream in_file("words.txt");
    if (in_file)cout << "file open successfully" << endl;
    unsigned line_number = 1;
    while (getline(in_file, word119))
    {
        ss << word119;
        cout << "word119:" << word119 << endl;
        //用stringstream流对象初始化输出流迭代器对象
        //！！暂时没想到不在循环内部创建输入流迭代器的方法
        istream_iterator<string> in(ss), eof;
        vector<string> word_vec(in, eof);
        //！！stringstream在循环内使用只有第一次能读取到数据，后续要调用成员函数clear才能再次读取
        ss.clear();
        int cnt = 1;
        for (auto beg=word_vec.begin();beg!=word_vec.end();++beg)
        {
            word_which_line[*beg].push_back(line_number);
            cout << cnt++ << ',';
        }
        cout << endl;
        cout << "line number is " << line_number << endl;
        ++line_number;
    }
    for (const auto& c : word_which_line)
    {
        cout << "word " << c.first << " emerge at line ";
        for (const auto& s : c.second)
        {
            cout << s << " ";
        }
        cout << endl;
    }


    cout << 11.10 << endl;
    vector<string> str_pair = { "apple","pen","banana" };
    vector<int> int_pair = { 1,2,3 };
    //pair的头文件在utility中
    vector<pair<string, int>> pair_vec;
    auto str_pair_beg = str_pair.begin();
    auto int_pair_beg = int_pair.begin();
    while(str_pair_beg!=str_pair.end())
    {
        //pair_vec.push_back(make_pair(*str_pair_beg, *int_pair_beg));
        //pair_vec.push_back(pair<string, int>(*str_pair_beg, *int_pair_beg));
        pair_vec.push_back({ *str_pair_beg, *int_pair_beg });//最简单的方法
        ++str_pair_beg;
        ++int_pair_beg;
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
