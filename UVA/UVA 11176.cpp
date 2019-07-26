//http://lbv-pc.blogspot.com/2012/06/winning-streak.html
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

int n;
double p,po[505],dp[505][505];


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

while(cin>>n>>p,n)
{
    po[0]=1;
    forr(i,1,n)po[i]=po[i-1]*p;

    forr(i,0,n)dp[0][i]=1.0;

    forr(i,1,n)
    {
        forr(j,0,n)
        {
            dp[i][j]=dp[i-1][j];
            if(j==i-1)dp[i][j]-=po[i];
            if(j<i-1)dp[i][j]-=dp[i-j-2][j]*(1-p)*po[j+1];
        }
    }

    double ans=0;
    forr(i,1,n)ans+=i*(dp[n][i]-dp[n][i-1]);

    cout<<fixed<<setprecision(12)<<ans<<endl;

}




return 0;
}
