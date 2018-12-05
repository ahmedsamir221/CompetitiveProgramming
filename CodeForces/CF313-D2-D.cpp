/*
  first we should save the min cost from each hole to another
  then try all possible set of segments that do not intersect using dp  that will cover at least k hole
  then minimize the cost
*/

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
int n,m,k,a[303][303],l,r,v;
ll mem[303][303];
ll dp(int i=1,int v=k)
{
    if(v<=0)return 0;
    if(i>n)return 1e14;
    ll&ret=mem[i][v];
    if(~ret)return ret;
    ll mn=1e18;
    ret=dp(i+1,v);
    for(int j=n;j>=i;j--)
    {
        if(a[i][j]!=0)
        mn=min(mn,(ll)a[i][j]);
        if(mn!=1e18)
        {
            ret=min(ret,dp(j+1,v-(j-i+1))+mn);
        }
    }
    return ret;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("tour.in","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>m>>k;
forr(i,1,m)
{
    cin>>l>>r>>v;
    if(a[l][r]==0)a[l][r]=v;
    else a[l][r]=min(a[l][r],v);
}

memset(mem,-1,sizeof mem);
ll ans=dp();
if(ans>=1e14)cout<<"-1";
else cout<<ans;
return 0;
}
