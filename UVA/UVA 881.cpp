/*
   first we need to sort the all polygons in increasing order according to the area .
   for each point we will iterate in the sorted polygons and the answer will be the first polygon which
   the point is inside it .
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


#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);


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

const double PI  = acos(-1.0);
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
typedef complex<double> point;

//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const int N=100007,M=1000000;
const double EPS= 1e-9;

int n,m,id[N];
vector<point>pol[N];


int inPolygon(vector<point> &p, point q) {
	int i, j, cnt = 0;
	int n = p.size();
	for(i = 0, j = n-1; i < n; j = i++) {
		if(p[i].y > q.y != p[j].y > q.y &&
		q.x < (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y) + p[i].x)
		cnt++;
	}
	return cnt&1;
}
double polygonArea(vector<point> &p) {
    double area = 0;
    int n = p.size();
    for(int i = 0; i < n;i++)
		area += p[i].x * p[(i+1)%n].y - p[i].y * p[(i+1)%n].x;
    return fabs(area) /2;
}
 int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
//__builtin_popcount()
input;
int t,cas=0;
cin>>t;
while(t--)
{
    string s;
    getline(cin,s);
    cin>>n;
    cin.ignore();
    int idx;
    double X,Y;
    vector<pair<double,int>>sortarea;
    forr(i,1,n)
    {
        getline(cin,s);
        stringstream f;
        f<<s;
        f>>id[i];
        pol[i].clear();
        while(f>>X>>Y)
        {
            point a(X,Y);
            pol[i].push_back(a);
        }
        sortarea.push_back({polygonArea(pol[i]),i});
    }
    sort(sortarea.begin(),sortarea.end());
    cin>>m;
    vector<pair<int,int>>ans;
    if(cas++)cout<<endl;
    while(m--)
    {
        cin>>idx>>X>>Y;
        point a(X,Y);
        double polid=0;
        for(auto p:sortarea)
        {
            if(inPolygon(pol[p.S],a))
            {
                polid=id[p.S];
                break;
            }
        }
        ans.push_back({idx,polid});
    }
    sort(ans.begin(),ans.end());
    for(auto p:ans)cout<<p.F<<" "<<p.S<<endl;
}

return 0;
}
