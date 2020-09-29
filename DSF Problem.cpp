#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
#define ll long long int

using namespace std;
ll dfs(vector<vector<ll> > &graph, ll i, vector<bool> &visited, vector<ll> &costs){
    //set node as visited
    visited[i]=1;
    ll c=costs[i];
    for(ll j=0;j<graph[i].size();j++){
        if(!visited[graph[i][j]]){
            // Recursively find minimum cost
            c = min(c, dfs(graph, graph[i][j], visited, costs));
        }
    }
    return c;
}
void solve(){
   ll n, edges, i, x, y, finalCost=0;
   // Vertices and Edges
   cin>>n>>edges;
   vector<ll> costs;

   for(i=0;i<n;i++){
    cin>>x;
    costs.push_back(x);
   }
   vector<bool> visited(n, 0);

   vector<vector<ll> > graph(n, vector<ll> (0));
   for(i=0;i<edges;i++){
    cin>>x>>y;
    --x;--y;
    graph[x].push_back(y);
    graph[y].push_back(x);
   }
   //Find cost for each group and add to result
    for(i=0;i<n;i++){
        if(!visited[i])
            finalCost+=dfs(graph, i, visited, costs);
    }
    cout<<finalCost;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
