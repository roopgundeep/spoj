#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long int dp[100003];
int main()
{
	int k,t;long long int i,j,n,c=0;
	scanf("%d",&t);
	char s[100003];
	for(k=0;k<t;k++)
	{
		scanf("%s",s);
		 n=strlen(s);
		for(i=0;i<=n;i++)
			dp[i]=0;
		dp[0]=1;
		for(i=0;i<n;i++)
		{
			c=0;
			dp[i+1]=dp[i]+1000000007;
			for (j = i-1; j >= 0; --j) 
			{
           		 	if (s[i] == s[j]) 
			 	{
					c = dp[j];break;
				}
			}
			dp[i+1]=(dp[i+1]-c);
			if(dp[i+1]>=1000000007)
			{
				dp[i+1]-=1000000007;
			}
			dp[i+1]=dp[i+1]+dp[i];
			if(dp[i+1]>=1000000007)
			{
				dp[i+1]=dp[i+1]-1000000007;
			}
			//index[s[i]]=i;
		}
		printf("%lld\n",dp[n]);
		
	}
	return 0;
}

