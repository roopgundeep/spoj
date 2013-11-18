#include<stdio.h>
char arr[2665];
int prime[1000];
int ans[1000];
int main()
{
	int i,j,ct=0,flag=0;
	for(i=1;i<2665;i=i+2)
		arr[i]='0';
	for(i=4;i<2665;i=i+2)
		arr[i]='1';
	prime[0]=2;
	ct++;
	for(i=3;i<2665;i=i+2)
	{
		if(arr[i]!='1')
		{
			prime[ct++]=i;
			for(j=2;j*i<1001;j++)
				arr[j*i]='1';
		}
	}
	ans[0]=30;
	ans[1]=42;
	int t=2,num2,count;
	for(i=44;i<2665;i++)
	{
		num2=i;count=0;
		for(j=0;prime[j]<=num2;j++)
		{
			if(num2%prime[j]==0)
			{
				while(num2%prime[j]==0)
					num2=num2/prime[j];
				//			if(i==66)
				//				printf("%d %d\n",prime[j],num2);
				count++;
			}
			if(count==3)
			{
				ans[t++]=i;
				break;
			}
		}
	}
	for(i=0;i<1000;i++)
		printf("%d\n",ans[i]);
	/*int num1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num1);
		printf("%d\n",ans[num1-1]);
	}*/
	return 0;
}


