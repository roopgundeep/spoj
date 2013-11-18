#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
int gd[100000002];
long long int gcd(long long int a, long long int b)
{
	int t;

	while(b!=0)
	{   
		t = b;
		b = a%b; // B's now the remainder of A/B.
		a = t;
	} // And we go to the next iteration.

	return a;
}
int  main()
{

	long long int h1,h2,h3;
	long long int n,k,i,l,sum=0,j;
	for(i=0;i<100000002;i++)
		gd[i]=0;
	scanf("%lld",&k);
	for(j=0;j<k;j++)
	{
		sum=0;
		scanf("%lld",&n);
		for(i=1;i<=n-2;i++)
		{
			long long int a,b,c,m;
			h1=h2=h3=0;
			if(gd[i]==1)
			{
				sum=(sum+i)%n;
			}
			else
			{
				a=i,b=i+1,c=i+2;
				h1=gcd(a,b);
				if(h1==1)
				{
					h2=gcd(a,c);
					if(h2==1)
						h3=gcd(b,c);
				}
				if(h1==1 && h2==1 && h3==1)
				{
					sum=(sum+i)%n;
					gd[i]=1;
				}
			}
		}
		printf("%lld\n",sum);
	}

	return 0;
}
