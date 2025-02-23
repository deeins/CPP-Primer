[TOC]

# 第5章 语句

## 5.1 简单语句

#### 空语句

空语句只有分号，通常用于循环在条件部分就已经完成的情况，比如寻找一个序列的末尾索引、循环输入直到输入的值符合要求

### 复合语句

## 5.2 语句作用域

定义在局部的变量，不能从外部访问

## 5.3 条件语句

#### 悬垂else

if语句嵌套，else与哪个if匹配？

C++规定与最近的if匹配

### 5.3.2 switch语句

case关键字和对应的值一起被称为**case标签**，它必须是常量表达式，不能是字符串，可以是字符

当进入到某个case标签后，会顺序执行以下的所有语句，包括其他case标签的，除非遇到break

有些情况故意省略break，比如统计某些情况发生的总和（统计元音字符出现的总次数）

#### switch内部的变量定义

如果在switch内部初始化了变量，那么编译器会报错，可以声明，但不能在声明时初始化。在一个case中声明了一个变量，可以在另一个case中初始化该变量

C++不允许跨越初始化语句

## 5.4 迭代语句

#### 范围for语句

数组可以用范围for

范围for语句主要用于遍历容器或者其他序列的所有元素（序列可以是用花括号括起来的初始值列表）

能使用范围for的类型的共同点：拥有能返回迭代器的begin和end成员

<u>需要进行写操作时，要将循环控制变量定义为引用类型</u>

<u>由于范围for预存了end()的值，所以不能在其中改变序列长度</u>

## 5.5 跳转语句

C++提供了四种跳转语句：break continue goto return

### 5.5.1 break语句

负责终止最近的switch语句或迭代语句

### 5.5.2 continue语句

负责终止一次迭代，直接跳转到下一次迭代

### 5.5.3 goto语句

类似于汇编的无条件跳转JMP

建议：不要在程序中使用goto语句，它会让程序难以修改和理解

格式：

```c++
goto label;

label: return;
```

label可以在同一函数的任意位置

goto和switch一样不能跳过初始化，goto和label之间声明的变量不能初始化，如果goto在后面，那么可以初始化

## 5.6 try语句和异常处理

异常处理机制包括**异常检测**和**异常处理**

**throw表达式**，异常检测使用throw表达式表示遇到了无法处理的问题。我们说throw**引发（raise）**了异常

**try语句块**，异常处理部分使用try语句处理异常。try语句块以try开始，一个或多个catch子句结束。try语句块**中**抛出的异常会被某个catch子句处理。因为catch子句“处理”异常，所以它们也被称为**异常处理代码**

**异常类**用于在<u>throw表达式</u>和<u>catch子句</u>之间传递异常的具体信息，比如throw runtime_error("一些说明信息")，然后catch(runtime_error err)，这样就在异常类中的what()成员函数中记录了错误信息，它们可以在catch中被访问到

### 5.6.1 throw表达式

throw表达式出现在try语句块中，用于检测异常，满足某种错误条件时，我们手动抛出异常

格式：

```c++
throw exception_class;
```

<u>抛出异常会中止当前函数，并把控制权交给处理异常的代码</u>

### 5.6.2 try语句块

语法格式：

```c++
try{
    
} catch (exception-declaration){
    
} catch (exception-declaration){
    
} 
```

<u>catch子句包含三个部分：</u>catch关键词、异常声明、处理异常的语句块

try语句中定义的变量catch中无法访问

stdexcept头文件中定义了标准库异常类，每个标准库异常类都有成员函数what()，它们没有参数，返回值是C风格字符串               （const char*），runtime_error的what()返回初始化的string对象的副本

#### 函数在寻找处理代码的过程中退出

异常被抛出后会寻找匹配的catch子句，没有则会在调用该函数的函数中寻找，以此类推，找不到匹配的catch，会调用名为terminate的标准库函数，导致函数非正常退出

一般没有try语句块，而发生了异常，系统都会调用terminate函数并终止程序的执行

### 5.6.3 标准异常

- exception头文件中定义了最通用的异常类exception。它只报告异常的发生，不提供额外信息
- stdexcept头文件定义了几种常用异常类
- new头文件定义了bad_alloc异常类型，后面12.1.2会详细介绍
- type_info头文件定义了bad_cast异常类型，19.2节详细介绍

<u>exception bad_alloc bad_cast只能默认初始化，不能提供初始值</u>，其他的要用string对象或C风格字符串初始化

有初始值的异常类型，what()返回初始化时的异常信息，无初始值的，返回值由编译器决定