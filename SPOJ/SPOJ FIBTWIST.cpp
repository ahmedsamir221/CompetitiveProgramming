/*
    initial matrix will be  1    1    0    1
                            0    0    0    0
                            0    0    0    0
                            0    0    0    0
 transition matrix will be
                            1   1   0   0
                            1   1   0   1
                            0   0   0   1
                            0   0   1   1
*/
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
int x[8]={1,0,0,-1,-1,-1,1,1};
int y[8]={0,1,-1,0,-1,1,-1,1};
const double EPS = 1e-9;
const int N = 5e5 + 9;
ll n,k,b[12],c[12];


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
        int t;
        cin>>t;
        matrix init(4,row(4,0));
        init[0][0]=init[0][1]=init[0][3]=1;

        matrix trans(4,row(4,0));
        trans[0][0]=trans[0][1]=trans[1][1]=trans[1][3]=trans[2][3]=trans[3][2]=trans[3][3]=1;


        while(t--)
        {
            ll n,m;
            cin>>n>>m;
            if(n==0||n==1)cout<<n<<endl;
            else {
            matrix ans=mul(init,matPow(trans,n-1,m),m);
            cout<<ans[0][3]<<endl;
            }

        }

return 0;
}
