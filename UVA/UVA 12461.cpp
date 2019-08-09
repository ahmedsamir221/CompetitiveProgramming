/*
   if we used dp with O(n*n) will realize that the answer = (2^(n-2))/(2^(n-1))= 1/2 .

    our state will be the index of the person , every time he can set in place of the first person and all
    coming will set in there right places or set in another place and make the decision to the person
    he set in his place .
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
ll n,mem[1005];
ll dp(int i)
{
    if(i==n)return 1;
    ll&ret=mem[i];
    if(~ret)return ret;
    ret=0; // number of times that n-th set is occupied
   //ret=1; // total number of ways
    forr(j,i+1,n)
        ret+=dp(j);
    return ret;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
while(cin>>n,n)
{
    cout<<"1/2"<<endl;
  // memset(mem,-1,sizeof mem);
  // cout<<dp(1)<<endl;
}

return 0;
}
