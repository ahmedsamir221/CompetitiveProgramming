/*
   we will run BFS from (a1,b1) and save the all possible moves , then run another BFS from (a2,b2) and match
   it with the first BFS .
*/
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
//const int N=500009,M=1000000;
const double EPS= 1e-9,eps=-1e9;
//const int N =300005;
ll a1,a2,b1,b2;

map<ll,pair<ll,pii>> get(ll a, ll b)
{
    map<pii,ll>vis;
    map<ll,pair<ll,pii>>ans;
    queue<pair<pii,ll>>q;
    q.push({{a,b},0});
    while(q.size())
    {
        ll u=q.front().F.F,v=q.front().F.S,d=q.front().S;
        q.pop();
        if(vis.count({u,v}))continue;
        if(ans.count(u*v)==0)ans[u*v]={d,{u,v}};
        else ans[u*v]=min(ans[u*v],{d,{u,v}});
        vis[{u,v}]=1;
        if(u%2==0)q.push({{u/2,v},d+1});
        if(u%3==0)q.push({{u*2/3,v},d+1});
        if(v%2==0)q.push({{u,v/2},d+1});
        if(v%3==0)q.push({{u,v*2/3},d+1});
    }
    return ans;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;

    cin>>a1>>b1;
    cin>>a2>>b2;
    map<ll,pair<ll,pii>>x=get(a1,b1);
    map<ll,pair<ll,pii>>y=get(a2,b2);
    int ans=1e9;
    for(auto p:x)
    {
        if(y.count(p.F)==0)continue;
        if(x[p.F].F+y[p.F].F<ans)
        {
            ans=x[p.F].F+y[p.F].F;
            a1=x[p.F].S.F,b1=x[p.F].S.S;
            a2=y[p.F].S.F,b2=y[p.F].S.S;
        }
    }
    if(ans==1e9)
    {
        cout<<"-1";
        return 0;
    }
    cout<<ans<<endl;
    cout<<a1<<" "<<b1<<endl;
    cout<<a2<<" "<<b2<<endl;


return 0;
}
