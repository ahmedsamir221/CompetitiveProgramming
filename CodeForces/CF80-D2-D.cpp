//https://codeforces.com/blog/entry/1773
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
const int N=16,M=1000000;
const double EPS= 1e-9;

ll t,a,b;
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>t;
while(t--)
{
    cin>>a>>b;
    double ans;
    if(b==0)ans=1;
    else if(a==0)ans=0.5;
    else{
    ans=a*b;
    if(a<=4*b) ans+=0.5*a*a/4;
    else ans+=a*b-0.5*b*b*4;
    ans/=a*2*b;
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
return 0;
}
