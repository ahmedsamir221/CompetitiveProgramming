/*
   first we will get max  height according to the sum of red and green blocks
   then use dp with rolling to get the answer
   our state will be the remain number of red blocks  and the current level
   then each time will try to make the level red or green
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
int R,G,h;

int dp[200020][2];
int m=1e9+7;
/*
int dp(int r=R,int l=1)
{
    if(l>h)return 1;
    int&ret=mem[r][l];
    if(~ret)return ret;
    ret=0;
    if(r>=l)
        ret+=dp(r-l,l+1);
    int d=l*(l-1)/2-(R-r);
    if(G-d>=l)
        ret+=dp(r,l+1);
    return ret%m;
}*/

int dpk(int r=R,int l=1)
{
    int e=0;
    forr(r,0,R)dp[r][e]=1;

    for(int l=h;l>=1;l--)
    {
        e=!e;
        forr(r,0,R)
        {
            dp[r][e]=0;
            if(r>=l)
            dp[r][e]+=dp[r-l][!e];
            int d=l*(l-1)/2-(R-r);
            if(G-d>=l)
            dp[r][e]+=dp[r][!e];
            dp[r][e]%=m;
        }
    }
    return dp[R][e];
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
cin>>R>>G;
forr(i,1,1000)
    if(i*(i+1)/2<=R+G)h=i;

ll ans=dpk();
cout<<(ans+m)%m;
}
