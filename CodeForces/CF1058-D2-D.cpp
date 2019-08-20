//https://codeforces.com/blog/entry/62013
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
int MAXN = 1010;
ll n,m,k;
vector<int>v;
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>n>>m>>k;
if((2*n*m)%k)
{
    cout<<"NO";
    return 0;
}
int ck=1;
if(k%2==0)k/=2,ck=0;
for(int j=2;j*j<=k;j++)
{
    while(k%j==0)
    {
        v.push_back(j);
        k/=j;
    }
}
if(k>1)v.push_back(k);
for(auto p:v)
{
    if(n%p==0)
    {
        n/=p;
        if(ck)n*=2,ck=0;
    }
    else
    {
        m/=p;
        if(ck)m*=2,ck=0;
    }
}

cout<<"YES"<<endl;
cout<<"0 0"<<endl;
cout<<n<<" 0"<<endl;
cout<<n<<" "<<m<<endl;
return 0;
}
