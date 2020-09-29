#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005]={false};
int dist[101];

void BFS_SnL(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    dist[source]=0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int i = 0; i < adj[parent].size(); i++)
        {
            if(!visited[adj[parent][i]])
            {
                q.push(adj[parent][i]);
                visited[adj[parent][i]] = true;
                // As distance of any child/neighbour would be one more than the parent.
                dist[adj[parent][i]]=dist[parent]+1;
            }
            if(adj[parent][i]==100) return;
        }
    }
}

void solveSnL()
{
    int n,m,start,end;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin >> start >> end;
        // Making edges for ladders.
        adj[start].push_back(end);
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin >> start >> end;
        // Making edges for snakes. 
        adj[start].push_back(end);
    }
    // For making connection between a point and the next 6 points.
    for(int i=1; i<=100; i++)
    {
        // If there's a ladder or snake on any of the points then it would directly take us to other end.
        // So we don't need to connect this point to the next 6 points.
        // Just need to connect it to the other end of snake or ladder.
        if(adj[i].size()==1) continue;
        for(int j=i+1; j<=i+6 && j<=100; j++)
        {
            // If there's a ladder or snake at a point then it directly takes us to the other end.
            // So instead of connecting point i to j we connect point i to the other end.
            if(adj[j].size()==1) // We can tell that there's a snake or ladder at a point if there's only one connection.
                adj[i].push_back(adj[j][0]); // adj[3]=[22]
            else
                adj[i].push_back(j);    // adj[2]=[]
        }
    }
    // BFS to calculate distance.
    BFS_SnL(1);
    cout<<dist[100]<<endl;
}

// To initialize everything for performing BFS.
void init_SnL()
{
    for(int i=1; i<=100; i++)
    {
        adj[i].clear();
        dist[i]=-1;
        visited[i]=false;
    }
}

int main() {
    int t=1;
    cin>>t;
    while(t--)
    {
        init_SnL();
        solveSnL();
    }
    return 0;
}
