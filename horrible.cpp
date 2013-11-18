#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct tree
{
	int sum;
	int add;
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
		s[node].add=0;
		s[node].sum=0;
		return;
	}
	int mid=(b+e)/2;
	initialize(2*node,b,mid);
	initialize(2*node+1,mid+1,e);
	s[node].sum=s[node*2].sum+s[node*2+1].sum + s[node].add*(e-b+1);
}
void update(int node,int b,int e,int x,int y,int v)
{
	if(b==x && e==y)
	{
		s[node].add +=v;
		s[node].sum +=v*(y-x+1);
		return;
	}
//	int m = (i+j)/2;
//	if(idx<=m) update(2*Node, i, m, idx, val);
//	else update(2*Node+1, m+1, j, idx, val);///
	int m=(b+e)/2;	
	if(y<=m)
		update(2*node,b,m,x,y,v);
	else if(x>m)
		update(2*node+1,m+1,e,x,y,v);
	else
	{
		update(2*node,b,m,x,m,v);
		update(2*node+1,m+1,e,m+1,y,v);
	}
	s[node].sum=s[node*2].sum+s[node*2+1].sum + s[node].add*(e-b+1);

}
int  query(int node,int i,int j,int x,int y,int v)
{
	if(i==x && j==y)
	{
		return s[node].sum+v*(y-x+1);
	}
	int m=i+j/2;
	if(y<=m)
	{
		return query(2*node,i,m,x,y,v + s[node].add);
	}
	else if(x>m)
	{
		return query(2*node+1,m+1,j,x,y,v+s[node].add);
	}
	else
	{
		int ans=0;
		ans +=query(2*node,i,m,x,m,v+s[node].add);
		ans +=query(2*node+1,m+1,j,m+1,y,v+s[node].add);
		return ans;
	}
}
int main()
{
	int n,i,t,k,c,p,q,v,dec;
	scanf("%lld",&t);
	for(k=0;k<t;k++)
	{
		scanf("%lld%lld",&n,&c);
		initialize(1,0,n-1);
		for(i=0;i<c;i++)
		{
			scanf("%lld",&dec);
			if(dec==0)
			{
				scanf("%lld%lld%lld",&p,&q,&v);
				update(1,0,n-1,p-1,q-1,v);
			}
			else
			{
				scanf("%lld%lld",&p,&q);
				printf("%lld\n",query(1,0,n-1,p-1,q-1,0));
			}
		}
	
	}
	return 0;
}
