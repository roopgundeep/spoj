#include <iostream>
#include <cstring>
using namespace std;
int val[2000010];
int mx[2000010];
int K,N;
 
void setmax(int &a, int b) {if(a<b) a=b;}
 
int build(int Node, int start, int end)
{
	if(start==end)
	{
		mx[Node]=val[start];
		return mx[Node];
	}
	int mid=(end+start)/2;
	mx[Node]=-1;
	setmax(mx[Node],build(Node*2, start, mid));
	setmax(mx[Node],build(Node*2+1, mid+1, end));
	return mx[Node];
}
 
int q(int Node, int q1, int q2, int start, int end)
{
	if(q1==start && q2==end)
		return mx[Node];
	int x=-1;
	int mid=(start+end)/2;
	if(q1>=mid+1)
		setmax(x,q(2*Node+1, q1, q2, mid+1, end));
	else if(q2<=mid)
		setmax(x,q(2*Node, q1, q2, start, mid));
	else
	{
		setmax(x,q(2*Node, q1, mid, start, mid));
		setmax(x,q(2*Node+1, mid+1, q2, mid+1, end));
	}
	return x;
}
 
int main()
{
	cin >> N;
	for(int i=0;i<N;i++) cin >> val[i];
	cin >> K;
	build(1, 0, N-1);
	cout<<q(1,0,K-1,0,N-1);
	for(int i=K; i<N;i++)
		cout<<' '<<q(1,i-K+1,i,0,N-1);
	cout<<endl;
	return 0;
}
