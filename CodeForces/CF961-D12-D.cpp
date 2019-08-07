//https://codeforces.com/blog/entry/58743
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
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

const int N=100006,M=1000000;
const double EPS= 1e-9;
ll n,a[N],b[N];

bool get(int n1,int n2)
{
    ll c1=b[n2]-b[n1];
    ll c2=a[n1]-a[n2];
    ll c3=-a[n1]*b[n2]+a[n2]*b[n1];
    vector<int>v;
    forr(i,1,n)
        if(a[i]*c1+b[i]*c2+c3)v.push_back(i);
    if(v.size()>2)
    {
        n1=v[0],n2=v[1];
        c1=b[n2]-b[n1];
        c2=a[n1]-a[n2];
        c3=-a[n1]*b[n2]+a[n2]*b[n1];
        for(auto i:v)
          if(a[i]*c1+b[i]*c2+c3)return 0;
        return 1;
    }
    else return 1;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n;
forr(i,1,n)cin>>a[i]>>b[i];

if(n<=4)cout<<"YES";
else if(get(1,2)||get(1,3)||get(2,3))cout<<"YES";
else cout<<"NO";


return 0;
}
