#include<stdio.h>
#define max 10000007
int a[max+1]={0};
void seive()
{
	int i,j;
	for(i=2;i<=max;i++)
	{
		if(a[i]!=0)
			continue;
		else
		{
			for(j=2*i;j<=max;j=j+i)
			{
				if(a[j]==0)
				{
					a[j]=i;
				}
			}
		}
	}
}
int main()
{
	seive();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)printf("%d\n",n);
		else
		{
			printf("1");
			if(a[n]!=0)
			{
				while(n%a[n]==0)
				{
					printf(" x %d",a[n]);
					if(a[n]==0)
						break;
					n=n/a[n];
					if(a[n]==0)
						break;
				}
			}
			printf(" x %d\n",n);
		}
	}
	return 0;
}
