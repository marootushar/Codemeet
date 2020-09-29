#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
#define ll long long int


using namespace std;

int main(){
    int v, e, x, y, i, j, w;
    cin>>v>>e;
    vector<vector<bool> > AdjMat(v, vector<bool> (v, 0));
    vector<vector<int> > AdjList(v);
    for(i=0;i<e;i++){
        cin>>x>>y;
        AdjList[--x].push_back(--y);
        AdjList[y].push_back(x);
        AdjMat[x][y]=1;
        AdjMat[y][x]=1;
    }
    cout<<"Adjacency Matrix :\n";
    for(i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Adjacency List :\n";
    for(i=0;i<v;i++){
        for(j=0;j<AdjList[i].size();j++){
            cout<<AdjList[i][j]<<" ";
        }
        cout<<endl;
    }
    //Weighted and Directed
    cin>>v>>e;
    vector<vector<int> > AdjMatWt(v, vector<int> (v, 0));
    vector<vector<pair<int, int> > > AdjListWt(v);

    for(i=0;i<e;i++){
        cin>>x>>y>>w;
        AdjMatWt[--x][--y]=w;
        AdjListWt[x].push_back(make_pair(y, w));
    }
    cout<<"Adjacency Matrix :\n";
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            cout<<AdjMatWt[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Adjacency List :\n";
    for(i=0;i<v;i++){
        for(j=0;j<AdjListWt[i].size();j++){
            cout<<AdjListWt[i][j].first<<" "<<AdjListWt[i][j].second<<"\t";
        }
        cout<<endl;
    }
}
/*
5 5
1 2
2 3
3 4
4 5
1 4

5 5
1 2 10
2 3 11
3 4 12
4 5 13
2 1 14

*/
