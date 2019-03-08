/*
    we will split the memory clusters to parts equals to the power of two.
    then by brute force we will matching the arrays from the smallest  to the the memory clusters.
*/
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
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
int n,m,a[50],b[50],x;
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;


scanf("%d%d",&n,&m);
forr(i,1,n)
{
    scanf("%d",&x);
    forr(e,0,30)
           if((1<<e)&x)a[e]++;
}

forr(i,1,m)
{
scanf("%d",&x);
b[x]++;
}

int ans=0;
forr(i,0,30)
{
   forr(j,i,30)
   {
       if(b[i]==0)break;
       int t=a[j]*(1<<(j-i));
       int g=min(b[i],t);
       t-=g;
       a[j]=t/(1<<(j-i));
       t=t%(1<<(j-i));
       t*=(1<<i);
       ans+=g;
       b[i]-=g;
       forr(e,0,30)
           if((1<<e)&t)a[e]++;
   }
}
printf("%d",ans);
return 0;
}
