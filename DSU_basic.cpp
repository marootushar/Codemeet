#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Parent[100000];

void initialise(int n)
{
    for(int i=0;i<n;i++)
	{
		Parent[i]=i;
	}
}

int find(int i) 
{
    if (Parent[i] == i) 
    {
        return i;
    }
    else
    { 
        return find(Parent[i]);
    }
}

void Union(int i, int j) 
{
    int ir = find(i);
    int jr = find(j);
    Parent[ir] = jr;
}

int main() 
{
	int n,m,a,b;
	cin>>n>>m;
	initialise(n);
	while(m--)
	{
		cin>>a>>b;
		Union(a,b);
	}
	cin>>a>>b;
	if(find(a)==find(b))
		cout<<"Same set";
	else
		cout<<"Different set";	
	return 0; 
} 
