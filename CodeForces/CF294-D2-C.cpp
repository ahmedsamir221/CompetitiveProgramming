//https://codeforces.com/blog/entry/7287
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
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

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100006,M=1000000;
const double EPS= 1e-9;
int MAXN = 1010;
ll n,m,a[1020],p[1020];
ll mod = 1000000007;
ll comb[1020][1020] ;
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

comb[0][0] = 1;
for (int i = 1; i < MAXN; i++) {
comb[i][0] = 1;
for (int j = 1; j <= i; j++) {
    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
    }
}
p[0]=1;
forr(i,1,1000)
{
    p[i]=p[i-1]*2;
    p[i]%=mod;
}
cin>>n>>m;
forr(i,1,m)cin>>a[i];
sort(a+1,a+1+m);
a[m+1]=n+1;

ll ans=1;
int c=a[1]-1;
forr(i,1,m)
{
    int g=a[i+1]-a[i]-1;
    c+=g;
   // cout<<g<<" "<<c<<endl;
    if(g>0)
    {
     ans*=comb[c][g];
     ans%=mod;
     if(i<m){
     ans*=p[g-1];
     ans%=mod;}
    }
}

cout<<(ans+mod)%mod;
return 0;
}
