#include<stdio.h>
#include<iostream>
using namespace std;
long long int a[502];
long long int p[502];
int flag[502];
long long int getmost(int m,int k)
{
	int n=m,i;long long int hi=0;
	long long int lo=a[m-1];
	for(i=0;i<m;i++)
		hi=hi+a[i];
	while(lo<hi)
	{
		long long int x= lo + (hi-lo)/2;
		long long int required =1,current_load =0;
		for(i=1;i<=m;++i){
			if(current_load + a[i] <=x)
			{
				current_load +=a[i];
			}
			else{
				++required;
				current_load=a[i];
			}
		}
		if(required <= k)
			hi=x;
		else
			lo=x+1;
	}
	return lo;
}
void print(int m,int b,long long int value)
{
	int i;
	for(i=0;i<m;i++)
		flag[i]=0;
	int k=0;
	long long int sum=0;
	for(i=m-1;i>=0;i--)
	{
		if(sum+a[i]<=value)
		{
			sum=sum+a[i];
		}
		else
		{
			printf("i=%dsum=%lld\n",i,sum);
			sum=a[i];
			flag[i]=1;
			k=k+1;
		}
	}
	int temp=0;
	while(k<b)
	{
		if(flag[temp]==0)
		{
			flag[temp]=1;k=k++;
		}
		temp++;
	}

	for(i=0;i<m;i++)
	{
		if(flag[i]==1 && i!=m-1)
		{
			printf("%lld ",a[i]);
			printf("/ ");
		}
		else if(i==m-1)
		{
			printf("%lld\n",a[i]);
		}
		else
		{
			printf("%lld ",a[i]);
		}
	}
}

int main()
{
	int t,l,k,m,i,j;
	scanf("%d",&t);
	for(l=0;l<t;l++)
	{
		scanf("%d%d",&m,&k);
		p[0]=0;
		for(i=1;i<m;i++)
		{
			scanf("%lld",&a[i]);
	//		sum=sum+a[i];
			p[i]=p[i-1]+a[i];
			
		}
		long long int value=getmost(m,k);
		print(m,k,value);
	}
	return 0;
}
