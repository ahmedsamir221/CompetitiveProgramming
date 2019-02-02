//https://codeforces.com/blog/entry/3864
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
ll n,ck[707],m=1e9+7,mem[703][702][3][3];
char a[707];
string s;
stack<pair<char,int>>k;

ll dp(int l=1,int r=n,int cl=0,int cr=0)
{
    if(l>r)return 1;
    ll&ret=mem[l][r][cl][cr];
    if(~ret)return ret;
    ret=0;
    int k=ck[l];
    if(k==r)
    {
        if(cl==0)
        {
            ret+=dp(l+1,r-1,1,0)%m;
            ret+=dp(l+1,r-1,2,0)%m;
        }
        if(cl==1)
            ret+=dp(l+1,r-1,2,0)%m;
        if(cl==2)
            ret+=dp(l+1,r-1,1,0)%m;
        if(cr==0)
        {
            ret+=dp(l+1,r-1,0,1)%m;
            ret+=dp(l+1,r-1,0,2)%m;
        }
        if(cr==1)
            ret+=dp(l+1,r-1,0,2)%m;
        if(cr==2)
            ret+=dp(l+1,r-1,0,1)%m;
    }
    else
    {
       if(cl==0)
       {
           ret+=(dp(l+1,k-1,1,0)%m*dp(k+1,r,0,cr)%m)%m;
           ret+=(dp(l+1,k-1,0,1)%m*dp(k+1,r,1,cr)%m)%m;
           ret+=(dp(l+1,k-1,2,0)%m*dp(k+1,r,0,cr)%m)%m;
           ret+=(dp(l+1,k-1,0,2)%m*dp(k+1,r,2,cr)%m)%m;
       }
       if(cl==1)
       {
           ret+=(dp(l+1,k-1,2,0)%m*dp(k+1,r,0,cr)%m)%m;
           ret+=(dp(l+1,k-1,0,2)%m*dp(k+1,r,2,cr)%m)%m;
           ret+=(dp(l+1,k-1,0,1)%m*dp(k+1,r,1,cr)%m)%m;
       }
       if(cl==2)
       {
           ret+=(dp(l+1,k-1,1,0)%m*dp(k+1,r,0,cr)%m)%m;
           ret+=(dp(l+1,k-1,0,2)%m*dp(k+1,r,2,cr)%m)%m;
           ret+=(dp(l+1,k-1,0,1)%m*dp(k+1,r,1,cr)%m)%m;
       }
    }

    return ret%m;
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
cin>>s;
n=(int)s.size();
forr(i,1,n)
a[i]=s[i-1];

forr(i,1,n)
{
    if(a[i]!=')')k.push({a[i],i});
    else
    {
        ck[k.top().S]=i;
        k.pop();
    }
}

memset(mem,-1,sizeof mem);

cout<<(dp()+m)%m;
return 0;
}
