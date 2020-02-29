//https://github.com/morris821028/UVa/blob/master/volume126/12697%20-%20Minimal%20Subarray%20Length.cpp
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

ll n,x,tree[N];
ll a[N],b[N];


void up(int idx,ll v)
{
    for(;idx<=n;idx+=idx&-idx)tree[idx]=max(tree[idx],v);
}

ll get(int idx)
{
    ll res=-2e9;
    for(;idx;idx-=idx&-idx)res=max(res,tree[idx]);
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
            cin>>n>>x;
            forr(i,1,n)cin>>a[i],b[i]=a[i],tree[i]=-2e9;

            forr(i,1,n)b[i]+=b[i-1];
            sort(b+1,b+1+n);
            int c=0;
            map<ll,int>re;
            forr(i,1,n)
                if(i==1||b[i]!=b[i-1])re[b[i]]=++c;


            ll ans=2e9;
            forr(i,1,n)
            {
                a[i]+=a[i-1];
                if(a[i]>=x)ans=min(ans,(ll)i);
                ll f=a[i]-x;
                auto it=re.upper_bound(f);
                if(it!=re.begin())
                {
                    it--;
                    auto p=*it;
                    ans=min(ans,(ll)i-get(p.S));
                }
                up(re[a[i]],i);
            }
            if(ans>=2e9)cout<<"-1"<<endl;
            else cout<<ans<<endl;
        }


return 0;
}
