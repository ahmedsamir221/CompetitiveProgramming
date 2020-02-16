//https://github.com/goswami-rahul/competitive-coding/blob/master/CompetitiveProgramming/spoj/PLHOP.cpp
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
    matrix id(n, row(n, 1e14));
    fr(i, n) id[i][i] = 0;
    return id;
}

matrix mul(const matrix& a, const matrix& b){
    matrix c(ROWS(a), row(COLS(b), 1e14));
    fr(i, ROWS(a)) fr(j, COLS(b))
    fr(k, COLS(a)){
        c[i][j] = min(c[i][j],a[i][k] + b[k][j]) ;
    }
    return c;
}

matrix matPow(const matrix& a, lld po){
    matrix ret = identity(ROWS(a));
    matrix m = a;
    while(po){
        if(po & 1) ret = mul(ret, m);
        m = mul(m, m);
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

        int t,cas=0;
        cin>>t;
        while(t--)
        {
            int n,k;
            cin>>k>>n;
            matrix adj(n,row(n,0));
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    cin>>adj[i][j];

            matrix ans=matPow(adj,k);
            forr(p,k+1,k+n)
            {
                matrix temp=matPow(adj,p);
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        ans[i][j]=min(ans[i][j],temp[i][j]);

            }


            cout<<"Region #"<<++cas<<":"<<endl;
            for(int i=0;i<n;i++){
                cout<<ans[i][0];
                for(int j=1;j<n;j++)
                    cout<<" "<<ans[i][j];
                cout<<endl;
            }
            cout<<endl;

        }


return 0;
}
