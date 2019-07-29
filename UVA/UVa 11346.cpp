/*
   because the number of real points is infinite and we can not count them , so we will take our probability
   in the area .
   we need to calculate the area which all points in it make rectangle with area > S .
   we can to that with simple integration
        ans = (a-k) * b - s * (log(a)-log(k)) ;  where k is the first position after it the curve will change
   we can calculate it by binary search .

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
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=500005,M=1000000;
const double EPS= 1e-9;
int t;
double a,b,s;


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

cin>>t;
while(t--)
{
    cin>>a>>b>>s;
    double l=0,r=a,mid;
    forr(i,1,10000)
    {
        mid=(l+r)/2;
        if(mid*b<=s)l=mid;
        else r=mid;
    }
    double k=mid;
    double ans=(a-k)*b;
    ans-=s*(log(a)-log(k));
    if(s==0)cout<<fixed<<setprecision(6)<<100.000000<<"%"<<endl;
    else cout<<fixed<<setprecision(6)<<ans/(a*b)*100.0<<"%"<<endl;
}



return 0;
}
