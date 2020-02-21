//https://ideone.com/OcvCo2
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);

//const double PI  = acos(-1.0);
using namespace std;
//typedef pair<double,double>pdd;
typedef long long  ll;
//typedef pair<ll, ll>pii;
//typedef complex<double> point;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
const double EPS = 1e-9;
const int N = 5e5 + 9;
int x,y,z,k;


#define fr(i, n)    for(int i=0; i<(int)n; ++i)

pair<pair<double,double>,pair<double,double>> identity(){
    pair<pair<double,double>,pair<double,double>> id={{1.0,0.0},{0,1.0}};
    return id;
}

pair<pair<double,double>,pair<double,double>> mul(pair<pair<double,double>,pair<double,double>> a, pair<pair<double,double>,pair<double,double>> b){
    pair<pair<double,double>,pair<double,double>> c={{0.0,0.0},{0.0,0.0}};
    c.F.F=a.F.F*b.F.F+a.F.S*b.S.F;c.S.S=c.F.F;
    c.F.S=a.F.F*b.F.S+a.F.S*b.S.S;c.S.F=c.F.S;
    return c;
}

pair<pair<double,double>,pair<double,double>> matPow(pair<pair<double,double>,pair<double,double>> a, ll po){
    pair<pair<double,double>,pair<double,double>> ret = identity();
    pair<pair<double,double>,pair<double,double>> m = a;
    while(po){
        if(po & 1) ret = mul(ret, m);
        m = mul(m, m);
        po >>= 1;
    }
    return ret;
}
 int main()
{
//freopen("circles.in ","r",stdin);
//freopen("circles.out","w",stdout);
//__builtin_popcount()
//input
        int t,cas=0;
        scanf("%d",&t);
        while(t--)
        {
        scanf("%d%d%d%d",&x,&y,&z,&k);
        double ans=0;
        forr(i,1,x)
        {
            double r1=i*(x-i+1)*2-1;r1/=x*x;
            forr(j,1,y)
            {
                double r2=j*(y-j+1)*2-1;r2/=y*y;
                forr(v,1,z)
                {
                    double r3=v*(z-v+1)*2-1;r3/=z*z;
                    double p=r1*r2*r3;
                    pair<pair<double,double>,pair<double,double>> m={{1.0-p,p},{p,1.0-p}};
                    m=matPow(m,k);
                    ans+=m.F.S;
                }
            }
        }
        printf("Case %d: %.6f\n",++cas,ans);
        }



return 0;
}
