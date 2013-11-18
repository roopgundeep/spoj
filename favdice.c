#include<stdio.h>
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		double n,t;
		scanf("%lf",&n);
		t=n;
		double num=1;
		while(n-->1)
		{
			num+=(double)(t*1/n);
		}
		printf("%.2lf\n",num);

	}
	return 0;
}
