/*
we will use dp to solve that problem and our state will be any archer we will hit and its health and
the health of previous archer we can go to next archer to right if we killed the previous archer
and then update our state until reach to last archer */
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
int n,a,b,k[13],mem[12][19][19];
vector<int>ans;
int dp(int i,int cur,int before )
{
    if(i==n)return max(0,(cur+b-1)/b);
    int&ret=mem[i][cur][before];
    if(~ret)return ret;
    ret=1e8;
    forr(j,0,17)
    {
        if(before-j*b<=0)
        ret=min(ret,dp(i+1,max(k[i+1]-b*j,0),max(cur-a*j,0))+j);
    }
    return ret;
}

void bulid(int i,int cur,int before )
{
    if(i==n)
    {
        int u=max(0,(cur+b-1)/b);
        while(u--)ans.push_back(n-1);
        return ;
    }
    forr(j,0,17)
    {
        if(before-j*b<=0)
        {
            if(dp(i,cur,before)==dp(i+1,max(k[i+1]-b*j,0),max(cur-a*j,0))+j)
            {
                int u=j;
                while(u--)
                ans.push_back(i);
                bulid(i+1,max(k[i+1]-b*j,0),max(cur-a*j,0));
                break;
            }
        }
    }
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
cin>>n>>a>>b;
forr(i,1,n)
cin>>k[i],k[i]++;
memset(mem,-1,sizeof mem);
dp(2,k[2],k[1]);
bulid(2,k[2],k[1]);
cout<<(int)ans.size()<<endl;
for(auto p:ans)
    cout<<p<<" ";
return 0;
}
