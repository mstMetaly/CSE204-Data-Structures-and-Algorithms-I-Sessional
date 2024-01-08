#include<iostream>
using namespace std;


template<class E>class AbstractStack{

public:
    virtual void Clear()=0;
    virtual void push(E item)=0;
    virtual E pop()=0;
    virtual int length()=0;
    virtual E topValue()=0;

};
