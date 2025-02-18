#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class StrBlob
{
public:
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
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string& msg)const;
};

StrBlob fun(StrBlob str);