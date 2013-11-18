#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int t,k,i,j,l;
	char str[55];
	char string[55];
	scanf("%d",&t);
	int a[55][55];
	int count[55];
	for(k=0;k<t;k++)
	{
		int n;
		scanf("%s",string);
		for(i=0;i<strlen(string);i++)
		{
			if(string[i]=='N')
				a[0][i]=0;
			else
				a[0][i]=1;
		}
		n=strlen(string);
		for(i=0;i<n;i++)
			count[i]=0;
		for(i=1;i<n;i++)
		{
			scanf("%s",str);
			for(j=0;j<n;j++)
			{
				if(str[j]=='N')
					a[i][j]=0;
				else
					a[i][j]=1;
			}
		}
		int c=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]==1)
				{
					c=0;
					for(l=0;l<n;l++)
					{
						if(a[j][l]==1 && a[i][l]!=1 && l!=i)
						{
							c=c+1;
						}
					}
					if(c>count[i])
						count[i]=c;
				}
			}
		}
//		for(i=0;i<n;i++)
//			printf("%d ",count[i]);
		int max=count[0];
		int p=0;
		for(i=0;i<n;i++)
		{
			if(count[i]>max)
			{
				max=count[i];
				p=i;
			}
		}
		printf("%d %d\n",p,max);

	
	}
	return 0;
}
