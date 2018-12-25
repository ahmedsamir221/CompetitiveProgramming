/*
  we will sort the words in lexicographically order then give to each word a number and sort them
  after reverse them and give them the same numbers and will be line between the same number in the two column
  by segment tree we will get the number of crossed lines
  and will be the answer;
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
int n,l,r,tar,R[100010],val[70000000],b[100010];
string s[100010];
bool com2(int i,int j)
{
    string u=s[i];
    string v=s[j];
    reverse(u.begin(),u.end());
    reverse(v.begin(),v.end());
    if(u<v)return 1;
    return 0;
}
int query(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)return val[p];
    int mid=(s+e)/2;
    if(r<=mid)return query(s,mid,p*2);
    else if(l>mid) return query(mid+1,e,p*2+1);
    else return query(s,mid,p*2)+query(mid+1,e,p*2+1);
}
int up(int s=1,int e=n,int p=1)
{
    if(s==tar&&s==e)return val[p]=1;
    int mid=(s+e)/2;
    if(tar<=mid)return val[p]=up(s,mid,p*2)+val[p*2+1];
    else  return val[p]=val[p*2]+up(mid+1,e,p*2+1);
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
cin>>n;
forr(i,1,n)
    cin>>s[i];

sort(s+1,s+n+1);

forr(i,1,n)b[i]=i;

sort(b+1,b+n+1,com2);

forr(i,1,n)
    R[b[i]]=i;

ll ans=0;
forr(i,1,n)
{
    l=R[i]+1;
    r=n;
    if(l<=r)
    ans+=(ll)query();
    tar=R[i];
    up();
}

cout<<ans;
return 0;
}
