//https://codeforces.com/blog/entry/17612
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
const int N = 2e5 + 9;

int n,m,a[N];
vector<int>val[N*20];
void bulid(int s,int e,int p)
{
    val[p].resize(e-s+1);
    if(s==e)
    {
        val[p][0]=a[s];
        return ;
    }
    int mid=(s+e)/2;
    bulid(s,mid,p*2);
    bulid(mid+1,e,p*2+1);
    merge(val[p*2].begin(),val[p*2].end(),val[p*2+1].begin(),val[p*2+1].end(),val[p].begin());
}

int get(int s,int e,int p,int l,int r,int v)
{
    if(l>r)return 0;
    if(e<l||s>r)return 0;
    if(s>=l&&e<=r)
    {
        auto it=lower_bound(val[p].begin(),val[p].end(),v);
        return (it-val[p].begin());
    }
    int mid=(s+e)/2;
    return get(s,mid,p*2,l,r,v)+get(mid+1,e,p*2+1,l,r,v);
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n;
        forr(i,1,n)cin>>a[i];
        bulid(1,n,1);

        forr(k,1,n-1)
        {
            ll p=1,pr=0,ans=0,ck=1;
            while(1)
            {
                ll s=pr+p+1;
                for(ll j=0;j<p;j++)
                {
                    ll l=s+j*k;
                    ll r=min(1LL*n,l+k-1);
                    if(l>n)
                    {
                        ck=0;
                        break;
                    }
                    ans+=get(1,n,1,l,r,a[pr+j+1]);
                }
                if(!ck)break;
                pr+=p;
                p*=k;
            }
            cout<<ans<<" ";
        }

return 0;
}
