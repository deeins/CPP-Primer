#pragma once
#include "StrBlobPtr.h"

//解引用
string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

//递增
StrBlobPtr& StrBlobPtr::incr()
{
    //如果抛出异常，则不会递增
    auto p = check(curr, "increament past end");
    curr++;
    return *this;
}

//检查是否绑定strblob，以及是否越界
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& str) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(str);
    return ret;
}

