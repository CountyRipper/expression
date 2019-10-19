//
// Created by pc on 2019/10/16.
//

#ifndef STACK1_STACK_H
#define STACK1_STACK_H

#include <cstdio>

template <class T>
    struct LinkNode{
        T data;
        LinkNode *link;
        LinkNode(const T& args,LinkNode<T> *ptr=NULL){
            data = args;
            link = ptr;
        }
};
template <class Type>
class stack{
private:
    LinkNode<Type>*top;
public:
    stack(){
        top =NULL;
    }
    ~stack(){
        clearStack();
    }
    void push(const Type &x){
        top = new LinkNode<Type>(x,top);
    }
    void pop(Type &x){
        if(isEmpty()) throw "empty";
        LinkNode<Type> *p = top;
        top = top->link;
        x = p->data;
        delete p;
    }
    bool isEmpty(){
        return (top == NULL)? true: false;
    }
    void clearStack() {
        LinkNode<Type> *p = top;
        while (p != NULL) {}
        p = p->link;
        delete p;
    }
    Type getTop(){
        if(isEmpty()) throw "Empty";
        return top->data;
    }
    int getSize(){
        LinkNode<Type> *p = top;
        int k=0;
        while(p!=NULL){
            p=p->link;
            k++;
        }
        return k;
    }

};
#endif //STACK1_STACK_H
