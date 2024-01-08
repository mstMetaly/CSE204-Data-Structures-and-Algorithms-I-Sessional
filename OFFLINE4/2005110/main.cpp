#include<iostream>
#include<fstream>
#include<string.h>
#include "heap.h"



using namespace std;


int main()
{
    ifstream infile;
    ofstream outfile;

    Heap h;


    infile.open("input.txt");
    outfile.open("output.txt");

    while(!infile.eof())
    {
        string order;

        infile >> order;

        if(order=="INS")
        {
            int key;
            infile>>key;
            h.Insert(key);
            cout << "INSERTED "<< key << endl;
            outfile << "INSERTED "<< key << endl;

        }
        else if(order=="PRI")
        {
            h.Print(outfile);
        }
        else if(order=="DEC")
        {
            int prevKey,newKey;
            infile>> prevKey >> newKey;
            h.DecreaseKey(prevKey,newKey,outfile);

        }
        else if(order=="FIN")
        {
            int value=h.FindMin();
            if(value!=-1)
            {
                cout << "FindMin returned "<< value<< endl;
                outfile << "FindMin returned "<< value<< endl;
            }
            else
            {
                cout << "Empty heap:No minimum"<< endl;
                outfile << "Empty heap:No minimum"<< endl;

            }


        }
        else if(order=="EXT")
        {
            int value=h.ExtractMin();
            if(value==-1)
            {
                cout << "Empty heap:Noting to extract"<< endl;
                outfile << "Empty heap:Nothinf to extract"<< endl;
            }
            else
            {
                cout << "ExtractMin returned "<< value << endl;
                outfile << "ExtractMin returned "<< value << endl;
            }


        }

    }


    infile.close();
    outfile.close();

    return 0;

}
