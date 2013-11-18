#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
using namespace std;
map<char,int>value;
map<int,char>content;
int main()
{
	value['A']=1;
	value['B']=2;
	value['C']=3;
	value['D']=4;
	value['E']=5;
	value['F']=6;
	value['G']=7;
	value['H']=8;
	value['I']=9;
	value['J']=10;
	value['K']=11;
	value['L']=12;
	value['M']=13;
	value['N']=14;
	value['O']=15;
	value['P']=16;
	value['Q']=17;
	value['R']=18;
	value['S']=19;
	value['T']=20;
	value['U']=21;
	value['V']=22;
	value['W']=23;
	value['X']=24;
	value['Y']=25;
	value['Z']=26;
	content[1]='A';
	content[2]='B';
	content[3]='C';
	content[4]='D';
	content[5]='E';
	content[6]='F';
	content[7]='G';
	content[8]='H';
	content[9]='I';
	content[10]='J';
	content[11]='K';
	content[12]='L';
	content[13]='M';
	content[14]='N';
	content[15]='O';
	content[16]='P';
	content[17]='Q';
	content[18]='R';
	content[19]='S';
	content[20]='T';
	content[21]='U';
	content[22]='V';
	content[23]='W';
	content[24]='X';
	content[25]='Y';
	content[26]='Z';
	int t,k,i;
	char line[1002];
	char p;
	scanf("%d",&t);
	int max=0,duplicate=0;
	for(k=0;k<t;k++)
	{
		max=0;duplicate=0;
		map<char,int>count;
		getchar();
		scanf("%[^\n]",line);
		int length=strlen(line);
		for(i=0;i<length;i++)
		{
			if(line[i]!=' ')
			{
				count[line[i]]++;
				if(max<count[line[i]])
				{
					p=line[i];
					max=count[line[i]];
					duplicate=0;
				}
				else if(max==count[line[i]])
				{
					duplicate=1;
				}
			}
		}
	//	printf("%d\n",value[p]);
		int d=value[p]-value['E'];
		if(duplicate==0)
		{
			if(d<0)
			{
				printf("%d ",26+d);
				d=d+26;
			}
			else
				printf("%d ",d);
			for(i=0;i<length;i++)
			{
				if(line[i]!=' ')
				{
					if(value[line[i]]-d>0)
					{
						printf("%c",content[value[line[i]]-d]);
					}
					else
					{
						printf("%c",content[26+value[line[i]]-d]);
					}
				}
				else
					printf(" ");
			}
			printf("\n");
		}
		else
		{
			printf("NOT POSSIBLE\n");
		}
	}
	
	return 0;
}
