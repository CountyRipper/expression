
#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include <stack>
#include <fstream>
#include <istream>
#include <iostream>

using namespace std;

template<class Type>
class expression {
private:
	static bool Isoperator(char ch) {
		if (ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%' || ch == '(' || ch == ')')
			return true;
		else return false;
	}//判断是否是操作符
	static int Opri(char op) {
		if (op == '=') return 0;
		else if (op == '(') return 1;
		else if (op == '+' || op == '-') return 2;
		else if (op == '*' || op == '/' || op == '%') return 3;
		else if (op == '^') return 4;
		else if(op == ')') return 5;
        else return -1;
	} 
    //判断优先级
	static bool Isdigit(char ch) {
		if (ch >= '0' && ch <= '9') return true;
		else return false;
	}
	//取出两个操作数,从堆栈中
	static void get2Operands(stack<Type>& opnd, Type& a1, Type& a2) {
		a1 = opnd.top(); opnd.pop();//a1获取了opnd的弹出的一个元素
		a2 = opnd.top(); opnd.pop();
	};

	//形成运算指令送入opnd栈中
	static void DoOperator(stack<Type>& opnd, const Type& a1, char op, const Type& a2) {
		switch (op)
		{
		case '+':
			opnd.push(a1 + a2);
			break;
		case '-':
			opnd.push(a1 + a2);
			break;
		case '*':
			opnd.push(a1 * a2);
			break;
        case '%':
            opnd.push(a2 % a1);
		case '/':
			try
			{
				if (a2 == 0) throw "a2 = 0";
				else opnd.push(a2 / a1);
			}
			catch (const char* e)
			{
				std::cerr << e << '\n';
			}
			break;
		case '^': {
			int a11 = a1;
			int a22 = a2;
			while (a22 >= 1) {
				
				a11 *= a11;
				a22--;
			}
			opnd.push(a11);
		}
				break;
		default:
			break;
		}
	}

	//从键盘中读取输入流并且由中缀表达式转后缀表达式存入文件中
	static void exchangexp(std::ofstream& outfile) {
		//先建一个操作符栈，用来存储操作符
		stack<char>optr;
		//输入的字符ch和操作符栈顶的操作符optrtop以及操作符op
		char ch, optrtop, op;
		//操作数
		Type operand;
		//先压入'='确保安全
		optr.push('=');
		optrtop = optr.top();//optrtop取得optr栈顶元素
		//设置循环，在输入输出流中读取字符
		std::cin>>ch;
		while (optrtop != '=' || ch != '=') {
			//当ch为数字或者.的处理
			try {
				if (Isdigit(ch) || ch == '.') {
					std::cin.putback(ch);//把ch放回到输入流中
					std::cin >> operand;//读操作数
					outfile << operand << " ";//把文件输出到outfile中
					std::cin >> ch; //从输入流中原则上需要跳过空格与制表符
				}
				// illegal char

				else if (!Isoperator(ch)) {
					throw "非法字符!";
				}

				//compare optrator priori
				//如果是操作符
                else if(ch=='('){
                    	optr.push(ch);//ch这个操作符进操作符栈
						std::cin >> ch;//再次从输入流中读取ch;
                }
                else if(ch==')'){
                    while(optrtop!='('){
                        op =optr.top();
                        optr.pop();
                        outfile<<op<<' ';
                        optrtop=optr.top();
                    }
                    optr.pop();//把()舍去
                    std::cin >> ch;
                }
                //当不等于()时
				else {
					//优先级高或者相等就压栈
					if (Opri(optrtop) <= Opri(ch)) {
						optr.push(ch);//ch这个操作符进操作符栈
						std::cin >> ch;//再次从输入流中读取ch;
					}
					else if (Opri(optrtop) > Opri(ch)) {
						op = optr.top();
						optr.pop();//从栈中把上一个操作符弹给op
						outfile << op << ' '; //把运算符op输出到outfile中
					}/*
					else if (optrtop == '(' && ch == ')') {
						ch=optr.top();//optr stack pop ()
						optr.pop();
						std::cin >> ch;
					}*/
				}
				optrtop = optr.top();//获取当前操作符栈的栈顶元素         
			}
			catch (char* msg) {
				std::cerr << msg << std::endl;
			}
			
		}
		outfile << '=';
	}

	//计算后缀表达式值,来自于输入文件infile
	static void calexpression(std::ifstream& infile) {
		stack<Type>opnd;//操作数栈
		char ch;
		double operand;//操作数

		while (infile >> ch, ch != '=') {
			if (Isoperator(ch)) {
				Type a1, a2;
				get2Operands(opnd,a1,a2);//从operands栈取出两个操作数
				DoOperator(opnd, a1, ch, a2);//运算结果送入opnd中
			}
			//ch is not operator
			else {
				infile.putback(ch);//把ch放回infile
				infile >> operand;//操作数赋值
				opnd.push(operand);//将operand入opnd栈
			}
		}
		operand=opnd.top();
		std::cout << operand << std::endl;
	}

	//static char Getchar(std::istream &instream);      
public:
	//程序启动接口
	static void Run() {
		std::ofstream outfile("exp_text.dat");//define outfile
		exchangexp(outfile);//exchange the mid_expression to ,save the result in outfile
		outfile.close();

		std::ifstream infile("exp_text.dat");
		calexpression(infile);//计算输入流文件中表达式的结果
		infile.close();
		//remove("exp_text.dat");
	};
	//无参构造函数
	expression() {};
	//析构函数
	virtual ~expression() {};
};


#endif

