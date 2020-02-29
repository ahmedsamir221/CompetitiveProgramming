//https://codeforces.com/contest/501/problem/D
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

int n,tree[N],x,c[N];
void up(int idx,int v)
{
    for(;idx<=n;idx+=idx&-idx)tree[idx]+=v;
}
int get(int idx)
{
    if(idx==0)return 0;
    int res=0;
    for(;idx;idx-=idx&-idx)res+=tree[idx];
    return res;
}

 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n;
        forr(i,1,n)
        {
            cin>>x;
            x++;
            c[i]=x-get(x)-1;
            up(x,1);
        }
        memset(tree,0,sizeof tree);
        forr(i,1,n)
        {
            cin>>x;
            x++;
            c[i]+=x-get(x)-1;
            up(x,1);
        }
        reverse(c+1,c+1+n);
        vector<int>ans;
        forr(i,1,n)
        {
            if(c[i]>=i)c[i+1]++;
            c[i]%=i;
        }
        reverse(c+1,c+1+n);
        memset(tree,0,sizeof tree);
        forr(i,1,n)up(i,1);

        forr(i,1,n)
        {
            int k=c[i]+1;
            int l=1,r=n,mid;
            while(l<r)
            {
                mid=(l+r)/2;
                if(get(mid)<k)l=mid+1;
                else r=mid;
            }
            cout<<l-1<<" ";
            up(l,-1);
        }

return 0;
}
