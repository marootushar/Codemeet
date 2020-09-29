#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005],DFS_result;
bool visited[100005]={false};

void DFS(int source)
{
    visited[source]=true;                   // adj[0]=[1,2,5]  i=0
    DFS_result.push_back(source);           // adj[1]=[0,3,6]  i=0
    for(int i=0; i<adj[source].size(); i++) // adj[2]=[0]      i=0
    {                                       // adj[3]=[1,4]    i=0
        if(!visited[adj[source][i]])        // adj[4]=[3,5]    i=0
        DFS(adj[source][i]);                // adj[5]=[0,4]    i=0
    }                                       // adj[6]=[1]      i=0
}

void print(vector<int> A)
{
    for(int i=0; i<A.size(); i++)
    cout<<A[i]<<" ";
    cout<<endl;
}

void init(int vertices)
{
    for(int i=0; i<vertices; i++) 
        visited[i]=false;
    DFS_result.clear();
}

void DFS_all(int vertices)
{
    for(int i = 0; i < vertices; i++)
    {
        if(!visited[i])
            DFS(i);
    }
}

int main() 
{
    int vertices,edges;
    cin >> vertices >> edges;
    for(int i = 0; i < edges; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0; i <vertices; i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }

    init(vertices);
    DFS(0);
    cout<<"DFS Result : ";
    print(DFS_result);

    init(vertices);
    DFS_all(vertices);
    cout<<"DFS for all Result : ";
    print(DFS_result);
    return 0;
}

// 7 7
// 0 1
// 0 2
// 0 5
// 1 6
// 1 3
// 3 4
// 5 4

// adj[0]=[1,2,5]
// adj[1]=[0,3,6]
// adj[2]=[0]
// adj[3]=[1,4]
// adj[4]=[3,5]
// adj[5]=[0,4]
// adj[6]=[1]

// 9 7
// 0 1
// 1 2
// 1 3
// 2 3
// 3 4
// 7 6
// 6 8

