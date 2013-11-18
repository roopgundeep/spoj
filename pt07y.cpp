#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
map<int,int>edge;
int main()
{
	int n,m,i,u,v;
	scanf("%d%d",&n,&m);
	if(m!=n-1)
	{
		printf("NO\n");
	}
	else
	{
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			if(edge[u]==1 && edge[v]==1)
			{
				printf("NO\n");
				return 0;
			}
			edge[u]=1;
			edge[v]=1;
		}
		printf("YES\n");
	}
	return 0;
}
