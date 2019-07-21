//https://codeforces.com/blog/entry/10786
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
int n,m;
ll mem[1<<19][101];
string s;
ll dp(int msk,int mod)
{
    if(msk==0)
    {
        if(mod==0)return 1;
        return 0;
    }
    ll&ret=mem[msk][mod];
    if(~ret)return ret;
    ret=0;
    int ck[10];
    memset(ck,0,sizeof ck);
    for(int i=0;i<n;i++)
    {
        if(msk==(1<<n)-1&&s[i]=='0')continue;
        if(ck[s[i]-'0']==0&&(msk&((ll)1<<i)))ret+=dp(msk&(~(1<<i)),(mod*10+(s[i]-'0'))%m);
        if(msk&(1<<i))ck[s[i]-'0']=1;
    }
    return ret;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
input;
cin>>s>>m;
n=s.size();
memset(mem,-1,sizeof mem);
cout<<dp((1<<n)-1,0);

return 0;
}
