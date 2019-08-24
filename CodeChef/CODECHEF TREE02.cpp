/*
   we will binary search the answer , each time will start from the leafs and get the sum of each subtree .
   if the sum  > our binary search value , we will sort the children values in increasing order  and  add there
   values until the sum > the binary search value then will cut the all remaining edges .
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


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100000,M=1000000;
const double EPS= 1e-9;
int n,k,vis[N],val[N],id,ans;
ll dis[N];
vector<int>a[N];

void get(int u,ll mx)
{
    vis[u]=id;
    vector<ll>t;
    for(auto v:a[u])
    {
        if(vis[v]!=id)
        {
            get(v,mx);
            t.push_back(dis[v]);
        }
    }
    sort(t.begin(),t.end());
    dis[u]=val[u];
    for(int i=0;i<(int)t.size();i++)
    {
        if(dis[u]+t[i]<=mx)dis[u]+=t[i];
        else{
            ans+=(int)t.size()-i;
            break;
        }
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n>>k;
ll l=0,r=1e15,mid;
forr(i,1,n)cin>>val[i],l=max(l,(ll)val[i]);
int u,v;
forr(i,1,n-1)
{
    cin>>u>>v;
    a[u].push_back(v);
    a[v].push_back(u);

}
while(l<r)
{
    mid=(l+r)/2;
    memset(dis,0,(n+5)*sizeof dis[0]);
    id++;
    ans=0;
    get(1,mid);
    if(ans<k)r=mid;
    else l=mid+1;
}
cout<<l<<endl;

return 0;
}
