//https://codeforces.com/blog/entry/45770
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
const int N=2000006,M=1000000;
const double EPS= 1e-9;

int n,k,a[N],p[N],f[N],c[N],id;


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>n>>k;
forr(i,1,n)cin>>a[i];

for(int i=2;i<=1000000;i++)
{
    if(!p[i]){
       for(int j=i;j<=1000000;j+=i)p[j]=i;
    }
}

forr(i,1,n)
{
    int g=a[i];
    vector<int>v;
    while(g>1)
    {
        c[p[g]]++;
        v.push_back(p[g]);
        g/=p[g];
    }
    for(auto p:v)
    {
        if(c[p])f[p]+=max(0,c[p]-f[p]),c[p]=0;
    }
}

for(int i=2;i*i<=k;i++)
{
    while(k%i==0)
    {
        f[i]--;
        k/=i;
        if(f[i]<0)
        {
            cout<<"No";
            return 0;
        }
    }
}
if(k>1&&!f[k])cout<<"No";
else cout<<"Yes";
return 0;
}
