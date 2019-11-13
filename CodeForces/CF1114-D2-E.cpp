//https://codeforces.com/blog/entry/65136
#pragma GCC optimize("O3")
#include<queue>
#include <cmath>
#include <complex>
#include<map>
#include <string>
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>


/*
#define x real()
#define y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
*/

//#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
#define NOT(x) (1^x)

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100009,M=1000000;
int n,cnt=60;
int get()
{
    int l=0,r=1e9,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        cout<<"> "<<mid<<endl;
        cnt--;
        fflush(stdout);
        int t;
        cin>>t;
        if(t)l=mid+1;
        else r=mid;
    }
    return l;
}

int Rand()
{
	int res = 0;
	for (int i = 30;i >= 0;i--)
		res += ((rand() & 1) << i);
	return res;
}


 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
// srand (time(NULL));
// cout<<rand()<<endl;
//__builtin_popcount()
input;
       cin>>n;
       int mx=get();
       vector<int>v;
       srand (time(NULL));
       forr(i,1,min(n,cnt))
       {
           int j=Rand()%n;
           cout<<"? "<<j+1<<endl;
           fflush(stdout);
           int x;
           cin>>x;
           v.push_back(x);
       }
       int g=0;
       for(auto i:v)
       for(auto j:v)
       {
           if(i==j)continue;
           g=__gcd(g,abs(i-j));
       }
       cout<<"! "<<mx-(n-1)*g<<" "<<g<<endl;
       fflush(stdout);




return 0;
}
