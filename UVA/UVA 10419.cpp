/*
  we can use simple dp , our state will be the primes number , number of primes we used until now and
  the sum .
  if we found an answer , will return our answer and no need to recurse in the remaining
  paths to avoid time limit .

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
const int N=2000006,M=1000000;
const double EPS= 1e-9;

int n,t,m,p[N],mem[64][15][1004],cas;
vector<pair<string,int>>v;
int dp(int i=0,int c=0,int sum=0)
{
    if(c==t)
    {
        if(sum==n)return 1;
        return 0;
    }
    if(i==m)return 0;
    int&ret=mem[i][c][sum];
    if(~ret)return ret;
    ret=0;
    if(v[i].S==2)
    {
       if(sum+v[i].S<=n) ret=max(ret,dp(i+1,c+1,sum+v[i].S));
    }
    else
    {
       if(sum+v[i].S*2<=n&&c+2<=t) ret=max(ret,dp(i+1,c+2,sum+v[i].S*2));
       if(ret==0&&sum+v[i].S<=n) ret=max(ret,dp(i+1,c+1,sum+v[i].S));
    }

    if(ret==0)ret=max(ret,dp(i+1,c,sum));
    return ret;
}


void bulid(int i=0,int c=0,int sum=0,int cnt=0)
{
    if(c==t)return ;
    if(i==m)return ;

    int ck=1;
        if(v[i].S==2)
        {

              if(sum+v[i].S<=n&&dp(i,c,sum)==dp(i+1,c+1,sum+v[i].S))
              {
                  if(c<t-1)cout<<v[i].S<<"+";
                  else cout<<v[i].S<<endl;
                  bulid(i+1,c+1,sum+v[i].S);
                  ck=0;
              }
        }
        else
        {
              if(sum+v[i].S*2<=n&&c+2<=t&&dp(i,c,sum)==dp(i+1,c+2,sum+v[i].S*2))
              {
                  if(c<t-2)cout<<v[i].S<<"+"<<v[i].S<<"+";
                  else cout<<v[i].S<<"+"<<v[i].S<<endl;
                  bulid(i+1,c+2,sum+v[i].S*2);
                  ck=0;
              }
              else if(sum+v[i].S<=n&&dp(i,c,sum)==dp(i+1,c+1,sum+v[i].S))
              {
                  if(c<t-1)cout<<v[i].S<<"+";
                  else cout<<v[i].S<<endl;
                  bulid(i+1,c+1,sum+v[i].S);
                  ck=0;
              }
        }
    if(ck)
    {
        bulid(i+1,c,sum,0);
    }
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

for(int i=2;i<=300;i++)
{
    if(!p[i]){
       for(int j=i;j<=300;j+=i)p[j]=i;
    }
}
ll s=0;
forr(i,2,300)
{

    if(i==p[i])
    {
        string g;
        int f=i;
        while(f)
        {
            g.push_back((char)((f%10)-'0'));
            f/=10;
        }
        reverse(g.begin(),g.end());
        v.push_back({g,i});
    }
}
sort(v.begin(),v.end());
m=v.size();
while(cin>>n>>t,n||t)
{
    forr(i,0,63)forr(j,0,t)forr(u,0,n)mem[i][j][u]=-1;
    cout<<"CASE "<<++cas<<":"<<endl;
    if(!dp())
    {
        cout<<"No Solution."<<endl;
    }
    else
    {
        bulid();
    }
}
return 0;
}
