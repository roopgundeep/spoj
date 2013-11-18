#include<stdio.h>
#include<stdlib.h>
long long int a[200002];
long long int temp[200002];
long long int merge(long long int a[],long long int left,long long int mid,long long int right)
{
	long long int inv_count=0;
	long long int i,j,k;
	i=left;j=mid;k=left;
	while(i<=mid-1 && j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
	//		continue;
		}
		else
		{
			temp[k++]=a[j++];
	//		continue;
			inv_count=inv_count+(mid-i);
		}
	}
	while(i<=mid-1)
		temp[k++]=a[i++];
	while(j<=right)
		temp[k++]=a[j++];
	for(i=left;i<=right;i++)
		a[i]=temp[i];
	return inv_count;
}
long long int mergecount(long long int a[],long long int left,long long int right)
{
	long long int mid,inv=0;
	if(right>left)
	{
		mid=(left+right)/2;
		inv=mergecount(a,left,mid);
	//	printf("inv1=%lld\n",inv);
		inv=inv+mergecount(a,mid+1,right);
	//	printf("inv2=%lld\n",inv);
		inv=inv + merge(a,left,mid+1,right);
	//	printf("inv3=%lld\n",inv);
	//	printf("%lld\n",inv);
	}
	return inv;
}
int main()
{
	int t,k;
	long long int n,i;
	scanf("%d",&t);
	char line[10];
	for(k=0;k<t;k++)
	{
		scanf("%[^\n]",line);
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		printf("%lld\n",mergecount(a,0,n-1));
	}
	return 0;
}
