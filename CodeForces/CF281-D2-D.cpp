//https://assets.codeforces.com/statements/280-281/Tutorial.pdf
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
int n,a[100020];

int get()
{
    vector<int>v;
    int g=0;
    forr(i,1,n)
    {
        while(v.size()&&a[i]>v[v.size()-1])v.pop_back();
        v.push_back(a[i]);
        if(v.size()>1)g=max(g,v[v.size()-1]^v[v.size()-2]);
    }
    return g;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>n;
forr(i,1,n)cin>>a[i];

int ans=get();
reverse(a+1,a+1+n);
ans=max(ans,get());
cout<<ans;
return 0;
}
