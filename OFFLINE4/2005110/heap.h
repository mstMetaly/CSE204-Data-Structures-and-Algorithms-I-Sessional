#include<iostream>
#include<math.h>
using namespace std;


class Heap
{

private:
    int *arr;
    int index;
    int length;


public:
    Heap(int Size=10)
    {
        index=0;
        length=Size;
        arr=new int[length];
    }

    //operation-1.FindMIn()
    int FindMin()
    {
        if (index>0)
            return arr[1];
        else return -1;
    }

    //operations-2.ExtractMin()
    int ExtractMin()
    {
        if(index==0)
        {
            return -1;
        }
        int minValue=arr[1];
        arr[1]=arr[index];
        index--;

        int i=1;
        while(i<index)
        {
            int left=2 * i;
            int right=2 * i + 1;
            if(arr[left]<arr[right] && arr[left]<arr[i] && left<=index && right<=index)
            {
                int temp=arr[left];
                arr[left]=arr[i];
                arr[i]=temp;
                i=left;
            }
            else if(arr[left]<arr[i] && left<=index && right>index)
            {
                int temp=arr[left];
                arr[left]=arr[i];
                arr[i]=temp;
                i=left;
            }

            else if(arr[right]<arr[left] && arr[right]<arr[i] && left<=index && right<=index)
            {
                int temp=arr[right];
                arr[right]=arr[i];
                arr[i]=temp;
                i=right;
            }
            else
            {
                break;

            }

        }

        return minValue;


    }

    //operation-3.Insert()
    void Insert(int key)
    {
        index++;
        if(index>=length)
        {
            length=length * 2;
            int *arr2=new int[length];
            for(int i=0; i<=index; i++)
            {
                arr2[i]=arr[i];
            }
            delete[] arr;
            arr=new int[length];
            for(int i=0; i<=index; i++)
            {
                arr[i]=arr2[i];
            }
            delete[] arr2;


        }
        arr[index]=key;

        int i=index;
        int parent=i/2;
        while(i>1)
        {
            if(arr[i]<arr[parent])
            {
                int temp=arr[parent];
                arr[parent]=arr[i];
                arr[i]=temp;
                i=parent;
                parent=i/2;
            }
            else
            {
                return;
            }
        }

    }

    //operation-4.DecreaseKey(prevKey,newKey)
    int FindIndex(int prevKey)
    {
        int idx=-1;
        for(int i=1; i<=index; i++)
        {
            if(arr[i]==prevKey)
                idx=i;
        }

        return idx;
    }

    void DecreaseKey(int prevKey,int newKey,ofstream& out)
    {
        int prevKey_index=FindIndex(prevKey);
        if(prevKey_index==-1)
        {
            cout << "Not Found "<< prevKey<< endl;
            out << "Not Found "<< prevKey<< endl;
        }
        else
        {
            arr[prevKey_index]=newKey;

            int childIndex=prevKey_index;
            int parentIndex=childIndex/2;

            while((arr[childIndex]<arr[parentIndex]) && parentIndex>=1)
            {
                int temp=arr[parentIndex];
                arr[parentIndex]=arr[childIndex];
                arr[childIndex]=temp;

                childIndex=parentIndex;
                parentIndex=childIndex/2;
            }

            cout << prevKey << " decreased to "<< newKey<< endl;
            out << prevKey << " decreased to "<< newKey<< endl;

        }
    }

    //opeartion.5-Print()
    void Print(ofstream& out)
    {
        if(index==0)
        {
            cout << "Empty Heap"<< endl;
            out << "Empty Heap"<< endl;

        }
        else
        {
            cout << "Printing the binary heap"<< endl;
            out << "Printing the binary heap"<< endl;
            cout << "-------------------------"<< endl;
            out << "-------------------------"<< endl;
            int level=log(index)/log(2);

            cout << "Level  "<< 0 << ":" ;
            out << "Level  "<< 0 << ":" ;
            cout << arr[1]<< endl;
            out << arr[1]<< endl;


            for(int i=1; i<=level; i++)
            {
                cout << "Level  "<< i << ":";
                out << "Level  "<< i << ":";

                for(int j=pow(2,i); j<pow(2,i+1); j++)
                {
                    if(j<=index)
                        cout << arr[j] << "  ";
                    out << arr[j] << "  ";
                }

                cout << endl;
                out << endl;

            }

            cout << endl;
            out << endl;

        }

    }







};





