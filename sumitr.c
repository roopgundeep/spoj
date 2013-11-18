#include<stdio.h>
int max(int a,int b)
{
	if(a>b)return a;
	else
		return b;
}
int main()
{
	int a[100][100];
	int t,n,i,l,j;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<i+1;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<i+1;j++)
			{
				if(j==0)
				{
					a[i][j]=a[i][j]+a[i-1][j];
				}
				else if(j==i)
				{
					a[i][j]=a[i][j]+a[i-1][j-1];
				}
				else
				{
					a[i][j]=max(a[i][j]+a[i-1][j],a[i][j]+a[i-1][j-1]);
				}
			}
		}
		int max=0;
		for(i=0;i<n;i++)
		{
			if(a[n-1][i]>max)
				max=a[n-1][i];
		}
		printf("%d\n",max);
	}
	return 0;
}
