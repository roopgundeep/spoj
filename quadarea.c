#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,s;
	int k,i;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		s=(a+b+c+d)/2;
		double p=((s-a)*(s-b)*(s-c)*(s-d));
		printf("%0.2lf\n",sqrt(p));
	}
	return 0;
}
