#include<stdio.h>
long long int fi(long long int n)
{
	long long int result = n,i; 
	for(i=2;i*i <= n;i++) 
	{ 
		if (n % i == 0) result -= result / i; 
		while (n % i == 0) n /= i; 
	} 
	if (n > 1) result -= result / n; 
	return result;

}
int main()
{
	long long int t,k,n;
	scanf("%lld",&t);
	for(k=0;k<t;k++)
	{
		scanf("%lld",&n);
		printf("%lld\n",fi(n));

	}
	return 0;
}
