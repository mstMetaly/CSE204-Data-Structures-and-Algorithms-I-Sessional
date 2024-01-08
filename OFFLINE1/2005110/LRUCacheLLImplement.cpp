#include<iostream>
#include "LLImplementation.cpp"
#include<typeinfo>
using namespace std;

class Pair{

public:
    int key;
    int value;
    Pair()
    {

    }
    Pair(int k,int v)
    {
        key=k;
        value=v;
    }
    Pair(const Pair& obj)
    {
        this->key=obj.key;
        this->value=obj.value;


    }

    Pair operator=(const Pair& ob)
    {
        Pair temp;
        temp.key=ob.key;
        temp.value=ob.value;
        return temp;
    }

     bool operator == (const Pair& ob2)
    {
        if(this->key== ob2.key && this->value==ob2.value)
            return true;

        return false;
    }

friend  ostream& operator<<(ostream& os,const Pair& p);




};
    ostream& operator<<(ostream& os,const Pair& p) {
    os << p.key << " " << p.value;
    return os;
    }


class LRUCache{

private:
    int capacity;
     MyList<Pair> llList;

public:
    LRUCache(int C)
    {
        capacity=C;
       // llList.setSize(C);
    }


    void  put(int x,int y)
    {
        Pair pairOb(x,y);
        if(llList.Size()<capacity)
        { int p=10;
            llList.push((pairOb));
            cout <<"key"<< pairOb.value<< endl;
           cout<<typeid(p).name()<< endl;


        }
        else if(llList.Size()>=capacity)
        {  // cout << "111"<< endl;
            llList.setToEnd();
            llList.erase();
            llList.setToBegin();
            llList.push(pairOb);
             llList.setToBegin();

        }


    }

    int get(int k)
    {
        int temp=-1;
       for(int i=0;i<llList.Size();i++)
       {
        if(llList.getValue().key==k)
           {temp=llList.getValue().value;}

           llList.next();
       }

        llList.setToBegin();
        return temp;

    }

    void print()
    {
       /* int curr=llList.currPos();
        for(int i=0;i<llList.Size();i++)
        {
           llList.setToBegin();
           cout << "currr:"<<llList.currPos()<< endl;
           cout<<llList.getValue().key<< ",";
           cout <<llList.getValue().value<< endl;
           llList.next();
        }*/
        llList.print();
      // llList.setToPos(curr);

    }

};

int main()
{
   LRUCache ob(2);
   ob.put(1,1);
   ob.put(2,2);
  // ob.put(3,3);
   ob.print();


}
