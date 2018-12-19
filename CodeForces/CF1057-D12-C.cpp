/*
  first we will sort the boxes according to number of candies
  then with dp get the best set of boxes
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
int n,s,k,mem[52][52][2055];
pair<int,int>a[52];
char b[52];
int c[52];
int dp(int cur=1,int pr=s,int val=0)
{
    if(val>=k)return 0;
    if(cur>n)return 1e7;
    int&ret=mem[cur][pr][val];
    if(~ret)return ret;
    ret=1e7;
    if(val==0)
    {
       ret=min(ret,dp(cur+1,pr,val));
       ret=min(ret,dp(cur+1,a[cur].S,val+a[cur].F)+abs(pr-a[cur].S));
    }
    else
    {
       ret=min(ret,dp(cur+1,pr,val));
       if(a[cur].F>c[pr]&&b[a[cur].S]!=b[pr])
       ret=min(ret,dp(cur+1,a[cur].S,val+a[cur].F)+abs(pr-a[cur].S));
    }
    return ret;

}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);a
//freopen("trip.in","r",stdin);
//freopen("trip.out","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n>>s>>k;

forr(i,1,n)
{
cin>>a[i].F,a[i].S=i;
c[i]=a[i].F;
}

forr(i,1,n)cin>>b[i];

sort(a+1,a+1+n);

memset(mem,-1,sizeof mem);

int ans=dp();

if(ans>=1e7)cout<<"-1";
else cout<<ans;

return 0;
}
