/*
  it is easer to count number of ways that confuse with the information then subtract it from (2 power n)
  so we can do that with normal dp
*/
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=2800000,M=20000000;
ll n,m,mem[303][303][2],l[303],r[303],mod=1000000007;

ll dp(int i=0,int p=0,int ck=0)
{
    if(i==n)
    {
        if(ck)return 1;
        else return 0;
    }
    ll&ret=mem[i][p][ck];
    if(~ret)return ret;

    int g=0;
    forr(j,1,m)
        if(p<=l[j]&&i>=r[j])g=1;
    ll c1=dp(i+1,p,max(g,ck))%mod;
    ll c2=dp(i+1,i+1,ck)%mod;
    return ret=(c1+c2)%mod;
}


class WolfInZooDivTwo{
public:
    int count(int N, vector <string> L, vector <string> R)
    {
        n=N;
        string a,b;
        int x,y;
        for(auto p:L)a+=p;
        for(auto p:R)b+=p;
        stringstream A;A<<a;
        stringstream B;B<<b;
        while(A>>x)
        {
            B>>y;
            l[++m]=x;
            r[m]=y;
        }

        memset(mem,-1,sizeof mem);
        ll ans=1;
        forr(i,1,n)
        ans*=2,ans%=mod;
        ans=(ans%mod-dp()%mod+mod)%mod;
        return ans;
    }
};
