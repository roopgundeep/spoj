#include<iostream>
int a[105][105],i,j,t,n;using namespace std;
int main()
{cin>>t;while(t--){cin>>n;for(i=1;i<=n;i++)for(j=1;j<=i;j++){cin>>a[i][j];a[i][j]=max(a[i-1][j-1],a[i-1][j])+a[i][j];}j=0;for(i=1;i<=n;i++)j=max(j,a[n][i]);cout<<j<<endl;}}


