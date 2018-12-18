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
ll n,a[200020];
vector<ll>v,g;
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
   forr(i,1,n/2)
   {
     cin>>a[i];
     if(i==1)
     {
         g.push_back(0);
         v.push_back(a[i]);
     }
     else
     {
         ll u=g[(int)g.size()-1];
         ll t=v[(int)v.size()-1];
         if(a[i]<=a[i-1])
         {

             g.push_back(u);
             v.push_back(a[i]-u);
         }
         else
         {
             g.push_back(a[i]-t);
             v.push_back(t);
         }
     }
   }

   for(auto p:g)
        cout<<p<<" ";
   for(int i=n/2-1;i>=0;i--)
       cout<<v[i]<<" ";




return 0;
}
