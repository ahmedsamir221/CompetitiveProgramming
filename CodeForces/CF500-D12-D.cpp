//https://codeforces.com/blog/entry/15488
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
ll n,vis[N],val[N],cnt[N],from[N],to[N];
double sum,dis[N];
double nc3[N];
vector<pii>a[N];

ll get(int u)
{
    vis[u]=1;
    vector<pair<ll,double>>t;
    for(auto v:a[u])
    {
        if(!vis[v.F])
        {
            get(v.F);
            dis[u]+=dis[v.F]+(double)(cnt[v.F]*v.S);
            cnt[u]+=cnt[v.F];
            t.push_back({cnt[v.F],dis[v.F]+(double)(cnt[v.F]*v.S)});
        }
    }
    sum+=dis[u];
    cnt[u]++;
    double g=0;
    ll c=0;
    if(t.size()>1){
    for(int i=0;i<(int)t.size();i++)
    {
        if(i) sum+=(t[i].S*c+g*t[i].F);
        g+=t[i].S;
        c+=t[i].F;
    }}
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>n;

nc3[3]=1;
forr(i,4,n)nc3[i]=nc3[i-1]*(double)i/(double)(i-3);

int u,v,w;
forr(i,1,n-1)
{
    cin>>u>>v>>w;
    from[i]=u,to[i]=v,val[i]=w;
    a[u].push_back({v,w});
    a[v].push_back({u,w});
}
get(1);
int q,idx;
cin>>q;
while(q--)
{
    cin>>idx>>v;
    int f=from[idx];
    int t=to[idx];
    if(cnt[f] < cnt[t])sum-=(double)(val[idx]-v)*cnt[f]*(n-cnt[f]);
    else sum-=(double)(val[idx]-v)*cnt[t]*(n-cnt[t]);
    val[idx]=v;
    cout<<fixed<<setprecision(10)<<sum*(n-2)/nc3[n]<<endl;
}
return 0;
}
