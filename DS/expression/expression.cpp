#include "expression.h"

template<class Type>
bool expression<Type>::Isoperator(char ch){
    if(ch=='='||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%'||ch=='('||ch==')')
        return true;
    else return false;
}

template<class Type>
int expression<Type>::Opri(char op){
    int pri;
    if(op=='=') return 0;
    else if(op=='(') return 1;
    else if(op=='+'||op=='-') return 2;
    else if(op=='*'||op=='/'||op=='%') return 3;
    else if(op=='^') return 4;
    else if(op==')') return 5;
}

template<class Type>
bool expression<Type>::Isdigit(char ch){
    if(ch>='0'&&ch<='9') return true;
    else return false;
}

template<class Type>
void expression<Type>::get2Operands(stack<Type> &opnd,Type &a1,Type &a2){
    opnd.pop(a1);//a1获取了opnd的弹出的一个元素
    opnd.pop(a2);
}
/*
template<class Type>
char expression<Type>::Getchar(std::istream &instream){
    char ch;
    while(ch=(instream.peek())!EOF&&(ch=instream.get()==' '||ch=='\t'));
        return ch;
    
}*/

template<class Type>
void expression<Type>::DoOperator(stack<Type>&opnd,const Type &a1,char op,const Type &a2){
    switch (op)
    {
    case '+':
        opnd.push(a1+a2);
        break;
    case '-':
        opnd.push(a1+a2);
        break;
    case '*':
        opnd.push(a1*a2);
        break;
    case '/':
        try
        {
            if(a2==0) throw "a2 = 0";
            else opnd.push(a1/a2);
        }
        catch(const char* e)
        {
            std::cerr << e << '\n';
        }
        break;
    case '^':{
        while(a2>1){
            a1*=a1;
            a2--;
        }
        opnd.push(a1);
    }
    break;
    default:
        break;
    }
}

template<class Type>
void expression<Type>::calexpression(std::ifstream &infile){
    stack<Type>opnd;//操作数栈
    char ch;
    double operand;//操作数

    while(infile>>ch,ch!='='){
        if(Isoperator(ch)){
            Type a1,a2;
            get2Operands(a1,a2);//从operands栈取出两个操作数
            DoOperator(opnd,a1,ch,a2);//运算结果送入opnd中
        }
        //ch is not operator
        else{
            infile.putback(ch);//把ch放回infile
            infile>>operand;//操作数赋值
            opnd.push(operand);//将operand入opnd栈
        }
    }
    opnd.getTop(operand);
    std::cout<<operand<<std::endl;
}

template<class Type>
void expression<Type>::exchangexp(std::ofstream &outfile){
    //先建一个操作符栈，用来存储操作符
    stack<char>optr;
    //输入的字符ch和操作符栈顶的操作符optrtop以及操作符op
    char ch,optrtop,op;
    //操作数
    Type operand;
    //先压入'='确保安全
    optr.push('=');
    optrtop = optr.getTop();//optrtop取得optr栈顶元素
    //设置循环，在输入输出流中读取字符
    ch=std::cin.get();
    while(optrtop!='='||ch!='='){
        //当ch为数字或者.的处理
        try{
            if(Isdigit(ch)||ch=='.'){
                std::cin.putback(ch);//把ch放回到输入流中
                std::cin>>operand;//读操作数
                outfile<<operand<<" ";//把文件输出到outfile中
                std::cin>>ch; //从输入流中原则上需要跳过空格与制表符
            }
            // illegal char
        
            else if(!Isoperator(ch)){
                throw "非法字符!";
            }
        
            //compare optrator priori
            //如果是操作符
            else{
                //优先级高或者相等就压栈
                if(Opri(optrtop)<=Opri(ch)){
                    optr.push(ch);//ch这个操作符进操作符栈
                    std::cin>>ch;//再次从输入流中读取ch;
                }
                else if(Opri(optrtop)>Opri(ch)){
                    optr.pop(op);//从栈中把上一个操作符弹给op
                    outfile<<op<<' '; //把运算符op输出到outfile中
                }
                else if(Opri(optrtop)=='('&&ch==')'){
                    optr.pop(ch);//optr stack pop ()
                    std::cin>>ch;
                }
            }
            optrtop=optr.getTop();//获取当前操作符栈的栈顶元素         
        }catch(char *msg){
            std::cerr<<msg<<std::endl;
        }
        outfile<<'=';
    }
}

template<class Type>
void expression<Type>::Run(){
    std::ofstream outfile("exp_text.dat");//define outfile
    exchangexp(outfile);//exchange the mid_expression to ,save the result in outfile
    outfile.close();
    
    std::ifstream infile("exp_text.dat");
    calexpression(infile);//计算输入流文件中表达式的结果
    infile.close();
    remove("exp_text.dat");
} 
