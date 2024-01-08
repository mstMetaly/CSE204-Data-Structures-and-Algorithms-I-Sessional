#include<iostream>
#include "List.cpp"
using namespace std;

template<class E>
class Node{

public:
    E value;
    Node* next;

    Node()
    {
        next=NULL;
    }

    Node(E value,Node* next)
    {
        this->value=value;
        this->next=next;
    }


    Node(Node* next)
    {
        this->next=next;
    }

    Node(Node &ob)
    {
        value=ob.value;
        next=ob.next;

    }



};

template<class E>
class MyList: public List<E>
{
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* curr;
    int sizeOfList=0;

public:
    MyList()
    {
      curr=head=tail=NULL;
       sizeOfList=0;
    }
    MyList(int K)
    {
     curr=head=tail=NULL;
     sizeOfList=0;
    }

    MyList(MyList &ob)
    {
       head=ob.head;
       tail=ob.tail;
       curr=ob.curr;
       sizeOfList=ob.sizeOfList;


    }



    ~MyList()
    {
        while(head!=NULL){
           curr=head;
           head=head->next;
           delete[] head;

        }
    }



    int Size()
    {
    return sizeOfList;
    }



    void push(E value)
    {
       Node<E>* item=new Node<E>(value,NULL);

        if(curr==head)
        {
           item->next=curr;
           head=item;
           curr=item;
           tail=item;
        }

        if(curr!=head )
        {
            cout << "In loop2"<< endl;
           Node<E>* prev=head;
           while(prev->next!=curr)
           {
               prev=prev->next;
           }
            prev->next=item;
            item->next=curr;
            curr=item;

        }

        sizeOfList++;

    }


     void pushBack(E value)
     {

     Node<E>* item;
     item=new Node<E>(value,NULL);
     if(head==NULL && tail==NULL){
        head=item;
        tail=head;
     }
     else{
     tail->next=item;
     tail=item;
     }
     sizeOfList++;

     }

     E erase()
     {
        E temp=curr->value;
        Node<E>* tempNode=curr;
        Node<E>* tempNode2=head;
        if(curr->next==NULL)
        {
           while(tempNode2->next->next!=NULL)
           {
               tempNode2=tempNode2->next;
           }
           curr=tempNode2;
           curr->next=NULL;
           sizeOfList--;
        }
        else{

           while(curr->next->next!=NULL)
           {
               curr->value=curr->next->value;
               curr=curr->next;
           }
           curr->value=curr->next->value;
           curr->next=NULL;
           sizeOfList--;
           curr=tempNode;
        }


        return temp;
     }




     void setToBegin()
     {
         curr=head;
     }

     void setToEnd()
     {

        while(curr->next!=NULL)
        {
            curr = curr->next;
        }

     }


     void prev() {

       if(curr==head) return;
       Node<E>* temp=head;
       while(temp->next!=curr)
           temp=temp->next;
       curr=temp->next;
    }



      void next() {
       curr=curr->next;
    }


    int currPos() {
        Node<E> *temp = head;
        int i = 0;
        while (temp != curr)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }


     void setToPos(int pos)
      {
       Node<E>* temp=head;

       if(pos==0)curr=head;
       for(int i=0;i<=pos;i++)
       {
           temp=temp->next;
       }
       curr=temp;
    }

     E getValue() {
        return curr->value;
    }


    int find(E item) {
       Node<E>* temp=head;
       int i=0;
       while (temp!=tail)
       {
           if(temp->value==item) return i;
           temp=temp->next;
           i++;
       }

        return -1;
    }



    void clear() {
       sizeOfList=0;
      head=tail=curr=NULL;
    }



    void print()
    {

     Node<E>* temp=head;
     for(int i=0;i<sizeOfList;i++)
     {
         if(i==0)
            cout << "<";
         if(temp==curr)
            cout << "|";
         cout<< temp->value << " ";
         if(i==(sizeOfList-1))
            cout<< ">";
         temp=temp->next;
     }

     cout << endl;


    }


};
