#include<iostream>
#include<fstream>
using namespace std;

int merge_count(int *arr,int s,int e)
{

   int mid=(s+e)/2;
   int len1=mid-s+1;
   int len2=e-mid;

   int *first=new int[len1];
   int *second=new int[len2];

   int index=s;
   for(int i=0;i<len1;i++)
   {
        first[i]=arr[index++];
   }

   for(int i=0;i<len2;i++)
   {
       second[i]=arr[index++];
   }

   //merge two sorted arrays
   int index1=0;
   int index2=0;
   index=s;
   int inversion=0;

   while(index1<len1 && index2<len2)
   {
      if(first[index1] > second[index2])
      {
          arr[index++]=second[index2];
          index2++;
          inversion+=(len1-index1);
      }
      else if(first[index1]<second[index2])
      {
          arr[index++]=first[index1];
          index1++;
      }
      else{
        arr[index++]=first[index1++];

      }
   }

   while(index1<len1)
   {
       arr[index++]=first[index1++];
   }

   while(index2<len2)
   {
       arr[index++]=second[index2++];
   }

    delete[] first;
    delete[] second;

    return inversion;

}

int divide_conquer(int *arr,int s,int e)
{
    if(s>=e)
        return 0;
    int mid=(s+e)/2;
    int rA=divide_conquer(arr,s,mid);
    int rB=divide_conquer(arr,mid+1,e);
    int r=merge_count(arr,s,e);

    return rA+rB+r;
}

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("input.txt");

    int n;
    infile>>n;

    int arr[n];
    int arr2[n];

    for(int i=0;i<n;i++)
    {
        infile>> arr[i];
        arr2[i]=arr[i];
    }

    int inversion=divide_conquer(arr,0,n-1);

    cout << "Inversion:"<< inversion << endl<< endl;
    cout << "The inverted pairs are:"<< endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr2[i]>arr2[j])
                cout << "("<< arr2[i]<< ","<< arr2[j]<< ")"<< endl;
        }
    }

    return 0;

}
