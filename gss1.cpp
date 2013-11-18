#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct tree
{
	long long int maxv;
	long long int leftsum;
	long long int rightsum;
	long long int sum;
}tree;
#define max 50002
tree s[1000002];
int a[1000002];
int max2(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int max3(int a,int b,int c)
{
	int m;
	if(a>b)
	{
		m=a;	
	}
	else
		m=b;
	if(m>c)
		return m;
	else
		return c;
}
void initialize(int node,int b,int e)
{
	if(b==e)
	{
		s[node].maxv=a[b];
		s[node].leftsum=a[b];
		s[node].rightsum=a[b];
		s[node].sum=a[b];
		return;
	}
	long long int mid=(b+e)/2;
	initialize(2*node,b,mid);
	initialize(2*node+1,mid+1,e);
	s[node].sum=s[node*2].sum+s[node*2+1].sum;
	s[node].maxv=max3(s[node*2].maxv,s[node*2+1].maxv,s[node*2].rightsum+s[node*2+1].leftsum);
	s[node].leftsum=max2(s[node*2].leftsum,s[node*2].sum + s[node*2+1].leftsum);
	s[node].rightsum=max2(s[node*2+1].rightsum,s[node*2+1].sum+s[node*2].rightsum);

}
void query(tree &answer,int node,int L,int R,int i,int j)
{
	if(L==i && R==j)
	{
		answer=s[node];
		return;
	}
	long long int m=(L+R)/2;
	if(j<=m)
	{
		query(answer,2*node,L,m,i,j);
	}
	else if(i>m)
	{
		query(answer,2*node+1,m+1,R,i,j);
	}
	else
	{
		tree right,left;
		query(left,2*node,L,m,i,m);
		query(right,2*node+1,m+1,R,m+1,j);
		answer.maxv=max3(left.maxv,right.maxv,left.rightsum+right.leftsum);
		answer.sum=left.sum+right.sum;
//		res.lval = max2(Left.lval, Left.sum + Right.lval);
//		res.rval = max2(Left.rval + Right.sum, Right.rval);
		answer.leftsum = max2(left.leftsum,left.sum + right.leftsum);
		answer.rightsum = max2(right.rightsum,left.rightsum + right.sum);
	}
}
int main()
{
	long long int n,i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	initialize(1,0,n-1);
//	for(i=0;i<n;i++)
//	{
//		printf("s[%d] max=%d sum=%d left=%d right=%d \n",i,s[i].maxv,s[i].sum,s[i].leftsum,s[i].rightsum);
//	}
	tree answer;
	long long int m,k,j;
	scanf("%lld",&m);
	for(k=0;k<m;k++)
	{
		scanf("%lld%lld",&i,&j);
		query(answer,1,0,n-1,--i,--j);
		printf("%lld\n",answer.maxv);
	}
	return 0;
}
