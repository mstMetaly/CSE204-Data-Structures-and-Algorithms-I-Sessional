#include<iostream>
#include<fstream>
#include<unordered_map>
#include<list>
#include "ArrayQueue.cpp"

using namespace std;

class Graph
{

private:
    unordered_map<int,list<int>> adj;
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfs_visited;

public:
    void createEdge(int u,int v)
    {
        adj[u].push_back(v);
        visited[u]=false;
        visited[v]=false;
        dfs_visited[u]=false;
        dfs_visited[v]=false;
    }

    //BFS-----------

    list<int> BFS(int sourceNode)
    {
        Queue<int>q;
        list<int>ans;
        q.enqueue(sourceNode);
        while(q.length()!=0)
        {
            int frontValue=q.frontValue();
            q.dequeue();

            if(visited[frontValue]==false)
            {
                for(auto i:adj[frontValue])
                {
                    if(visited[i]==false)
                    {
                        int exist=q.findElement(i);
                        if(exist==-1 && i!=frontValue)
                           {
                            q.enqueue(i);
                           }
                    }
                }
            }

            visited[frontValue]=true;
            ans.push_back(frontValue);

        }

        return ans;

    }



    //DFS--------------
    list<int> DFS(int sourceNode,list<int> &dfs_list)
    {
        dfs_list.push_back(sourceNode);
        dfs_visited[sourceNode]=true;

        for(auto i:adj[sourceNode])
        {
            if(dfs_visited[i]==false)
            {
                DFS(i,dfs_list);
            }

        }

        return dfs_list;

    }



};


int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("input.txt");
    outfile.open("output.txt");

    Graph g;

    int n,m;
    infile>> n>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        infile >> u >> v;
        g.createEdge(u,v);
    }

    int s;
    infile>>s;

    cout<< "BFS:";
    outfile<< "BFS:";

    list<int> bfs_travarsal=g.BFS(s);

    list<int>::iterator it;

    for(it=bfs_travarsal.begin(); it!=bfs_travarsal.end(); it++)
    {
        cout<<*it<< "  ";
        outfile<< *it << "  ";
    }

    cout << endl;

    cout << "DFS:";

    list<int>dfs_travarsal;
    dfs_travarsal=g.DFS(s,dfs_travarsal);

    list<int>::iterator it2;

    for(it2=dfs_travarsal.begin(); it2!=dfs_travarsal.end(); it2++)
    {
        cout<<*it2<< "  ";
        outfile<< *it2 << "  ";
    }

    cout<< endl;

    return 0;
}
