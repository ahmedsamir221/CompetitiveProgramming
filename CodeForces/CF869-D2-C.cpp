//https://codeforces.com/blog/entry/55009
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
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;

ll a,b,c,mem[5005][5005],mod=998244353;
ll dp(int n,int m)
{
    if(n==0||m==0)return 1;
    ll&ret=mem[n][m];
    if(~ret)return ret;
    ret=0;
    ret+=(dp(n-1,m-1)*m)%mod;
    ret+=dp(n-1,m);
    return ret%mod;
}


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>a>>b>>c;
memset(mem,-1,sizeof mem);

cout<<((dp(a,b)%mod * dp(a,c)%mod )%mod * dp(b,c)%mod)%mod;


return 0;
}
