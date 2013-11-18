#include<stdio.h>
#include<iostream>
using namespace std;
int v[1050];
int w[1050];
int a[60][1050];
int main()
{
	int l,t,i,j;
	scanf("%d",&t);
	for(i=0;i<60;i++)
		for(j=0;j<1050;j++)
			a[i][j]=0;
	for(l=0;l<t;l++)
	{
		int k,m;
		scanf("%d%d",&k,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&w[i],&v[i]);
		}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(j>=w[i])
				{
					a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+v[i]);
				}
				else
				{
					a[i][j]=a[i-1][j];
				}
			}
		}
		printf("Hey stupid robber, you can get %d.\n",a[m][k]);

	}
	return 0;
}
