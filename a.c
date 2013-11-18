#include<stdio.h>
typedef long long int li;
int main()
{
	int t;
	li n,k,min,max,i,ans1,ans2;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		if(k-1<n-k){
			min =k-1;
			max= n-k;
		}
		else{
			min = n-k;
			max = k-1;
		}
		if(n==k)
			printf("1\n");
		else if(n==k+1)
			printf("%lld\n",k);
		else
		{
			ans1=1,ans2=1;
			for(i=n-1;i>max;i--)
			{
				ans1*=i;
				ans1/=ans2;
				ans2++;
			}
			printf("%lld\n",ans1);
		}
	}
	return 0;
}


