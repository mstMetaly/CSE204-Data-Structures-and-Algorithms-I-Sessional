#include<iostream>
using namespace std;


template<class E>class List
{

public:
    List()
    {

    }

    List(const &List)
    {

    }


    virtual ~List()
    {

    }

    virtual int Size()=0;
    virtual void push(E item)=0;
    virtual void pushBack(E item)=0;
    virtual E erase()=0;
    virtual void setToBegin()=0;
    virtual void setToEnd()=0;
    virtual void prev()=0;
    virtual void next()=0;
    virtual int currPos()=0;
    virtual void setToPos(int pos)=0;
    virtual E getValue()=0;
    virtual int find( E item)=0;
    virtual void clear()=0;

};
