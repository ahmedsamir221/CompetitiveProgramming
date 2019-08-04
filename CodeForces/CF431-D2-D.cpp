//https://codeforces.com/blog/entry/12369
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
ll comb[70][70] ,m,k;

bool ok(ll x)
{
    ll g=0;
    int c=0;
    for(ll j=62;j>-1;j--)
    {
      if(x>=((ll)1<<j))
      {
          x-=((ll)1<<j);
          c++;
         // cout<<j<<endl;
          for(int i=0,e=c;i<=j;i++,e++)
              if(e==k)g+=comb[j][i];
      }
    }
   // cout<<g<<endl;
    if(g>=m)return 1;
    else return 0;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
comb[0][0] = 1;
for (int i = 1; i < 63; i++) {
comb[i][0] = 1;
for (int j = 1; j <= i; j++) {
    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) ;
    }
}

cin>>m>>k;
if(m==0)
{
    cout<<"1";
    return 0;
}

ll l=m,r=1e18,mid;
while(l<r)
{
    mid=(l+r)/2;
    if(ok(mid))r=mid;
    else l=mid+1;
}
cout<<l<<endl;
//cout<<ok(5);
return 0;
}
