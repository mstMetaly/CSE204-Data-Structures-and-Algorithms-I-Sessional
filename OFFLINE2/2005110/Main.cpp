#include<iostream>

//#include "ArrayStack.cpp"
//#include "ArrayQueue.cpp"


#include "LLQueue.cpp"

#include<fstream>


using namespace std;

int main()
{
    ifstream infile;
    ofstream out;

    infile.open("list_input.txt");
    out.open("list_output.txt",ios::out|ios::app);
    int K,X,x,Q,F,P;
    infile>> K >> X;
    Stack<int> stackOb(X);

    for(int i=0; i<K; i++)
    {
        infile>>x;
        stackOb.push(x);
    }

    stackOb.print();
    cout << endl;
    stackOb.write(out);
    out << endl;

    infile>> K >> X;
    Queue<int> queueOb(X);

    for(int i=0; i<K; i++)
    {
        infile>>x;
        queueOb.enqueue(x);
    }

    queueOb.print();
    cout << endl;
    queueOb.write(out);
    out << endl;


    infile>>Q;
    for(int i=0; i<Q; i++)
    {

        infile>> F >> P;

        switch (F)
        {
        case 1:
        {
            queueOb.Clear();

            cout << "cleared"<< endl;
            cout << "-1"<< endl;
            cout << endl;

            out << "cleared"<< endl;
            out << "-1"<< endl;
            out << endl;
            break;

        }

        case 2:
        {
            queueOb.enqueue(P);

            queueOb.print();
            cout << "-1"<< endl;
            cout << endl;

            queueOb.write(out);
            out << "-1"<< endl<< endl;
            break;

        }


        case 3:
        {
            int temp;
            if(queueOb.length()!=NULL)
            {
                temp=queueOb.dequeue();
                queueOb.print();
                cout << temp<< endl<< endl;

                queueOb.write(out);
                out << temp<< endl<< endl;
            }
            else
                {
                  queueOb.print();
                  cout << "No element to dequeue" <<endl<< endl;

                  queueOb.write(out);
                  out << "No element to dequeue" <<endl<< endl;

                }

            break;
        }


        case 4:
        {

            int temp;
            if(queueOb.length()!=NULL)
            {
                temp=queueOb.length();
                queueOb.print();
                cout << temp << endl<< endl;

                queueOb.write(out);
                out << temp << endl<< endl;
            }
            else
            {
                queueOb.print();
              cout << "Zero Length"<< endl<< endl;

              queueOb.write(out);
              out << "Zero Length"<< endl<< endl;
            }

            break;
        }

        case 5:
        {

            int temp;
            if(queueOb.length()!=NULL)
            {
                temp=queueOb.frontValue();
                queueOb.print();
                cout << temp << endl<< endl;

                queueOb.write(out);
                out << temp << endl<< endl;
            }
            else
            {
                 queueOb.print();
                cout << "No front Value"<< endl<< endl;

                queueOb.write(out);
                out << "No front Value"<< endl<< endl;
            }



            break;
        }

        case 6:
        {
            int temp;

            if(queueOb.length()!=0)
            {
                temp=queueOb.rearValue();
                queueOb.print();
                cout << temp << endl<<endl;

                queueOb.write(out);
                out << temp << endl<< endl;
            }

            else
               {
                    queueOb.print();
                  cout << "No rear value"<< endl<< endl;

                  queueOb.write(out);
                  out << "No rear value"<< endl<< endl;
               }

            break;
        }

        case 7:
        {
            int temp;

            if(queueOb.length()!=0)
            {
                temp=queueOb.leaveQueue();
                queueOb.print();
                cout << temp << endl<< endl;

                queueOb.write(out);
                out << temp << endl<< endl;
            }
            else
            {
                queueOb.print();
               cout << "No element to leave"<< endl<< endl;

               queueOb.write(out);
               out << "No element to leave"<< endl<< endl;
            }

            break;
        }

        case 8:
        {
            stackOb.Clear();

            cout << "cleared"<< endl;
            cout << "-1"<< endl<<endl;

            out << "cleared"<< endl;
            out << "-1"<< endl<<endl;
            break;
        }

        case 9:
        {
            stackOb.push(P);

            stackOb.print();
            cout << "-1"<< endl<<endl;

             stackOb.write(out);
            out << "-1"<< endl<<endl;
            break;
        }


        case 10:
        {
            int temp;
            if(stackOb.length()!=0)
            {   temp=stackOb.pop();
                stackOb.print();
                cout << temp<< endl<<endl;

                stackOb.write(out);
                out << temp<< endl<< endl;
            }
            else
            {

                 stackOb.print();
                cout << "No element to pop"<< endl<< endl;

                stackOb.write(out);
                out << "No element to pop"<< endl<< endl;
            }

            break;
        }


        case 11:
        {
            int temp;
            if(stackOb.length()!=0)
            {
                temp=stackOb.length();
                stackOb.print();
                cout << temp << endl<< endl;


                stackOb.write(out);
                out << temp << endl<< endl;
            }

            else
            {
                stackOb.print();
              cout << "Zero Length"<< endl<< endl;


              stackOb.write(out);
              out << "Zero Length"<< endl<< endl;
            }

            break;
        }

        case 12:
        {
            int temp;
            if(stackOb.length()!=0)
            {
                temp=stackOb.topValue();
                 stackOb.print();
                cout << temp << endl<< endl;

                stackOb.write(out);
                out << temp << endl<< endl;
            }
            else
            {
                stackOb.print();
               cout << "No top Value"<< endl<< endl;

               stackOb.write(out);
               out << "No top Value"<< endl<< endl;
            }

            break;
        }


        }


    }





    infile.close();
    out.close();
    return 0;




}
