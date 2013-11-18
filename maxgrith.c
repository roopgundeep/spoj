#include<stdio.h>
int main()
{
	int t,k,i;
	long long int n;
	long long int total;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		total=0;
		scanf("%lld",&n);
		long long int d=(n-2)/3;
		int r=(n-2)%3;
		if(r==2)
		{
			total=(2*d+3)%1000000007;
		}
		else
		{
			total=(2*d+2)%1000000007;
		}
		printf("%lld\n",total);
	}
	return 0;
}
