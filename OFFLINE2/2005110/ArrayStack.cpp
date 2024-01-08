#include<iostream>
#include "AbstractStack.cpp"
#include<fstream>
#define defaultSize 10;

using namespace std;

template<class E>
class Stack:public AbstractStack<E>{
private:
      int maxSize;
      E* arrList;
      int sizeOfList;


  public:
    Stack()
    {
        maxSize=defaultSize;
        sizeOfList=0;
        arrList=new E[maxSize];

    }

    Stack(int X)
    {
        maxSize=X;
        sizeOfList=0;
        arrList=new E[maxSize];
    }

    ~Stack()
    {
        maxSize=0;
        sizeOfList=0;
       delete[] arrList;
    }


    void Clear()
    {
        maxSize=0;
        sizeOfList=0;
        delete[] arrList;
    }



    void push(E item)
    {

       if(sizeOfList<maxSize){
      arrList[sizeOfList]=item;
      sizeOfList++;
      }

      else{

        maxSize=maxSize*2;
        E* tempList=new E[maxSize];
        for(int i=0;i<sizeOfList;i++)
        {
            tempList[i]=arrList[i];
        }

        arrList=tempList;

        arrList[sizeOfList]=item;
         sizeOfList++;

      }

    }


     E pop()
     {
         if(sizeOfList==0)
           {
           }
         else{
            E temp=arrList[sizeOfList-1];
            sizeOfList--;
            return temp;
         }


     }



    int length()
    {
        return sizeOfList;
    }


     E topValue()
     {
        if(sizeOfList==0)
        {
        }
        else{
            return arrList[sizeOfList-1];
        }

     }

     E headValue()
     {
         return arrList[0];
     }



     void print()
     {
         if(sizeOfList==0)
            cout << "Empty Stack"<< endl;
         else
         {
        for(int i=0;i<sizeOfList;i++)
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


     void write(ofstream &out)
     {
          if(sizeOfList==0)
            out << "Empty Stack"<< endl;
         else
         {
        for(int i=0;i<sizeOfList;i++)
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


     void revList()
     {
        E* temp;
        int j=0;
        temp=new E[sizeOfList];
         for(int i=sizeOfList-1;i>=0;i++)
         {
            temp[j]=arrList[i];
            j++;

         }
         for(int i=0;i<sizeOfList;i++)
         {
             arrList[i]=temp[i];
         }

     }





};
