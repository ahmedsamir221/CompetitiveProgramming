/*
    we will use normal dp , our state will be the number of Coupons we get till now .
    let i number of Coupons we get , p (the probability to get old Coupon) = i / n  and
    1 - p (the probability to get new Coupon)
    our recurrence equation will be
                        ex[i]=(p+(1-p)*(1+ex[i+1]))/(1-p)
*/
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
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//char rv[4]={'D','R','L','U'};
const double EPS = 1e-9;
const int N = 5e5 + 9;
pii mul(pii x , pii y)
{
    pii z = {x.F*y.F,x.S*y.S};
    ll g=__gcd(z.F,z.S);
    z.F/=g;
    z.S/=g;
    return z;
}

pii div(pii x , pii y)
{
    swap(y.F,y.S);
    return mul(x,y);
}

pii add(pii x , pii y)
{
    pii z = {x.F*y.S+y.F*x.S,x.S*y.S};
    ll g=__gcd(z.F,z.S);
    z.F/=g;
    z.S/=g;
    return z;
}
pii sub(pii x , pii y)
{
    pii z = {x.F*y.S-y.F*x.S,x.S*y.S};
    ll g=__gcd(z.F,z.S);
    z.F/=g;
    z.S/=g;
    return z;
}


int n;
pii mem[50];
pii dp(int i)
{
    if(i==n)return {0,1};
    pii&ret=mem[i];
    if(ret.F != -1)return ret;
    pii p = {i,n};
    ret= add(p,mul({n-i,n},add({1,1},dp(i+1))));
    ret= div(ret,{n-i,n});
    //ret = p + (1.0-p) * (1.0 + dp(i+1));
    //ret/=1.0-p;
    return ret;
}

int getsz(ll x)
{
    int c=0;
    while(x)c++,x/=10;
    return c;
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
   while(cin>>n){
        memset(mem,-1,sizeof mem);
        pii ans= dp(0);
        if(ans.S==1)cout<<ans.F<<endl;
        else{
            ll q = ans.F/ans.S;
            ll r = ans.F%ans.S;
            int a=getsz(q);
            int b=getsz(r);
            int c=getsz(ans.S);
            for(int i=0;i<a+1;i++)cout<<" ";cout<<r<<endl;
            cout<<q<<" ";for(int i=0;i<max(b,c);i++)cout<<"-";cout<<endl;
            for(int i=0;i<a+1;i++)cout<<" ";cout<<ans.S<<endl;

        }
   }


return 0;
}
