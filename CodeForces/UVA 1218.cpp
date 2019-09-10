//https://github.com/Triplem5ds/Competitve-Programming/blob/master/UVA/UVA%201218.cc
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
const int N=10007,M=1000000;
const double EPS= 1e-9;

int n,mem[N][3];
vector<int>a[N];
int dp(int u=1,int c=2,int p=-1)
{
    int&ret=mem[u][c];
    if(~ret)return ret;
    ret=1e5;
    if(c==0)
    {
        ret=1;
        for(auto v:a[u])
        {
            if(v==p)continue;
            ret+=dp(v,2,u);
        }
    }
    if(c==1||p==-1)
    {
        for(auto v:a[u])
        {
            if(v==p)continue;
            int k=dp(v,0,u);
            for(auto e:a[u])
            {
                if(e==v||e==p)continue;
                k+=dp(e,1,u);
            }
            ret=min(ret,k);
        }
    }
    if(c==2)
    {
        int k=1,t=0;
        for(auto v:a[u])
        {
            if(v==p)continue;
            k+=dp(v,2,u);
            t+=dp(v,1,u);
        }
        if(p!=-1)ret=min(t,k);
        else ret=min(ret,k);
    }
    return ret;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
while(1)
{
    cin>>n;
    int u,v;
    forr(i,1,n)a[i].clear();
    forr(i,1,n-1)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(mem,-1,sizeof mem);
    int ans=dp();
    cout<<ans<<endl;
    int x;
    cin>>x;
    if(x==-1)break;
}


return 0;
}
