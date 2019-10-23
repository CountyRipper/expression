#include "expression.h"


int main(int, char**) {
    char c1;
    expression<double>exp1;
    do{
        std::cout <<"It's a expression calculator"<<std::endl;
        std::cout << "input expression: such as \"-2*(3+5)+2^3/4=\""<<std::endl;
        expression<double>::Run();
        std::cout<<"continue?(y/n)"<<std::endl;
        std::cin.ignore(256,'\n');
        std::cin>>c1;
    }while(c1=='y');
    return 0;
}
