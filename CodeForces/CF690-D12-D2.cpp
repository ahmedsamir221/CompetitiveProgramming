//http://assets.codeforces.com/files/690/hc2-2016-editorial.pdf
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
const int N=16,M=1000000;
const double EPS= 1e-9;
ll f[800010],mm=1e6+3,n,c;
ll fPower(ll b, ll p, ll m){    //O(log(p))
  ll res = 1;
  while(p){
    if(p&1) res = (res * b)%m;
    b = (b * b)%m;
    p >>= 1;
  }
  return res;
}

inline ll modInversePrime(ll a, ll p){     //O(log(p))
  return fPower(a, p-2, p);
}
ll nCr(int n,int r)
{
    return ((f[n]*modInversePrime(f[r],mm))%mm*modInversePrime(f[n-r],mm)+mm)%mm;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
f[0]=1;
forr(i,1,800000)
f[i]=(f[i-1]*i)%mm;


cin>>n>>c;
ll ans=nCr(n+c,c)-1;
ans=(ans+mm+mm)%mm;
cout<<ans;

return 0;
}
