#include<stdio.h>
#include<math.h>
#define max 1000002
int main()
{
	long long int a[1000005],i,j;
	double fact,pow,v;
	fact=log(2.0);j=2;
	for(i=2;i<=max;i++)
	{	
		v=log((double)i);
		for(++j; ;j++)
		{
			fact=fact+log((double)j);
			pow=v*j;
			if(fact>pow)
			{
				a[i]=j;
				break;
			}
		}
	}
	long long int t,k,n;
	scanf("%lld",&t);
	for(k=0;k<t;k++)
	{
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}
