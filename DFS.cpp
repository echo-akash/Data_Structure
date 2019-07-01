#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adjlist[100];
int start[100]={0};
int ending[100]={0};
int visi[100]={0};
int visited[100]={0};
int t=0;
    void dfs( int node)
    {
        int k;
             visited[node]=1;
             t++;
             start[node]=t;
     for(int x=0;x<adjlist[node].size();x++)
     {
         k=adjlist[node].at(x);
         if(visited[k]==0)
             dfs(k);

         }
         t=t+1;
         ending[node]=t;
     }




int main()
{
    int j,k;
    cout<<"Node: ";
    cin>>n;
    cout<<"\nEdge: ";
    cin>>m;
    cout<<endl;
    for(int i=1;i<=m;i++)
    {
     cout<<"\nNode: ";
     cin>>k;
     cout<<"\nValue: ";
     cin>>j;
     adjlist[k].push_back(j);

    }
    for(int i=1;i<=n;i++)
    {
     cout<<i<<"-->";
     for(int x=0;x<adjlist[i].size();x++)
     {
         cout<<adjlist[i][x]<<" ";
     }
     cout<<endl;

    }
    int node;
    cin>>node;
    dfs(node);
    cout<<"Vertex:\td.time\tf.time\n\n";
    for(int i=1;i<=n;i++)
    {
        if(ending[i]!=0 && start[i]!=0)
        {
          cout<<i<<"\t"<<start[i]<<"\t"<<ending[i]<<endl;
        }
    }

    return 0;
}
