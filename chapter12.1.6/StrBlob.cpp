#include "StrBlob.h"
#include "StrBlobPtr.h"

void StrBlob::check(size_type i, const string& msg) const
{
    if (data->size() <= i)
    {
        throw out_of_range(msg);
    }
}

StrBlob::StrBlob(initializer_list<string> lst)
{
    data = make_shared<vector<string>>(vector<string>{lst});
}

StrBlob::StrBlob()
{
    data = nullptr;
}

string& StrBlob::front()
{
    // TODO: 在此处插入 return 语句
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    // TODO: 在此处插入 return 语句
    check(0, "back on empty StrBlob");
    return data->back();
}

string& StrBlob::front() const
{
    // TODO: 在此处插入 return 语句
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() const
{
    // TODO: 在此处插入 return 语句
    check(0, "back on empty StrBlob");
    return data->back();
}

bool StrBlob::empty()
{
    if (data->size() == 0)
    {
        cout << "This StrBlob object is empty" << endl;
        return true;
    }
    return false;
}

void StrBlob::pop_back()
{
    // TODO: 在此处插入 return 语句
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void StrBlob::push_back(const string& str)
{
    data->push_back(str);
}

void StrBlob::print()
{
    if (!empty())
    {
        for (auto beg = data->begin(); beg < data->end(); beg++)
        {
            cout << *beg << ' ';
        }
        cout << endl;
    }
}

// StrBlob 的 begin 和 end 成员的定义
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

StrBlob fun(StrBlob str)
{
    return str;
}