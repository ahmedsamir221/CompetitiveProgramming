//http://codeforces.com/blog/entry/695
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

//const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
//typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 1e3 + 9;
int n;
pair<pair<int,double>,pair<int,int>>a[N];
double dp[N];

bool can(int i,int j)
{
    ll x = a[i].S.F - a[j].S.F ;x*=x;
    ll y = a[i].S.S - a[j].S.S ;y*=y;
    ll d = x+y;
    ll f = a[j].F.F-a[i].F.F;
    if(d <= f * f)return 1;
    return 0;
}

double get()
{
    forr(i,1,n)
        forr(j,0,i-1)
            if(j==0||can(i,j))dp[i]=max(dp[i],a[i].F.S + dp[j]);

    double ans=0;
    forr(i,1,n)ans=max(ans,dp[i]);
    return ans;
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n;
        forr(i,1,n)
            cin>>a[i].S.F>>a[i].S.S>>a[i].F.F>>a[i].F.S;
        sort(a+1,a+1+n);
        cout<<fixed<<setprecision(6)<<get()<<endl;

return 0;
}
