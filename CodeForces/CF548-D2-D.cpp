/*
  we need to know for each element the max size of group  which it is the min in it
  we can do that using binary search and segment tree then
  will begin with max value and check if it's group size >= current x and so on
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
int n,val[5000000],l,r,b[200020];
pair<int,int>a[200020];
int bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=a[s].F;
    int mid=(s+e)/2;
    return val[p]=min(bulid(s,mid,p*2),bulid(mid+1,e,p*2+1));
}

int mann(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return val[p];
    int mid=(s+e)/2;
    if(mid>=r)return mann(s,mid,p*2);
    else if(mid<l) return mann(mid+1,e,p*2+1);
    else return min(mann(s,mid,p*2),mann(mid+1,e,p*2+1));
}

int left(int v,int p)
{
    if(b[p-1]<v)return p;

    int lo=1,hi=p,mid;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        l=mid,r=hi;
        int g=mann();
        if(g>=v)hi=mid;
        else lo=mid+1;
    }
    return hi;
}


int right(int v,int p)
{
    if(b[p+1]<v)return p;

    int lo=p,hi=n,mid;
    while(lo<hi)
    {
        int mid=(lo+hi+1)/2;
        l=lo,r=mid;
        int g=mann();
        if(g>=v)lo=mid;
        else hi=mid-1;
    }
    return lo;
}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("let_it_flow.txt","r",stdin);
//freopen("samir.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
scanf("%d",&n);
forr(i,1,n)scanf("%d",&a[i].F),a[i].S=i,b[i]=a[i].F;

bulid();

sort(a+1,a+1+n);

int x=1;
for(int i=n;i>=1;i--)
{
    if(x>n)break;
    int dis=right(a[i].F,a[i].S)-left(a[i].F,a[i].S)+1;
    while(dis>=x)printf("%d ",a[i].F),x++;
}
return 0;
}
