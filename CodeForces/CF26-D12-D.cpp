//https://github.com/MedoN11/CompetitiveProgramming/blob/master/CodeForces/CF26-D12-D.cpp
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include<bits/stdc++.h>


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

const int N=16,M=1000000;
const double EPS= 1e-9;
ll n,m,k;

 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
   cin>>n>>m>>k;
   if(m>n+k)cout<<fixed<<setprecision(6)<<0.0<<endl;
   else{
   double ans=1.0;
   for(ll i=m,j=n+k+1;i>m-k-1;i--,j--)
   {
       ans*=(ll)i;
       ans/=(ll)j;
   }
   cout<<fixed<<setprecision(6)<<1.0-ans<<endl;
   }

return 0;
}
