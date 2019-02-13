//https://codeforces.com/blog/entry/7036
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
ll n,a[200020],ans[2][200020],vis[2][200020],s,id;

ll get(int i,int ck)
{
    if(i==1)return -2e18;
    if(i<1||i>n)return 0;
    if(vis[ck][i]==id)return -2e18;
    if(ans[ck][i])return ans[ck][i];
    vis[ck][i]=id;
    if(ck==0) return ans[ck][i]=a[i]+get(i+a[i],!ck);
    else return ans[ck][i]=a[i]+get(i-a[i],!ck);
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
forr(i,2,n)cin>>a[i];

forr(i,1,n-1)
{
   a[1]=i;
   id++;
   ll ans=i+get(i+1,1);
   if(ans<=0)cout<<"-1"<<endl;
   else cout<<ans<<endl;
}



return 0;
}
