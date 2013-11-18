#include<stdio.h>
int a[3000]={0};
int p[1001];
int ans[3000];
int calculate()
{
	int i,j;
	a[0]=1;a[1]=1;
	for(i=2;i<3000;i++)
	{
		if(a[i]==0)
		{
			for(j=2*i;j<3000;j=j+i)
			{
				a[j]=1;
			}
		}
	}
	int k=0;
	for(i=0;i<3000;i++)
	{
		if(a[i]==0)
		{
			p[k]=i;
			k++;
		}
	}
	ans[0]=30;
	ans[1]=42;
	int g=2;
	for(i=44;i<3000;i++)
	{
		if(g>1000)
			break;
		int num=i;int count=0;
		for(j=0;p[j]<i;j++)
		{
			if(num%p[j]==0)
			{
				while(num%p[j]==0){
					num=num/p[j];}
				count=count+1;
			}
			if(count==3)
			{
				ans[g]=i;
				g=g+1;
				break;
			}
		}
	}


}
int main()
{
	calculate();
	int t,k,n;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n-1]);
	}
	return 0;
}
