//https://codeforces.com/blog/entry/23196
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

int n,b,k,x,a[50009];
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
input
        cin>>n>>b>>k>>x;
        matrix tr(x,row(x,0));
        forr(i,1,n)cin>>a[i];

        for(int i=0;i<x;i++)
        {
            forr(j,1,n)
            {
                int num=i*10+a[j];
                num%=x;
                tr[i][num]++;
            }
        }
        tr=matPow(tr,b,1e9+7);
        cout<<tr[0][k];

return 0;
}
