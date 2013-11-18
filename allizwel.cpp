#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int n,m;
char str[]="ALLIZZWELL";
char a[110][110];
int visit[110][110];
int check(int r,int c,int len)
{
	if(len==10)
		return true;
//	printf("r=%dc=%d\n",r,c);
	visit[r][c]=1;
	int i,j;
	for(i=-1;i<2;i++)
	{
		for(j=-1;j<2;j++)
		{
			int r1=r+i;int c1=c+j;
			if(i==0&&j==0)
				continue;
			if(r1<0 || c1<0 || r1>=n || c1 >=m || a[r1][c1]!=str[len])
				continue;
			if(visit[r1][c1]==1)
				continue;
			if(check(r1,c1,len+1))
			{
				visit[r][c]=0;
				return true;
			}
		}
	}
	visit[r][c]=0;
	return false;
}
int main()
{
	int t,k,i,j;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
	//	a.clear();
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
				scanf("%s",a[i]);	
		}
	//	printf("n=%dm=%d\n",n,m);
		int flag=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				visit[i][j]=0;
			}
		//	printf("\n");
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
		//		printf("%c",a[i][j]);
		//		if(a[i][j]=='A')
		//			printf("r=%dc=%d\n",i,j);
				if(a[i][j]=='A' && check(i,j,1))
				{	flag=0;
					break;}
			}
		//	printf("\n");
		//	if(flag==0)
		//		break;
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
