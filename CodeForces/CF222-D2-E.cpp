//https://codeforces.com/blog/entry/5251
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
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


#define row         vector<long long>
#define matrix      vector<row>
#define ROWS(v)     (v).size()
#define COLS(v)     (v)[0].size()



matrix identity(int n){
    matrix id(n, row(n, 0));
    for(int i=0;i<n;i++) id[i][i] = 1;
    return id;
}

matrix mul(const matrix& a, const matrix& b, ll mod){
    matrix c(ROWS(a), row(COLS(b), 0));
    for(int i=0;i< ROWS(a);i++) for(int j=0;j< COLS(b);j++)
    for(int k=0;k< COLS(a);k++){
        c[i][j] += (a[i][k] * b[k][j]) % mod;
        c[i][j] %= mod;
    }
    return c;
}

matrix matPow(const matrix& a, ll po, ll mod){
    matrix ret = identity(ROWS(a));
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
        ll n,m,k;
        cin>>n>>m>>k;
        matrix init(m,row(m,1));
        char x,y;
        forr(i,1,k)
        {
            cin>>x>>y;
            int r,c;
            if(x>='a')r=x-'a';
            else r=x-'A'+26;
            if(y>='a')c=y-'a';
            else c=y-'A'+26;
            init[r][c]=0;
        }
        matrix ans=matPow(init,n-1,1e9+7);
        ll res=0,mod=1e9+7;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                res+=ans[i][j],res%=mod;
        cout<<res;



return 0;
}
