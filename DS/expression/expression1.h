
#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include "stack1.h"
#include <fstream>
#include <istream>
#include <iostream>

template<class Type>
class expression{
    private:
        static bool Isoperator(char ch);//判断是否是操作符
        static int Opri(char op);//判断优先级
        static bool Isdigit(char ch);
        //取出两个操作数,从堆栈中
        static void get2Operands(stack<Type> &opnd,Type &a1,Type &a2);

        //形成运算指令送入opnd栈中
        static void DoOperator(stack<Type> &opnd,const Type &a1,char op,const Type &a2 );

        //从键盘中读取输入流并且由中缀表达式转后缀表达式存入文件中
        static void exchangexp(std::ofstream &outfile);

        //计算后缀表达式值,来自于输入文件infile
        static void calexpression(std::ifstream &infile);

        //static char Getchar(std::istream &instream);

        
    public:
        //程序启动接口
        static void Run();
        //无参构造函数
        expression(){};
        //析构函数
        virtual ~expression(){};
};


#endif
