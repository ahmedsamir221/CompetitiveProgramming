//https://codeforces.com/blog/entry/45425
/*
   we will use dp with mask , our state will be the fish we need to get it's probability and mask of live fishes .
   then if fish i will eat fish j we will add -->> a[i][j]*1/(number of remaining pairs) ;
   we can do some preprocessing to avoid the time limit
*/
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
int n,bob[1<<18];
double a[20][20],mem[18][1<<18],sum[18][1<<18];

double get(int i,int m)
{
    double s=0;
    for(int j=0;j<n;j++)
    {
        if(i==j)continue;
        if((1<<j)&m)s+=a[j][i];
    }
    return s;
}
double dp(int s,int m)
{
    if(bob[m]==1)
    {
        if((1<<s)&m)return 1;
        return 0;
    }
    double&ret=mem[s][m];
    if(ret==ret)return ret;
    ret=0;
    int t=bob[m];
    for(int j=0;j<n;j++)
        if((1<<j)&m)
            ret+=dp(s,m&~(1<<j))*sum[j][m]*(1.0/(t*(t-1)/2));

    return ret;

}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>n;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
       cin>>a[i][j];
for(int i=0;i<(1<<n);i++)
{
    bob[i]=__builtin_popcount(i);
    for(int j=0;j<n;j++)
    {
        sum[j][i]=get(j,i);
    }
}
memset(mem,-1,sizeof mem);
cout<<fixed<<setprecision(6);
for(int i=0;i<n;i++)
{
    cout<<dp(i,(1<<n)-1)<<" ";
}
return 0;
}
