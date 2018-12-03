/*
first we want to calculate number of tree with height >= h
so we want at least one leaf of the tree with height >= h
so easy we can calculate number of tree that has height < h because it has one condition that all leaf with height < h
then calculate all possible tree with any height
then the answer will be the difference
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
//typedef bitset<3> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//typedef complex<double> point;
ll n,h,mem[37][37][37],mem2[37][37][37];
ll dp(int l=1,int r=n,int k=0)
{
    if(l==r)
    {
        if(k<h-1)return 1;
        else return 0;
    }
    ll&ret=mem[l][r][k];
    if(~ret)return ret;
    ret=0;
    forr(i,l,r)
    {
        if(i==r)
        ret+=dp(l,i-1,k+1);
        else if(i==l)
        ret+=dp(i+1,r,k+1);
        else
        ret+=dp(l,i-1,k+1)*dp(i+1,r,k+1);;
    }
    return ret;
}

ll dp2(int l=1,int r=n,int k=0)
{
    if(l==r)
    return 1;
    ll&ret=mem2[l][r][k];
    if(~ret)return ret;
    ret=0;
    forr(i,l,r)
    {
        if(i==r)
        ret+=dp2(l,i-1,k+1);
        else if(i==l)
        ret+=dp2(i+1,r,k+1);
        else
        ret+=dp2(l,i-1,k+1)*dp2(i+1,r,k+1);;
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
cin>>n>>h;
memset(mem,-1,sizeof mem);
memset(mem2,-1,sizeof mem2);
cout<<dp2()-dp();
return 0;
}
