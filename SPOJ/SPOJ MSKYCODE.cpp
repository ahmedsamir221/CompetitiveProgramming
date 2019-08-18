//https://github.com/aboodJAD/CompetitiveProgramming/blob/master/SPOJ/MSKYCODE-%20Sky%20Code.cpp
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
int n,c[10020];
ll com[10020],tot[10020];
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
com[4]=1;
forr(i,5,10004)
    com[i]=com[i-1]*(ll)i/(i-4);

while(cin>>n)
{
    int x,mx=0;
    memset(c,0,sizeof c);
    memset(tot,0,sizeof tot);
    forr(i,1,n)
    {
        cin>>x;
        c[x]++;
        mx=max(mx,x);
    }
    ll ans=com[n];
    for(int i=mx;i>1;i--)
    {
        int k=0;
        for(int j=i;j<=mx;j+=i)k+=c[j];
        tot[i]+=com[k];
        ans-=tot[i];
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                tot[j]-=tot[i];
                if(j*j!=i)tot[i/j]-=tot[i];
            }
        }
    }
    cout<<ans<<endl;
}
return 0;
}
