//https://codeforces.com/blog/entry/47457
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
int n,m,t,u,v,w,mem[5005][5005];
vector<pair<int,int>>a[5005];
vector<int>ans;

int dp(int i,int c)
{
    if(i==n)
    {
        if(c==0)return 0;
        else return 1e9+9;
    }
    if(c<0)return 1e9+9;
    int&ret=mem[i][c];
    if(~ret)return ret;
    ret=1e9+9;
    for(auto p:a[i])
        ret=min(ret,dp(p.F,c-1)+p.S);
    return ret;
}


void bulid(int i,int c)
{
    if(i==n)
    {
        ans.push_back(n);
        return;
    }

    for(auto p:a[i])
    {
        if(dp(i,c)==dp(p.F,c-1)+p.S)
        {
            ans.push_back(i);
            bulid(p.F,c-1);
            break;
        }
    }


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
cin>>n>>m>>t;
forr(i,1,m)
{
    cin>>u>>v>>w;
    a[u].push_back({v,w});
}

memset(mem,-1,sizeof mem);
for(int i=n;i>=2;i--)
{
    if(dp(1,i-1)<=t)
    {
        bulid(1,i-1);
        cout<<(int)ans.size()<<endl;
        for(auto p:ans)cout<<p<<" ";
        return 0;
    }
}
return 0;
}
