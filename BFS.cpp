//final
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int dist[100];
int parent[100];
int bipartitecolor[100];
vector<int> adjList[100];
queue<int> q;




void bfs(int sour)
{

    for(int i=1;i<=n;i++)
    {
        if(n!=1)
        {
            parent[i]=0;
            dist[i]=-1;
        }
    }
    parent[sour]=0;
    dist[sour]=0;

    q.push(sour);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int j=0;j<adjList[x].size();j++)
        {
            int v=adjList[x][j];
            if(parent[v]==0)
            {
                dist[v]=dist[x]+1;
                parent[v]=x;
                q.push(v);
            }
        }
    }
}






int main()
{
//    cout<<"Enter Node_";
//    cin>>n;
//    cout<<"Enter Edges_";
//    cin>>m;
n=7;m=11;
    adjList[1].push_back(2);
    adjList[1].push_back(4);
    adjList[2].push_back(3);
    adjList[2].push_back(5);
    adjList[3].push_back(5);
    adjList[4].push_back(3);
    adjList[4].push_back(5);
    adjList[5].push_back(4);
    adjList[6].push_back(3);
    adjList[6].push_back(7);
    adjList[7].push_back(3);
    int x,y;
//    for(int i=1;i<=m;i++)
//    {
//        cin>>x;
//        cin>>y;
//        adjList[x].push_back(y);
//    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -->";
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }

bfs(1);
for(int i=1;i<=n;i++)
{
    cout<<"\tVertex="<<i;
    cout<<"\tParent="<<parent[i];
    cout<<"\tDistance="<<dist[i];
    cout<<endl;
}





    return 0;
}






























































































/*
//Bipartite


#include <iostream>
#include <queue>
#define V 4
using namespace std;

// This function returns true if graph G[V][V] is Bipartite, else false
bool isBipartite(int G[][V], int src)
{
    // Create a color array to store colors assigned to all veritces. Vertex
    // number is used as index in this array. The value '-1' of  colorArr[i]
    // is used to indicate that no color is assigned to vertex 'i'.  The value
    // 1 is used to indicate first color is assigned and value 0 indicates
    // second color is assigned.
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // Assign first color to source
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();

         // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            // An edge from u to v exists and destination v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can be colored with
    // alternate color
    return true;
}

// Driver program to test above function
int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
    return 0;
}



*/
