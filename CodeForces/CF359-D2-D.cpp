//https://codeforces.com/blog/entry/9425
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
int n,a[300030],val[20000000],val2[20000000],l,r;
vector<int>k;
int bulid(int s=1,int e=n,int p=1)
{
    if(s==e)return val[p]=a[s];
    int mid=(s+e)/2;
    return val[p]=__gcd(bulid(s,mid,p*2),bulid(mid+1,e,p*2+1));
}

int query(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return val[p];
    int mid=(s+e)/2;
    if(mid>=r) return query(s,mid,p*2);
    else if(l>mid) return query(mid+1,e,p*2+1);
    else return __gcd(query(s,mid,p*2),query(mid+1,e,p*2+1));
}




int bulid2(int s=1,int e=n,int p=1)
{
    if(s==e)return val2[p]=a[s];
    int mid=(s+e)/2;
    return val2[p]=min(bulid2(s,mid,p*2),bulid2(mid+1,e,p*2+1));
}

int query2(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return val2[p];
    int mid=(s+e)/2;
    if(mid>=r) return query2(s,mid,p*2);
    else if(l>mid) return query2(mid+1,e,p*2+1);
    else return min(query2(s,mid,p*2),query2(mid+1,e,p*2+1));
}
bool ok(int x)
{
    forr(i,1,n-x+1)
    {
        l=i,r=i+x-1;
        int a1=query();
        int b1=query2();
        if(a1==b1)return 1;
    }
    return 0;
}


void get(int x)
{
    forr(i,1,n-x+1)
    {
        l=i,r=i+x-1;
        int a1=query();
        int b1=query2();
        if(a1==b1)k.push_back(i);
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
cin>>n;
forr(i,1,n)cin>>a[i];

bulid();
bulid2();
int lo=1,hi=n,mid,ans=1;
while(lo<hi)
{
    mid=(lo+hi+1)/2;
    if(ok(mid))lo=mid,ans=mid;
    else hi=mid-1;
}

get(ans);

cout<<(int)k.size()<<" "<<ans-1<<endl;
for(auto p:k)cout<<p<<" ";

return 0;
}
