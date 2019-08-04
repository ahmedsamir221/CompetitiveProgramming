/*
   the number of zeros increase in each i%5==0 , so the number of distinct values  from 1 to x = x/5 .
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

const int N=50000,M=1000000;
const double EPS= 1e-9;
ll l,r;
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
while(cin>>l>>r,l||r)
{
    ll ans=r/5-(l-1)/5;
    if(l%5)ans++;
    cout<<ans<<endl;
}
return 0;
}
