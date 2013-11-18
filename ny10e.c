#include<stdio.h>
long long int dp[65][10];
count(int n)
{
	int i,j;
	if(dp[n][9]!=0)
		return;
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	return;
}
int main()
{
	int t,k,j,i,n,m;
	scanf("%d",&t);
	for(i=0;i<65;i++)
	{
		for(j=0;j<10;j++)
		{
			dp[i][j]=0;
		}
	}
	for(i=0;i<65;i++)
		dp[0][i]=1;
	for(i=0;i<10;i++)
		dp[i][0]=1;	
	for(k=0;k<t;k++)
	{
		scanf("%d%d",&m,&n);
		count(n);
		printf("%lld\n",dp[n][9]);
	}
	return 0;
}
