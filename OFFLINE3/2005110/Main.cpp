#include<iostream>
#include "BST.hpp"
#include<fstream>
#include<cstring>

using namespace std;


int main()
{

    ifstream infile;
    ofstream outfile;

    BST bst;

    infile.open("Input.txt");
    outfile.open("Output.txt");

    while(!infile.eof())
    {

        char order;
        int parameter;

        infile >> order;
        if(!infile.eof())
        {
            switch (order)
            {

            case 'I':
            {
                infile >> parameter;
                bst.Insert(parameter);
                bst.print();
                bst.write(outfile);
                break;
            }

            case 'F':
            {
                infile >> parameter;
                cout <<boolalpha<< bst.Find(parameter)<< endl;
                outfile <<boolalpha<< bst.Find(parameter)<< endl;
                break;

            }

            case 'D':
            {
                infile >> parameter;
                bool t=bst.Delete(parameter);

                if(t==true)
                {
                    bst.print();
                    bst.write(outfile);
                    break;

                }

                if(t==false)
                {
                    cout << "Invalid Operation"<< endl;
                    outfile<< "Invalid Operation"<< endl;
                    break;

                }


            }

            case 'T':
            {
                string chOrder ;
                infile >> chOrder;


                if(chOrder=="In")
                {
                    bst.InOrderTravarsal(outfile);
                    break;
                }

                else if(chOrder=="Pre")
                {
                    bst.PreOrderTravarsal(outfile);
                    break;
                }

                else if(chOrder=="Post")
                {
                    bst.PostOrderTravarsal(outfile);
                    break;
                }
            }
            }
        }
    }

    infile.close();
    return 0;


}
