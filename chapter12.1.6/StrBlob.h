#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class StrBlobPtr;

class StrBlob
{
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob(initializer_list<string> lst);
    StrBlob();
    string& front();
    string& back();
    string& front()const;
    string& back()const;
    bool empty();
    void pop_back();
    void push_back(const string& str);
    void print();
    StrBlobPtr begin();// ���� StrBlobPtr ����ܶ�����������������Ϊ���õ����Ĺ��캯��
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string& msg)const;
};

StrBlob fun(StrBlob str);