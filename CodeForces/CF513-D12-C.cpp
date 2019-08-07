/*
   we need to brute force in all values of all companies and count the number of times that will be the second
   max , we can count that by make one company pays max or equal value and the others with low or equal value .
   we need to take care of repetition .
*/
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
ll n,l[N],r[N];
double ans,t=1;
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
cin>>n;
forr(i,1,n)cin>>l[i]>>r[i],t*=r[i]-l[i]+1;


forr(i,1,n)
{
    forr(j,l[i],r[i])
    {
        forr(e,1,n)
        {
            if(i==e)continue;
            ll k=1;
            forr(u,1,n)
            {
                if(i==u)continue;
                if(u==e)k*=max((ll)0,min(r[u]-j+(i<u?1:0),r[u]-l[u]+1));
                else k*=max((ll)0,min(j-l[u]+(i>u?1:0),r[u]-l[u]+1));
            }
            ans+=k*(ll)j*1.0/t;
        }
    }
}
cout<<fixed<<setprecision(9)<<ans;
return 0;
}
