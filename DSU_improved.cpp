#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Parent[100000];
int Size[100000];

void initialise(int n)
{
    for(int i=0;i<n;i++)
	{
		Parent[i]=i;
        Size[i]=1;
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
        Parent[i] = find(Parent[i]);
        return Parent[i];
     }
}

void Union(int i, int j) 
{
    int iroot = find(i);
    int jroot = find(j);

    if (iroot == jroot)
        return;
    int isize = Size[iroot];
    int jsize = Size[jroot];
    if (isize < jsize) 
    {
        Parent[iroot] = jroot;
        Size[jroot]+=Size[iroot];
    } 
    else 
    {
        Parent[jroot] = iroot;
        Size[iroot]+=Size[jroot];
    } 
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
