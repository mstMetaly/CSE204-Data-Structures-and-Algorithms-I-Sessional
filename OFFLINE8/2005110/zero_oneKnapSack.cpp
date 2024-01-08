#include<iostream>
#include<fstream>
using namespace std;


int optimal(int k,int w,int **arr,int weight[],int value[])
{
    if(arr[k][w]!=(-1))
        return arr[k][w];
    if(weight[k]>w)
        return optimal(k-1,w,arr,weight,value);
    else
    {
        return max(optimal(k-1,w,arr,weight,value),optimal(k-1,w-weight[k],arr,weight,value)+value[k]);
    }


}

int knapSack(int k,int w, int weight[],int value[],ofstream &out )
{
    int **arr;
    arr = new int *[k+1];

    for(int i = 0; i <=k; i++)
    {
        arr[i] = new int[w+1];
    }

    for(int i=0; i<=k; i++)
    {
        arr[i][0]=0;
    }

    for(int i=0; i<=w; i++)
    {
        arr[0][i]=0;
    }

    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=w; j++)
        {
            arr[i][j]=(-1);

        }

    }


    for(int i=0; i<=k; i++)
    {
        for(int j=0; j<=w; j++)
        {
            arr[i][j]=optimal(i,j,arr,weight,value);
        }
    }

    int item=k;
    int col=w;
    while(item>0)
    {
        if(arr[item][col]<=arr[item-1][col])
            item--;
        else
        {
            cout << weight[item]<< "  ";
            out <<weight[item]<< "  ";
            col=(col-weight[item]);
            item--;
        }
    }
    cout<< endl;
    out<< endl;
    return arr[k][w];

}

int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("input.txt");
    outfile.open("output.txt");

    int k,w;
    infile >> k ;

    int weight[k];
    int value[k];

    for(int i=1; i<=k; i++)
    {
        int val,wgt;
        infile >> wgt >> val;
        weight[i]=wgt;
        value[i]=val;

    }

    infile>> w;

    int profit=knapSack(k,w,weight,value,outfile);
    cout <<"Profit:"<< profit << endl;



    return 0;
}
