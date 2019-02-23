//https://codeforces.com/blog/entry/45912
#include <iostream>
#include<vector>
#include<algorithm>
//#include <cmath>
//#include <complex>
#include<queue>
#include<map>
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
int n,a[200020],b[200020],mx[6000020],mn[6000020],l,r;
ll ans;
int bulidmx(int s=1,int e=n,int p=1)
{
    if(s==e)return mx[p]=a[s];
    int mid=(s+e)/2;
    return mx[p]=max(bulidmx(s,mid,p*2),bulidmx(mid+1,e,p*2+1));
}

int getmx(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return mx[p];
    int mid=(s+e)/2;
    if(r<=mid) return getmx(s,mid,p*2);
    else if(l>mid) return getmx(mid+1,e,p*2+1);
    else return max(getmx(s,mid,p*2),getmx(mid+1,e,p*2+1));
}

int bulidmn(int s=1,int e=n,int p=1)
{
    if(s==e)return mn[p]=b[s];
    int mid=(s+e)/2;
    return mn[p]=min(bulidmn(s,mid,p*2),bulidmn(mid+1,e,p*2+1));
}

int getmn(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return mn[p];
    int mid=(s+e)/2;
    if(r<=mid) return getmn(s,mid,p*2);
    else if(l>mid) return getmn(mid+1,e,p*2+1);
    else return min(getmn(s,mid,p*2),getmn(mid+1,e,p*2+1));
}

int main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
input;
cin>>n;
forr(i,1,n)cin>>a[i];
forr(i,1,n)cin>>b[i];
bulidmn();
bulidmx();


forr(i,1,n)
{
    if(a[i]>b[i])continue;
    l=i;
    int lo=i,hi=n,mid;
    int ansl=-1,ansr=-1;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        r=mid;
        if(getmx()<getmn())lo=mid,ansl=mid;
        else hi=mid-1;
    }
    r=i;
    if(ansl==-1&&getmx()>=getmn())ansl=i-1;
    else if(ansl==-1)ansl=i;

    lo=i,hi=n;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        r=mid;
        if(getmx()>getmn())hi=mid,ansr=mid;
        else lo=mid+1;
    }
    r=n;
    if(ansr==-1&&getmx()<=getmn())ansr=hi+1;
    else if(ansr==-1)ansr=hi;
 //   cout<<i<<"     "<<ansl<<"   "<<ansr<<endl;
    ans+=max((ll)0,(ll)ansr-(ll)ansl-1);
}

cout<<ans;
return 0;
}
