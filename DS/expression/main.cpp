#include "expression.h"

int main(int, char**) {
    char c1;
    expression<double>exp1;
    do{
        std::cout << "input expression:"<<std::endl;
        expression<double>::Run();
        std::cout<<"continue?(y/n)"<<std::endl;
        std::cin>>c1;
    }while(c1=='y');
    return 0;
}
