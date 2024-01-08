#include<iostream>
#include "AbstractQueue.cpp"
#include "LLStack.cpp"
#include<fstream>

using namespace std;


template<class E>
class Queue:public AbstractQueue<E>
{
private :
    Node<E>* head;
    Node<E>* tail;
    int sizeOfList;

public:
    Queue()
    {
        head=NULL;
        tail=NULL;
        sizeOfList=0;
    }

    Queue(int k)
    {
      head=NULL;
      tail=NULL;
      sizeOfList=0;
    }


     ~Queue()
    {
           while(head!=NULL)
        {
           tail=head;
           head=head->next;
           delete[] tail;

        }
    }

    void Clear()
    {
       while(head!=NULL){
           tail=head;
           head=head->next;
           delete[] tail;
           tail=NULL;

        }
         sizeOfList=0;

    }


      void enqueue(E item)
      {
          Node<E>* temp=new Node<E>(item,NULL);
          if(sizeOfList==0)
          {
              head=temp;
              tail=temp;
              sizeOfList++;
          }
          else if(sizeOfList==1)
          {
              head->next=temp;
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


     E dequeue()
     {
         E temp;
         if(sizeOfList==0)
         {

         }

         else if(sizeOfList==1)
         {
           temp=head->value;
           delete[] head;
           delete[] tail;
           head=NULL;
           tail=NULL;
           sizeOfList--;

         }

         else
         {
            Node<E>* tempHead=head;
           temp=head->value;
           head=head->next;
           delete[] tempHead;
           sizeOfList--;

         }
         return temp;

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
            return head->value;
     }



     E rearValue()
     {
       if(sizeOfList==0)
       {
       }

        else
            return tail->value;
     }



     E leaveQueue()
     {
         E temp;
         if(sizeOfList==0)
         {

         }
          else if(sizeOfList==1)
          {
            temp=head->value;
            delete[] head;
            delete[] tail;
            head=tail=NULL;
            sizeOfList--;
          }

          else{
            temp=tail->value;
            Node<E> *prev=head;
            while(prev->next!=tail)
            {
                prev=prev->next;
            }
            delete[] tail;
          tail=prev;
          tail->next=NULL;
          sizeOfList--;

          }

         return temp;
     }

     void print()
     {
         if(sizeOfList==0)
         {
             cout << "Empty Queue"<< endl;
         }

         else{
         Node<E>* temp=head;
         while(temp!=NULL)
         {
             if(temp==head)
             {
                 cout << "<";
             }
             cout << temp->value << " ";
             if(temp==tail)
                cout << ">"<< endl;

             temp=temp->next;
         }
         }

     }



     void write(ofstream& out)
     {

         if(sizeOfList==0)
         {
             out << "Empty Queue"<< endl;
         }

         else{
         Node<E>* temp=head;
         while(temp!=NULL)
         {
             if(temp==head)
             {
                 out << "<";
             }
             out << temp->value << " ";
             if(temp==tail)
                out << ">"<< endl;

             temp=temp->next;
         }
         }

     }





};














