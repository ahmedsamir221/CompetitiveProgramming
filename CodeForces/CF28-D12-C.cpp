//https://codeforces.com/blog/entry/685
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;
int n,m,x,a[55];
double mem[55][55][55];
ll comb[55][55] ;

double dp(int num=n,int i=1,int mx=0)
{
    if(num==0)return mx*pow(1.0/m,n);
    if(i>m)return 0;
    double &ret=mem[num][i][mx];
    if(ret==ret)return ret;
    ret=0;
    for(int j=0;j<=num;j++)
        ret+=dp(num-j,i+1,max(mx,(j+a[i]-1)/a[i]))*comb[num][j];

    return ret;
}


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
comb[0][0] = 1;
for (int i = 1; i < 51; i++) {
comb[i][0] = 1;
for (int j = 1; j <= i; j++) {
    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) ;
    }
}
cin>>n>>m;
forr(i,1,m) cin>>a[i];
memset(mem,-1,sizeof mem);
cout<<fixed<<setprecision(9)<<dp()<<endl;

return 0;
}
