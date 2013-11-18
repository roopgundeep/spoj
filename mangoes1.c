#include<stdio.h>
typedef long long int li;
int main()
{
	li t,ans,n,terms;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n%2==0)
			terms = (n>>1) -1;
		else
			terms = n>>1;
		printf("%lld\n",(terms*terms)%n);
	}
	return 0;
}
