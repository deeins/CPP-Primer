#pragma once
//extern const int bufff_size = 15;//只定义，没有声明,此句只要未注释程序就会报错
extern const int buff_size;//声明，然后在cpp文件中定义
//int i = 0;//此句代码报错多重定义，与第一句代码报错一样，说明头文件中不能初始化，要想不初始化只声明要通过extern关键词实现
extern int ii;//没有extern关键词，在.cpp文件中使用int ii=0;的语句初始化会报错，说明有extern关键词标注出是外部变量，变量才能被外部使用

