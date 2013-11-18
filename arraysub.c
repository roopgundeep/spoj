#include<stdio.h>
long long int a[1000002];
long long int q[100001];
long long int start(long long int s,long long int e)
{
	long long int max=a[s];
	for(i=s;i<e;i++)
	{
		q[i]=a[i];
		if(q[i]>max)
			max=q[i];
	}
	return max;
}
int main()
{
	long long int n,k,i,j,n1,n2,n3,max=0;
	char line[10];
	scanf("%lld",&n);
	scanf("%[^\n]",line);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&k);
	long long int max=start(0,k);
	for(i=)
	return 0;
}
