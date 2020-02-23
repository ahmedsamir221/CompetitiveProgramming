//https://codeforces.com/blog/entry/52895
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

#define fr(i, n)    for(int i=0; i<(int)n; ++i)
#define MOD         1000000007

#define row         vector<long long>
#define matrix      vector<row>
#define ROWS(v)     (v).size()
#define COLS(v)     (v)[0].size()

using namespace std;

typedef long long lld;

void printMat(const matrix& a){
    fr(i, ROWS(a)){
        fr(j, COLS(a)) printf("%lld ", a[i][j]);
        printf("\n");
    }
}

matrix add(const matrix& a, const matrix& b, lld mod){
    matrix c(ROWS(a), row(COLS(a), 0));
    fr(i, ROWS(a)) fr(j, COLS(a)){
        c[i][j] = a[i][j] + b[i][j];
        c[i][j] %= mod;
    }
}

matrix identity(int n){
    matrix id(n, row(n, 0));
    fr(i, n) id[i][i] = 1;
    return id;
}

matrix mul(const matrix& a, const matrix& b, lld mod){
    matrix c(ROWS(a), row(COLS(b), 0));
    fr(i, ROWS(a)) fr(j, COLS(b))
    fr(k, COLS(a)){
        c[i][j] += (a[i][k] * b[k][j]) % mod;
        c[i][j] %= mod;
    }
    return c;
}

matrix matPow(const matrix& a, lld po, lld mod){
    matrix ret = identity(ROWS(a));
    matrix m = a;
    while(po){
        if(po & 1) ret = mul(ret, m, mod);
        m = mul(m, m, mod);
        po >>= 1;
    }
    return ret;
}

matrix pre[109];
matrix get(int d,ll p)
{
    matrix x(d,row(d,0));
    for(int i=0;i<d;i++)
        x[i][max(0,i-1)]=x[i][i]=x[i][min(d-1,i+1)]=1;
    return matPow(x,p,MOD);
}

int n,c[109];
ll k,a[109],b[109],mem[109][19];

ll dp(int i=1,int h=0)
{
    if(h>c[i])return 0;
    if(i>n)
    {
        if(h==0)return 1;
        return 0;
    }
    ll&ret=mem[i][h];
    if(~ret)return ret;
    ret=0;
    forr(d,0,c[i])
    {
        ret+=((dp(i+1,d)%MOD) * (pre[i][h][d]%MOD))%MOD;
        ret%=MOD;
    }
    return ret;
}


 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n>>k;
        forr(i,1,n)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(i==n)b[i]=k;
            pre[i]=get(c[i]+1,b[i]-a[i]);
        }
        memset(mem,-1,sizeof mem);
        cout<<dp();

return 0;
}
