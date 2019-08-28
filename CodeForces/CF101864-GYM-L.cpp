/*
   the starting of our answer must be one of start or end point of the n segments .
   so we will try all of them as starting point to our answer and minimize the answer .
   so for every point we need to know the number of segments that start before it and intersect with it
   and the remaining p people will come after it .
   we can do that using segment tree and binary search .
*/
#include<bits/stdc++.h>
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

int n,r,v;
pair<int,int>a[N];
vector<int>val[N*20];

void build(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        val[p].clear();
        val[p].push_back(a[s].S);
        return ;
    }
    int mid=(s+e)/2;
    build(s,mid,p*2);
    build(mid+1,e,p*2+1);
    val[p].clear();
    val[p].resize(val[p*2].size()+val[p*2+1].size());
    merge(val[p*2].begin(),val[p*2].end(),val[p*2+1].begin(),val[p*2+1].end(),val[p].begin());
}
int get(int s=1,int e=n,int p=1)
{
    if(e<=r)
    {
        auto it=lower_bound(val[p].begin(),val[p].end(),v);
        return (int)(val[p].end()-it);
    }
    int mid=(s+e)/2;
    if(r<=mid)return get(s,mid,p*2);
    else return get(s,mid,p*2)+get(mid+1,e,p*2+1);
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

int t,k,cas=0;
cin>>t;
while(t--)
{
    cin>>n>>k;
    forr(i,1,n)cin>>a[i].F>>a[i].S;
    sort(a+1,a+1+n);
    vector<int>tx;
    forr(i,1,n)tx.push_back(a[i].F);
    build();
    int ans=2e9;
    forr(i,1,n)
    {
        r=i;
        v=a[i].F;
        int g=get();
        if(i+k-g<=n)ans=min(ans,a[i+k-g].F-a[i].F);

        auto it=upper_bound(tx.begin(),tx.end(),a[i].S);
        int j=it-tx.begin()+1;
        r=j-1;
        if(j<=n){
        v=a[i].S;
        g=get();
        if(j+k-g-1<=n)ans=min(ans,a[j+k-g-1].F-a[i].S);
        }
    }
    cout<<"Case "<<++cas<<": "<<max(ans,0)<<endl;
}
return 0;
}
