#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t,k,i,j;
	char str[10];
	char line[10];
	scanf("%d",&t);
	int grid[4][4];
	for(k=0;k<t;k++)
	{
//		scanf("%s",line);
//		getchar();
		int number_x=0;
		int number_o=0;
		for(i=0;i<3;i++)
		{
			scanf("%s",str);
			for(j=0;j<3;j++)
			{
				if(str[j]=='X')
				{
					grid[i][j]=1;
					number_x=number_x+1;
				}
				else if(str[j]=='O')
				{
					grid[i][j]=0;
					number_o=number_o+1;
				}
				else
					grid[i][j]=-1;
			}


		}
		int winx=0;int wino=0;
		int count_x=0;
		int count_o=0;
		for(i=0;i<3;i++)
		{
			count_x=0;
			count_o=0;
			for(j=0;j<3;j++)
			{
				if(grid[i][j]==1)
					count_x++;
				else if(grid[i][j]==0)
					count_o++;
			}
			if(count_x==3)
				winx=winx+1;
			else if(count_o==3)
				wino=wino+1;
		}
		for(i=0;i<3;i++)
		{
			count_x=0;
			count_o=0;
			for(j=0;j<3;j++)
			{
				if(grid[j][i]==1)
					count_x++;
				else if(grid[j][i]==0)
					count_o++;
			}
			if(count_x==3)
				winx=winx+1;
			else if(count_o==3)
				wino=wino+1;
		}
		count_x=0;
		count_o=0;
		for(i=0;i<3;i++)
		{
			if(grid[i][i]==1)
				count_x++;
			else if(grid[i][j]==0)
				count_o++;
		}
		if(count_x==3)
			winx++;
		else if(count_o==3)
			wino++;
		count_x=0;
		count_o=0;
		for(i=0,j=2;i<3;i++,j--)
		{
			if(grid[i][i]==1)
				count_x++;
			else if(grid[i][j]==0)
				count_o++;
		}
		if(count_x==3)
			winx++;
		else if(count_o==3)
			wino++;
//		printf("winx=%d,wino=%d,x=%d,y=%d\n",winx,wino,number_x,number_o);
		if(number_o>number_x||(number_o==number_x && winx)||number_x>number_o+1||(number_x==number_o+1 && wino)||winx>2||wino>1||(winx && wino))
			printf("no\n");
		else
			printf("yes\n");
	}

	return 0;
}
