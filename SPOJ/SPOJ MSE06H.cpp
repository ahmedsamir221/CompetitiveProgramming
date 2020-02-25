//https://www.quora.com/How-do-I-solve-SPOJ-com-Problem-MSE06H-using-BIT
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

int n,m,k,tree[1009];


void up(int idx)
{
    for(;idx<=m;idx+=idx&-idx)tree[idx]++;
}

int get(int idx)
{
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
        int t,cas=0;
        cin>>t;
        while(t--)
        {
            cin>>n>>m>>k;
            forr(i,1,m)tree[i]=0;
            vector<pair<int,int>>q(k);
            for(int i=0;i<k;i++)cin>>q[i].F>>q[i].S;
            sort(q.begin(),q.end());
            ll ans=0;
            for(int i=0;i<k;i++)
            {
                ans+=get(m)-get(q[i].S);
                up(q[i].S);
            }
            printf("Test case %d: %lld\n",++cas,ans);
        }


return 0;
}
