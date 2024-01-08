#include<iostream>
#include "AbstractQueue.cpp"
#include<fstream>
#define defaultSize 10;

using namespace std;

template<class E>
class Queue:public AbstractQueue<E>
{
private:
    int maxSize;
    int front,rear;
    E* arrList;
    int sizeOfList;

public:
    Queue()
    {
        sizeOfList=0;
        maxSize=defaultSize;
        front=-1;
        rear=-1;
        arrList=new E[maxSize];
    }

    Queue(int X)
    {
        maxSize=X;
        front=-1;
        rear=-1;
        sizeOfList=0;
        arrList=new E[maxSize];
    }

    ~Queue()
    {
        delete[] arrList;
    }


    void Clear()
    {
        maxSize=0;
        sizeOfList=0;
        delete[] arrList;
    }


    void enqueue(E item)
    {
        if(sizeOfList<maxSize)
        {
            arrList[sizeOfList]=item;
            sizeOfList++;

        }

        else
        {
            maxSize=maxSize * 2;
            E *tempList=new E[maxSize];

            for(int i=0; i<sizeOfList; i++)
            {
                tempList[i]=arrList[i];
            }

            arrList=tempList;
            arrList[sizeOfList]=item;
            sizeOfList++;

        }


    }


    E dequeue()
    {
        if(sizeOfList==0)
        {
        }

        else
        {

            E temp=arrList[0];
            E* tempList=new E[maxSize];

            for(int i=1; i<sizeOfList; i++)
            {
                tempList[i-1]=arrList[i];
            }
            sizeOfList--;
            delete[] arrList;
            arrList=tempList;
            return temp;
        }

    }


    int length()
    {
        return sizeOfList;

    }


    E frontValue()
    {
        if(sizeOfList==0)
        {

        }
        else
        {
            return arrList[0];
        }
    }


    E rearValue()
    {
        if(sizeOfList==0)
        {

        }
        else
        {
            return arrList[sizeOfList-1];
        }


    }


    E leaveQueue()
    {
        if(sizeOfList==0)
        {

        }
        else
        {
            E temp=arrList[sizeOfList-1];
            sizeOfList--;
            return temp;
        }


    }

    int findElement(int value)
    {
        for(int i=0;i<sizeOfList;i++)
        {
            if(value==arrList[i])
                return 0;

        }
        return -1;

    }


    void print()
    {
        if(sizeOfList==0)
            cout << "Empty Queue"<< endl;
        else
        {
            for(int i=0; i<sizeOfList; i++)
            {
                if(i==0)
                    cout << "<";
                cout << arrList[i] << " ";
                if(i==(sizeOfList-1))
                    cout << ">";
            }
            cout << endl;
        }

    }


    void write(ofstream& out)
    {
        if(sizeOfList==0)
            out << "Empty Queue"<< endl;
        else
        {
            for(int i=0; i<sizeOfList; i++)
            {
                if(i==0)
                    out << "<";
                out << arrList[i] << " ";
                if(i==(sizeOfList-1))
                    out << ">";
            }
            out << endl;
        }


    }



};
