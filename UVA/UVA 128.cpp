//http://roprogrammer.blogspot.com/2010/01/uva-problem-128-software-crc.html
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
string s;
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
//input;
while(getline(cin,s),s!="#")
{
    int ans=0,m=34943;
    for(auto p:s)
    {
        ans<<=8;
        ans+=(int)p;
        ans%=m;
    }
    ans<<=8;
    ans%=m;
    ans<<=8;
    ans%=m;
    ans=m-ans;
    ans%=m;
    printf("%02X %02X\n", ans >> 8, ans & 0xFF);
}
return 0;
}
