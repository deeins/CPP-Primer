#pragma once
#include "StrBlobPtr.h"

//������
string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

//����
StrBlobPtr& StrBlobPtr::incr()
{
    //����׳��쳣���򲻻����
    auto p = check(curr, "increament past end");
    curr++;
    return *this;
}

//����Ƿ��strblob���Լ��Ƿ�Խ��
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& str) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(str);
    return ret;
}

