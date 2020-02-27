//https://github.com/MeGaCrazy/CompetitiveProgramming/blob/c86a8f9935be057efbf0aa87b464b0740bcb41a4/UVA/UVA_1428.cpp
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
const double EPS = 1e-9;
const int N = 5e5 + 9;

int n,x,mx=1e5,a[N];
ll cnt[N],sum[N];

void upcnt(int idx)
{
    for(;idx<=mx;idx+=idx&-idx)cnt[idx]++;
}
ll getcnt(int idx)
{
    ll res=0;
    for(;idx;idx-=idx&-idx)res+=cnt[idx];
    return res;
}


void upsum(int idx,ll v)
{
    for(;idx<=mx;idx+=idx&-idx)sum[idx]+=v;
}
ll getsum(int idx)
{
    ll res=0;
    for(;idx;idx-=idx&-idx)res+=sum[idx];
    return res;
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        int t;
        cin>>t;
        while(t--)
        {
            cin>>n;
            ll ans=0;
            memset(cnt,0,sizeof cnt);
            memset(sum,0,sizeof sum);
            forr(i,1,n)
            {
                cin>>a[i];
                x=a[i];
                ans+=getsum(x);
                ll f=getcnt(x);
                upsum(x,f);
                upcnt(x);
            }
            memset(cnt,0,sizeof cnt);
            memset(sum,0,sizeof sum);
            for(int i=n;i>=1;i--)
            {
                x=a[i];
                ans+=getsum(x);
                ll f=getcnt(x);
                upsum(x,f);
                upcnt(x);
            }
            cout<<ans<<endl;
        }


return 0;
}
