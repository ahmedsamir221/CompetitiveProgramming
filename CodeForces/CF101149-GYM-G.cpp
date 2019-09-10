/*
   we will sort the n pairs and the m pairs in increasing order then start from the end and try to match
   i-th pair with one that has weight >= his weight and curvature >= his curvature but with min curvature .
   in any moment we can not match there will be now answer .
   we can do that with efficiency by using multi_set

*/
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
const int N=200007,M=1000000;
const double EPS= 1e-9;

int n,m,l,r,v,ans[N],idx;
pair<pair<int,int>,int>a[N],b[N];

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n;
forr(i,1,n)cin>>a[i].F.F>>a[i].F.S,a[i].S=i;
sort(a+1,a+1+n);
cin>>m;
forr(i,1,m)cin>>b[i].F.F>>b[i].F.S,b[i].S=i;
sort(b+1,b+1+m);



multiset<int>k;
map<int,vector<int>>id;
int j=m;
for(int i=n;i>=1;i--)
{
  while(j&&b[j].F.F>=a[i].F.F)
  {
      k.insert(b[j].F.S);
      id[b[j].F.S].push_back(b[j--].S);
  }
  auto it = k.lower_bound(a[i].F.S);
  if(it==k.end())
  {
      cout<<"-1";
      return 0;
  }
  int g=id[*it][id[*it].size()-1];
  id[*it].pop_back();
  k.erase(it);
  ans[a[i].S]=g;
}
forr(i,1,n)cout<<ans[i]<<" ";

return 0;
}
