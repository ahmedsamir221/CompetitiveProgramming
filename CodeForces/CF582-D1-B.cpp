//https://codeforces.com/blog/entry/20692
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
const int N = 5e2 + 9;
int n,t,mem[309][109][109],a[109];
int dp(int p,int i,int e)
{
    if(i==e)
    {
        if(a[i]>=p)return 1;
        else return -1e5;
    }
    int&ret=mem[p][i][e];
    if(~ret)return ret;
    ret=dp(p,i+1,e);
    if(a[i]>=p)ret=max(ret,dp(a[i],i+1,e)+1);
    return ret;
}

#define row         vector<long long>
#define matrix      vector<row>
#define ROWS(v)     (v).size()
#define COLS(v)     (v)[0].size()

matrix mul(const matrix& a, const matrix& b, ll mod){
    matrix c(ROWS(a), row(COLS(b), 0));
    forr(i,0, ROWS(a)-1) forr(j,0, COLS(b)-1){
        c[i][j]=-100000;
    forr(k,0, COLS(a)-1){
        c[i][j] = max(c[i][j],a[i][k] + b[k][j]) ;
    }}
    return c;
}

matrix matPow(const matrix& a, ll po, ll mod){
    matrix ret(ROWS(a),row(COLS(a),0));
    matrix m = a;
    while(po){
        if(po & 1) ret = mul(ret, m, mod);
        m = mul(m, m, mod);
        po >>= 1;
    }
    return ret;
}

 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n>>t;
        forr(i,1,n)cin>>a[i];
        memset(mem,-1,sizeof mem);
        matrix m(n,row(n,0));
        forr(i,1,n)
            forr(j,1,n)
                m[i-1][j-1]=max(-100000,dp(a[i],1,j));

        matrix ans=matPow(m,t,1e18);
        ll mx=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mx=max(mx,ans[i][j]);
        cout<<mx;

return 0;
}
