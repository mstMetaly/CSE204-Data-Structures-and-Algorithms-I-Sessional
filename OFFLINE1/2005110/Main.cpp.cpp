#include<iostream>
#include<bits/stdc++.h>
//#include "ArrayImplementation.cpp"
#include "LLImplementation.cpp"
#include<fstream>

using namespace std;


int main()
{
    ifstream input;
    ofstream out;
    input.open("list_input.txt");
    //out.open("list_output.txt");
    int k,x;
    int count=0;


    string line1,T;
    getline(input,line1);
    stringstream X(line1);
    while (getline(X, T, ' '))
    {

        if(count==0)
        {
            k=stoi(T);
            count++;

        }
        else x=stoi(T);


    }

   /// MyList<int>mylist(k,x);//use this mylist when use ArrayImplementation
   MyList<int> mylist;///use this mylist when use LLImplementation


    string line2,T2;
    getline(input,line2);
    stringstream X2(line2);
    while (getline(X2, T2, ' '))
    {
        mylist.push(stoi(T2));
    }

    mylist.print();


    string line3;
    getline(input,line3);
    int operation=stoi(line3);

    for(int i=0; i<operation; i++)
    {

        string line4,T4;

        getline(input,line4);
        stringstream X4(line4);
        int count2=0,call,parameter;
        while (getline(X4, T4, ' '))
        {
            if(count2==0)
            {
                call=stoi(T4);
                count2++;;
            }

            else
            {
                parameter=stoi(T4);
                count2=0;
            }


        }

         switch (call)
        {

        case 1:
        {
            mylist.print();
            cout<< mylist.Size()<< endl;
            break;

        }

       case 2:
        {
            mylist.push(parameter);
            mylist.print();
            cout<< "-1" << endl;

            break;
        }

        case 3:
        {
            mylist.pushBack(parameter);
            cout<< "-1" << endl;
            break;
        }

    case 4:
        {
           int temp= mylist.erase();
            mylist.print();
            cout << temp<<endl;
            break;
        }

    case 5:
        {
            mylist.print();

            cout<<  "-1" << endl;

            break;
        }

     case 6:
        {
            mylist.setToEnd();
            mylist.print();
            cout<<  "-1" << endl;
            break;
        }

     case 7:
        {
            mylist.prev();
            mylist.print();

            cout<<  "-1" << endl;

        }
        case 8:
        {
            mylist.next();
            mylist.print();
            cout<<  "-1" << endl;
            break;
        }
    case 9:
        {
           mylist.print();
            cout <<mylist.currPos()<< endl;
            break;
        }
        case 10:
        {
            mylist.setToPos(parameter);
            mylist.print();
            out<< "-1" << endl;
            break;
        }
    case 11:
        {
            mylist.print();
            cout << mylist.getValue()<< endl;
        }
        case  12:
        {
           mylist.print();
            cout << mylist.find(parameter)<< endl;
            break;
        }
        case 13:
        {
            mylist.clear();

            cout<< "-1"<< endl;
            break;
        }


        }


    }



    return 0;

}


