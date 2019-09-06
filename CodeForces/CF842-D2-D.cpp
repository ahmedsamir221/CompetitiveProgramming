//https://codeforces.com/blog/entry/54179
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
const int N=800007,M=1000000;
const double EPS= 1e-9;

int n,m,a[N];
int b[N][2],e,nxt[N][2],val[N],lef[N];

void add(vector<int> &v,int i,int cur)
{
    if(i==20)
    {
        lef[cur]=1;
        return ;
    }
    if(v[i]==0)
    {
        if(b[cur][0]==-1)
        {
            b[cur][0]=0;
            nxt[cur][0]=++e;
            val[e]=0;
        }
        add(v,i+1,nxt[cur][0]);
    }
    else
    {
        if(b[cur][1]==-1)
        {
            b[cur][1]=1;
            nxt[cur][1]=++e;
            val[e]=1;
        }
        add(v,i+1,nxt[cur][1]);
    }

     lef[cur]=((b[cur][0]!=-1)?lef[nxt[cur][0]]:0)+((b[cur][1]!=-1)?lef[nxt[cur][1]]:0);
    // cout<<cur<<" "<<((b[cur][0]!=-1)?lef[nxt[cur][0]]:0)<<" "<<((b[cur][1]!=-1)?lef[nxt[cur][1]]:0)<<endl;

}

void get(vector<int> &v,int i,int cur,int &ans)
{
    if(i==20)return ;
  //  cout<<b[cur][0]<<" "<<b[cur][1]<<" "<<cur<<" "<<((b[cur][0]!=-1)?lef[nxt[cur][0]]:0)<<" "<<((b[cur][1]!=-1)?lef[nxt[cur][1]]:0)<<endl;

    if(v[i]==0)
    {
        if(b[cur][0]==-1)forr(j,i,19)ans*=2;
        else if(lef[nxt[cur][0]]<(1<<(19-i)))get(v,i+1,nxt[cur][0],ans=ans*2);
        else
        {
            if(b[cur][1]==-1){ans=ans*2+1; forr(j,i+1,19)ans*=2;}
            else get(v,i+1,nxt[cur][1],ans=ans*2+1);
        }
    }
    else
    {
      //  cout<<lef[cur]<<"  "<<(1<<(19-i))<<endl;
        if(b[cur][1]==-1)forr(j,i,19)ans*=2;
        else if(lef[nxt[cur][1]]<(1<<(19-i)))get(v,i+1,nxt[cur][1],ans=ans*2);
        else
        {
             if(b[cur][0]==-1){ans=ans*2+1; forr(j,i+1,19)ans*=2;}
             else get(v,i+1,nxt[cur][0],ans=ans*2+1);
        }
    }

}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n>>m;
memset(b,-1,sizeof b);
forr(i,1,n)
{
    cin>>a[i];
    vector<int>v;
    int g=a[i];
    while(g)
    {
        v.push_back(g%2);
        g/=2;
    }
    while(v.size()<20)v.push_back(0);
    reverse(v.begin(),v.end());
    add(v,0,0);
}
int c=0,x,p;
while(m--)
{
    cin>>x;
    c^=x;

    vector<int>v;
    int g=c;
    while(g)
    {
        v.push_back(g%2);
        g/=2;
    }
    while(v.size()<20)v.push_back(0);
    reverse(v.begin(),v.end());
    int ans=0;
    get(v,0,0,ans);
    cout<<min(ans,300000)<<endl;
    p=ans;
}
return 0;
}
