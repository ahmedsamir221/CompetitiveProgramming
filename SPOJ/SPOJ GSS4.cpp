/*
  if we used the square root to any value more than 5 times it will reach to 1
  so we will use normal segment tree and stop the update of specific interval
  when all number in it equal 1
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
int  n,q,l,r,t,c;
ll a[200010],val[4000000];
ll bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=a[s];
    int mid=(s+e)/2;
    return val[p]=bulid(s,mid,p*2)+bulid(mid+1,e,p*2+1);
}


ll up(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=(ll)sqrt(val[p]);
    int mid=(s+e)/2;
    if(mid>=r)
    {
        if(val[p*2]>mid-s+1)
        return val[p]=up(s,mid,p*2)+val[p*2+1];
    }
    else if(l>mid)
    {
        if(val[p*2+1]>e-mid)
        return val[p]=val[p*2]+up(mid+1,e,p*2+1);
    }
    else
    {
        ll t1,t2;
        if(val[p*2]>mid-s+1)
        t1=up(s,mid,p*2);
        else
        t1=val[p*2];


        if(val[p*2+1]>e-mid)
        t2=up(mid+1,e,p*2+1);
        else
        t2=val[p*2+1];

        return val[p]=t1+t2;
    }
}


ll query(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return val[p];
    int mid=(s+e)/2;
    if(mid>=r)
        return query(s,mid,p*2);
    else if(l>mid)
        return query(mid+1,e,p*2+1);
    else
        return query(s,mid,p*2)+query(mid+1,e,p*2+1);

}
int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("CAMP.IN","r",stdin);
//freopen("CAMP.OUT","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//input;
while(scanf("%d", &n)!=EOF)
{
    forr(i,1,n)scanf("%lld",&a[i]);
    memset(val,0,sizeof val);
    bulid();
    scanf("%d",&q);
    printf("Case #%d:\n",++c);
    forr(i,1,q)
    {
        scanf("%d%d%d",&t,&l,&r);
        if(l>r)swap(l,r);
        if(t==0)
            up();
        else
        printf("%lld\n",query());
    }
    printf("\n");
}
return 0;
}
