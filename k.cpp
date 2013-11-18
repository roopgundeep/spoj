#include<cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	int test;
	int n,i,j,k,count,ans,index;
	char str[80];
	int arr[50][50];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",str);
		for(i=0;str[i];i++)
		{
			if(str[i]=='Y')
				arr[0][i]=1;
			else
				arr[0][i]=0;
		}
		n=i;
		for(j=1;j<n;j++)
		{
			scanf("%s",str);
			for(k=0;k<n;k++)
			{
				if(str[k]=='Y')
					arr[j][k]=1;
				else
					arr[j][k]=0;
			}
		}
		index=ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0,count=0;j<n;j++)
			{
				if(i!=j &&arr[i][j]==0)
				{
					for(k=0;k<n;k++){
						if(j!=k){
							if(arr[j][k]==1 && arr[i][k]==1)
								break;
						}
					}
					if(k<n)
						count++;
				}
			}
			if(count>ans){
				ans=count;
				index=i;
			}
		}
		printf("%d %d\n",index,ans);
	}
	return 0;
}


