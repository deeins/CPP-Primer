# 顺序容器

vector:支持随机访问，尾部插入/删除快，其他位置很慢

deque:支持随机访问，头尾插入/删除快

list:只支持双向顺序访问，任何位置插入/删除都很快

forward_list:只支持单向顺序访问，任何位置插入/删除都很快

array:固定大小数组，支持随机访问，不能添加删除元素

string:与vector相似，支持随机访问，尾部插入/删除速度快

## 容器通用操作

**类型别名**（这个操作不是太理解）

const_iterator:只读类型迭代器

size_type:无符号整型，足够保存容器最大可能大小

value_type:元素类型

reference:元素左值类型；与value_type&同义

const_reference:元素的const左值类型

**构造函数**

四种方式：默认构造、两种拷贝构造（利用其他同类容器、迭代器）、列表初始化

**赋值与swap**

c1=c2

c1={....}

a.swap(b) swap(a,b):这两个操作都是对a和b元素进行交换

**大小**

c.size()

c.max_size():c可保存的最大元素数目

c.empty():c是否为空

**添加/删除元素**（不适用于array）

c.insert(args)

c.emplace(inits):使用inits构造c中一个元素

c.clear():删除c中所有元素，返回void

c.erase(args):删除args指定的元素

**关系运算符**

==，!=所有都支持；<之类的无序关联容器不支持

**获取迭代器**

c.begin()

c.end()

c.cbegin()

c.cend()

**反向容器的额外成员**