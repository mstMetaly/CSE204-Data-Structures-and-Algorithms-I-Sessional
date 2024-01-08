#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

class Pair
{
private:
    int startTime;
    int endTime;
public:
    Pair()
    {

    }
    Pair(int startTime,int endTime)
    {
        this->startTime=startTime;
        this->endTime=endTime;
    }

    Pair(const Pair& ob)
    {
        this->startTime=ob.startTime;
        this->endTime=ob.endTime;

    }
    ~Pair()
    {

    }
    int get_startTime()
    {
        return startTime;
    }

    int get_endTime()
    {
        return endTime;
    }

    Pair* operator=(const Pair& ob)
    {
        this->startTime=ob.startTime;
        this->endTime=ob.endTime;
        return this;
    }

};

static bool cmp(Pair a,Pair b)
{
    return a.get_endTime()<b.get_endTime();
}

vector<Pair> find_maxCustomer(int startTime[],int endTime[],int n)
{
    vector<Pair>answer;
    Pair *cusArr=new Pair[n];
    for(int i=0; i<n; i++)
    {
        Pair p(startTime[i],endTime[i]);
        cusArr[i]=p;
    }

    sort(cusArr,cusArr+n,cmp);

    int serviceLast=cusArr[0].get_endTime();
    answer.push_back(cusArr[0]);
    for(int i=1; i<n; i++)
    {
        if(cusArr[i].get_startTime()>=serviceLast)
        {
            serviceLast=cusArr[i].get_endTime();
            answer.push_back(cusArr[i]);
        }
    }

    return answer;


}


int main()
{
    ofstream outfile;
    ifstream infile;

    infile.open("input.txt");
    outfile.open("output.text");
    int n;
    infile>>n;

    int startTime[n];
    int endTime[n];
    for(int i=0; i<n; i++)
    {
        int startS,endS;
        infile>> startS>> endS;
        startTime[i]=startS;
        endTime[i]=endS;
    }

    vector<Pair> ans=find_maxCustomer(startTime,endTime,n);
    outfile<< "Max Service:"<< ans.size()<< endl;
    cout << "Max Service:"<< ans.size()<< endl;
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i].get_startTime()<< "  "<< ans[i].get_endTime()<< endl;
        outfile << ans[i].get_startTime()<< "  "<< ans[i].get_endTime()<< endl;

    }

    return 0;
}
