/*
    we will first perform all the K increasing operation  and by binary search will get the poorest person
    then will perform all the K decreasing operation  and by binary search will get the richest person
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
int n,k,a[500005],poor,rich;

bool ok(int x)
{
    ll need=0,have=0;
    forr(i,1,n)
    {
        if(a[i]<x)need+=(ll)(x-a[i]);
        else have+=(ll)(a[i]-x);
    }
    if(need<=k&&have>=need)return 1;
    else return 0;
}

bool go(int x)
{
    ll need=0,have=0;
    forr(i,1,n)
    {
        if(a[i]<x)need+=(ll)(x-a[i]);
        else if(a[i]>x) have+=(ll)(a[i]-x);
    }
    if(have<=k&&have<=need)return 1;
    else return 0;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;


scanf("%d%d",&n,&k);
forr(i,1,n)scanf("%d",&a[i]);

sort(a+1,a+1+n);

int l=0,r=1e9+1,mid;
while(l<r)
{
    mid=(l+r+1)/2;
    if(ok(mid))l=mid,poor=mid;
    else r=mid-1;
}

l=0,r=1e9+1,mid;
while(l<r)
{
    mid=(l+r)/2;
    if(go(mid))r=mid,rich=mid;
    else l=mid+1;
}

cout<<rich-poor;

return 0;
}
