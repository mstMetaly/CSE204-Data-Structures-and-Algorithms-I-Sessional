#include<iostream>
#include "AbstractStack.cpp"
#include<fstream>


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
class Stack:public AbstractStack<E>
{
private :
    Node<E>* head;
    Node<E>* tail;
    int sizeOfList;

public:
    Stack()
    {
       head=tail=new Node<E>;
        sizeOfList=0;
    }

    Stack(int k)
    {
        sizeOfList=0;
        head=tail=new Node<E>;
    }


     ~Stack()
    {
        Node<E>* temp;
         while(head!=NULL){
           temp=head;
           head=head->next;
           delete temp;

        }
        sizeOfList=0;
    }

    void Clear()
    {
        Node<E>* temp;
       while(head!=NULL)
        {
           temp=head;
           head=head->next;
          delete temp;

        }
        sizeOfList=0;
       head=tail=new Node<E>;

    }


    void push(E item)
    {
        Node<E>* temp=new Node<E>(item,NULL);
        if(sizeOfList==0)
        {
         head=temp;
         tail=temp;
         sizeOfList++;
        }

       else
        {
            tail->next=temp;
            tail=tail->next;
            sizeOfList++;
        }

    }



    E pop()
    {

       E val;
       if(sizeOfList==0)
       {
       }

        else{
            val=tail->value;
            Node<E>* prev=head;
            while(prev->next!=tail)
            {
                prev=prev->next;
            }
            delete[] tail;
            tail=prev;
            tail->next=NULL;
            sizeOfList--;
        }

        return val;

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
         else
            return tail->value;


    }



    void print()
    {
        Node<E>* temp=head;
        if(temp==NULL)
        {
            cout << "Empty Stack"<< endl;
        }
        else
        {
        while(temp!=NULL)
        {
            if(temp==head)
                cout << "<";
            cout << temp->value<< " ";
            if(temp==tail)
                cout << ">";
            temp=temp->next;
        }
        }
      cout << endl;
    }

    E headValue()
    {
        if(head==NULL)
        {
          cout << "Empty Stack"<< endl;
        }
        else
        {
            return head->value;
        }
    }


    void write(ofstream &out)
    {

        Node<E>* temp=head;
        if(temp==NULL)
        {
            out << "Empty Stack"<< endl;
        }
        else
        {
        while(temp!=NULL)
        {
            if(temp==head)
                out << "<";
            out << temp->value<< " ";
            if(temp==tail)
                out << ">";
            temp=temp->next;
        }
        }
      out << endl;

    }



};
