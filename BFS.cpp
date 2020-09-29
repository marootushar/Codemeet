#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005],BFS_result;
bool visited[100005]={false};

void BFS(int source)
{
    // Queue to store elements we need to explore.
    queue<int> q;
    // We need to check source so we push source to the queue.
    q.push(source);
    visited[source] = true;
    // Loop till we have no elements to explore.
    while(!q.empty())
    {
        // Taking out first element from the queue.
        int parent = q.front();
        // As we are going to explore the first element so we pop it out.
        q.pop();
        // Push parent to results.
        BFS_result.push_back(parent);
        // To explore all elements of parent.
        for(int i = 0; i < adj[parent].size(); i++)
        {
            if(!visited[adj[parent][i]])
            {
                // Push to queue as we need to explore it.
                q.push(adj[parent][i]);
                visited[adj[parent][i]] = true;
            }
        }
    }
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
    BFS_result.clear();
}

void BFS_all(int vertices)
{
    for(int i = 0; i < vertices; i++)
    {
        if(!visited[i])
            BFS(i);
    }
}

int main() {
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

    BFS(0);
    cout<<"BFS Result : ";
    print(BFS_result);

    init(vertices);
    BFS_all(vertices);
    cout<<"BFS for all Result : ";
    print(BFS_result);
    return 0;
}

// TESTCASE 1
// 7 7
// 0 1
// 0 2
// 0 5
// 1 6
// 1 3
// 3 4
// 5 4

// TESTCASE 1 IN ADJACENCY LIST
// adj[0]=[1,2,5]
// adj[1]=[0,3,6]
// adj[2]=[0]
// adj[3]=[1,4]
// adj[4]=[3,5]
// adj[5]=[0,4]
// adj[6]=[1]

// TESTCASE 2
// 9 7
// 0 1
// 1 2
// 1 3
// 2 3
// 3 4
// 7 6
// 6 8