// Jeet's app problem from Sudo Code

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Parent[100000];
int Cost[100000];

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

void join(int i, int j) 
{
    int irep = find(i);
    int jrep = find(j);

    if (irep == jrep)
        return;
    int icost = Cost[irep];
    int jcost = Cost[jrep];
    if (icost > jcost) 
    {
        Parent[irep] = jrep;
    } 
    else if (jcost > icost) 
    {
        Parent[jrep] = irep;
    } 
    else
    {
        Parent[irep] = jrep;
    }
}

int main() {
	long long int n,m,a,b,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		Parent[i]=i;
		cin>>Cost[i];
	}
	while(m--)
	{
		cin>>a>>b;
		join(a-1,b-1);
	}
	for(int i=0;i<n;i++)
	{
		if(i==find(i))
		{
			sum+=Cost[i];
		}
	}
	cout<<sum;
	return 0;
}