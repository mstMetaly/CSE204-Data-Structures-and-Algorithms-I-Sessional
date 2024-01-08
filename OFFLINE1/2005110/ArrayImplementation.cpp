#include<iostream>
#include "List.cpp"
using namespace std;


template<class E>
class  MyList: public List<E>
{
private :
    int maxSize=0;
    int sizeOfList=0;
    int curr=0;

public:
    E *arrList;
    E *arrList1;
    MyList(int K,int X)
    {
        maxSize=X;
        curr=0;
        arrList=new E [maxSize];

    }

    MyList()
    {


    }

    MyList(int k)
    {
        maxSize=k;
    }

    ~MyList()
    {
        delete[] arrList;
        maxSize=sizeOfList=curr=0;
    }
    int getMaxSize()
    {
        return maxSize;
    }

    void setSize(int k)
    {
        maxSize=k;
    }

    int getSize()
    {
        return sizeOfList;
    }

    void check()
    {
        int temp=sizeOfList+1;
        if(temp>maxSize )
        {
            cout << "In loop1"<<endl;
            maxSize=maxSize * 2;
            arrList1=new  E[maxSize];
            for(int i=0; i<sizeOfList; i++)
            {
                arrList1[i]=arrList[i];

            }
            delete[] arrList;
            arrList=arrList1;
        }



    }


    int Size()
    {
        return sizeOfList;
    }


    void push(E item)
    {

        check();

        for(int i=sizeOfList; i>curr; i--)
        {
            arrList[i]=arrList[i-1];

        }
        arrList[curr]=item;
        sizeOfList++;
    }


    void pushBack(E item)
    {

        check();

        arrList[sizeOfList]=item;
        sizeOfList++;
    }

    E erase()
    {

        int temp1=sizeOfList-1;
        if(temp1<(0.5 * maxSize))
        {
            maxSize=maxSize/2;
            arrList1=new  E[maxSize];
            for(int i=0; i<sizeOfList; i++)
            {
                arrList1[i]=arrList[i];

            }
            delete[] arrList;
            arrList=arrList1;

        }
        E temp=arrList[curr];
        for(int i=curr; i<sizeOfList-1; i++)
        {
            arrList[i]=arrList[i+1];

        }
        sizeOfList--;
        return temp;
    }

    void setToBegin()
    {
        curr=0;
    }

    void setToEnd()
    {
        curr=sizeOfList;
    }

    void prev()
    {
        curr-=1;
    }

    void next()
    {
        curr+=1;
    }

    int currPos()
    {
        return curr;
    }

    void setToPos(int position)
    {
        curr = position;
    }

    E getValue()
    {
        return arrList[curr];
    }


    int find(E item)
    {
        int temp=-1;
        for(int i=0; i<sizeOfList; i++)
        {
            if(arrList[i]==item)
            {
                temp=i;
                break;
            }

        }
        return temp;

    }


    void clear()
    {
        delete[] arrList;
        sizeOfList = 0;
        curr= 0;
    }

    void print()
    {
         for(int i=0; i<sizeOfList; i++)
    {
        if(i==0) cout << "<";
        if(i==currPos())
            cout<< "|";
        cout << arrList[i]<< " ";
        if(i==(Size()-1))
           {
            cout << ">"<< endl;

           }

    }
     cout << endl;
    }


};
