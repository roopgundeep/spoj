#include<stdio.h>
long long int coins[1002];
long long int dp[1002];
long long int max(long long int a,long long int b)
{
	if(a>b)
		return a;
	else
		return b;
}
long long int s(long long int n)
{
	if(dp[n]!=-1)
		return dp[n];
	else
		dp[n]=max(s(n-1),s(n-2)+coins[n]);
	return dp[n];
}
int main()
{
	long long int t,k,n,i;
	scanf("%lld",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&coins[i]);
			dp[i]=-1;
		}
		if(n>1)
		{
			if(coins[0]>coins[1])
			{
				dp[0]=coins[0];
				dp[1]=coins[0];
			}
			else
			{
				dp[1]=coins[1];
				dp[0]=coins[0];
			}
			long long int answer=s(n-1);
			printf("Case %lld: %lld\n",k,answer);
		}
		else if(n!=0) 
		{
			printf("Case %lld: %lld\n",k,coins[0]);
		}
		else
		{
			printf("Case %lld: 0\n",k);
		}

	}
	return 0;
}
