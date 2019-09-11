//https://codeforces.com/blog/entry/43551
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


const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=500007,M=1000000;
const double EPS= 1e-9;

int n,m;
char str[N];
pair<char,ll>pat[N];
int F[M];

int getNextLen(int len, pair<char,ll> c){
  while(len && pat[len] != c )
    len = F[len-1];
  if(len==0)
  {
      if(pat[len].F == c.F ) ++len;
  }
  else
  {
      if(pat[len] == c ) ++len;
  }
  return len;
}

void computeF(){
  F[0] = 0;
  for(int i = 1 ; i < n ; ++i)
    F[i] = getNextLen(F[i-1], pat[i]);
}

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>n>>m;
int j=0;
vector<pair<char,ll>>a,b;
char c,h;
int t;
forr(i,1,n)
{
    cin>>t>>h>>c;
    if(a.size()&&c==a[a.size()-1].F)a[a.size()-1].S+=t;
    else a.push_back({c,t});
}

forr(i,1,m)
{
    cin>>t>>h>>c;
    if(b.size()&&c==b[b.size()-1].F)b[b.size()-1].S+=t;
    else b.push_back({c,t});
}

for(int i=0;i<b.size();i++)
{
    pat[j++]=b[i];
}


pat[j++]={'&',1e9};


for(int i=0;i<a.size();i++)
{
    pat[j++]=a[i];
}
n=j;
m=b.size();


if(m==1)
{
    ll ans=0;
    forr(i,0,(int)a.size()-1)
    {
        if(a[i].F==b[0].F&&a[i].S>=b[0].S)ans+=(ll)a[i].S-(ll)b[0].S+1;

    }
    cout<<ans;
    return 0;
}
computeF();

//cout<<n<<" "<<m<<endl;
ll ans=0;
for(int i=m+1;i<n;i++)
{
    //cout<<F[i]<<" ";
    if(F[i-1]==m-1&&pat[i].F==pat[m-1].F)
    {
        int id1=i-m-1;
        int id2=i-2*m;
        //cout<<id1<<" "<<id2<<endl;
        if(a[id1].S>=b[m-1].S&&a[id2].S>=b[0].S)ans++;
    }
}
cout<<ans<<endl;
return 0;
}
