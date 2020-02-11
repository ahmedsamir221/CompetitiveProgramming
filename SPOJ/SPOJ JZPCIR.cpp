//https://github.com/adarshkr532/CompetitiveProgramming/blob/master/SPOJ/JZPCIR.cpp
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

lld power(lld b, lld po, lld mod){
    lld ret = 1;
    while(po){
        if(po & 1) ret = (ret * b) % mod;
        b = (b * b) % mod;
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
        ll ans[8]= {2,2,8,9,12,16,23,29};
        matrix trans(6,row(6,0));
        trans[1][0]=trans[2][1]=trans[3][2]=trans[4][3]=trans[5][4]=1;
        trans[0][5]=1,trans[1][5]=-1,trans[2][5]=0,trans[3][5]=-1,trans[4][5]=0,trans[5][5]=2;
        matrix init(6,row(6,0));
        init[0][0]=8,init[0][1]=9,init[0][2]=12,init[0][3]=16,init[0][4]=23,init[0][5]=29;
        int t;
        cin>>t;
        ll mood=1000000009;
        while(t--)
        {
            ll n;
            cin>>n;
            if(n<=8)cout<<ans[n-1]<<endl;
            else{
                matrix f=matPow(trans,n-8,1e9+9);
                matrix x=mul(init,f,1e9+9);
                cout<<(x[0][5]+1LL*mood*2)%mood<<endl;
            }
        }
return 0;
}
