//https://codeforces.com/blog/entry/13430
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

const int N=50000,M=1000000;
const double EPS= 1e-9;


int n,k,d,a[1005][1005];
void get(int l,int s,int e)
{
    if(l>d)return ;
    int g=(e-s+k)/k;
    for(int i=s,t=1;i<=e;i+=g,t++)
    {
        for(int j=i;j<min(i+g,n+1);j++)a[l][j]=t;
        get(l+1,i,min(i+g-1,n));
    }
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n>>k>>d;

int g=n,m=d;
while(m--)
{
    g=(g+k-1)/k;
}
if(g>1)
{
    cout<<"-1";
    return 0;
}
get(1,1,n);

forr(i,1,d)
{
    forr(j,1,n)cout<<a[i][j]<<" ";
    cout<<endl;
}
return 0;
}
