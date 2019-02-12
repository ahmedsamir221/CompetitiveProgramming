//https://codeforces.com/blog/entry/11730
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <iostream>
#include <cmath>
#include <complex>
#include<queue>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
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
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
int n,m,b,x[110],k[110],p[100],a[110],id[110],d;
ll mem[2][(1<<20)+5];
bool com(int i,int j)
{
    if(k[i]<k[j])return 1;
    return 0;
}
/*
ll dp(int i=1,int mask=0)
{
    if(mask==(1<<m)-1)return (ll)k[id[i-1]]*(ll)b;
    if(i>n)return 4e18;
    ll&ret=mem[i][mask];
    if(~ret)return ret;
    int j=id[i];
    ret=dp(i+1,mask);
    forr(e,1,p[j])
        mask|=(1<<a[j][e]);
    ret=min(ret,dp(i+1,mask)+(ll)x[j]);
    return ret;
}

*/
ll dp2()
{
    int r=0;
    forr(j,0,(1<<m)-1)
    mem[!r][j]=4e18;

    for(int i=n;i>=1;i--)
    {
        mem[!r][(1<<m)-1]=(ll)k[id[i]]*(ll)b;
        for(int t=(1<<m)-1;t>=0;t--)
        {
           mem[r][t]=4e18;
           int j=id[i];
           mem[r][t]=min( mem[r][t],mem[!r][t]);
           int mask=t|a[j];
           mem[r][t]=min(mem[r][t],mem[!r][mask]+(ll)x[j]);
        }
        r=!r;
    }
    return mem[!r][0];
}

int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m>>b;
forr(i,1,n)
{
    cin>>x[i]>>k[i]>>p[i];
    forr(j,1,p[i])
    {
    cin>>d,d--;
    a[i]|=(1<<d);
    }
    id[i]=i;
}
sort(id+1,id+1+n,com);
ll ans=dp2();

if(ans>=4e18)cout<<"-1";
else cout<<ans;
return 0;
}
