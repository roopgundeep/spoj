#include<stdio.h>
int main()
{
	int m,t;
	scanf("%d\n",&t);
	for(m=0;m<t;m++)
	{
		long long int n,max,i,j,k,numerator=1,denominator=1;
		scanf("%lld%lld",&n,&k);
//		printf("%lld,%lld\n",n,k+1);
		if(k-1<n-k)
		{
			max=n-k;
		}
		else
		{
			max=k-1;
		}
		if(n==k)
		{
			printf("1\n");
		}
		else if(n==k+1)
		{
			printf("%lld\n",k);
		}
		else
		{
			for(i=n-1;i>max;i--)
			{
				numerator=numerator*(i);
				numerator=numerator/denominator;
				denominator++;
			}
			printf("%lld\n",numerator);
		}
	}
	return 0;
}
