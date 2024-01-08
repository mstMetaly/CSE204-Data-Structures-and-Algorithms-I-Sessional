#include<iostream>
using namespace std;


template<class E>class AbstractQueue{

public:
    virtual void Clear()=0;
    virtual void enqueue(E item)=0;
    virtual E dequeue()=0;
    virtual int length()=0;
    virtual E frontValue()=0;
    virtual E rearValue()=0;
    virtual E leaveQueue()=0;

};
